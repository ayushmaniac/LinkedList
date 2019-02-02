#include<iostream>

using namespace std;

struct Node 
{ 
    int data; 
    struct Node* link; 
}; 
  
void push(struct Node** head_ref, int new_data) 
{ 
    /* allocate node */
    struct Node* new_node = new Node; 
  
    /* put in the data  */
    new_node->data  = new_data; 
  
    /* link the old list off the new node */
    new_node->link = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref)    = new_node; 
} 
  

int findLoop (Node *head)
{
Node *slow, *fast;
slow=head;
fast=head;
 while (fast!=NULL && fast->link!=NULL )
 {
 fast= fast->link->link;
 slow = slow->link;
  if (slow ==  fast)
  {
  return 1;   //loop found
  }
 }
return 0;      //No loop, reached end of list
}
int main() {
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 20); 
    push(&head, 4); 
    push(&head, 15); 
    push(&head, 10); 
  
    /* Create a loop for testing */
    head->link->link->link->link= head; 
  
    if (findLoop(head)) 
        cout << "Loop found"; 
    else
        cout << "No Loop"; 
  
    return 0; 
} 	
	
}

