Node *removeDuplicates(Node *head)
{
if(head == NULL) return head;
    
    Node* curr = head; 
    Node* nxt = head->next;
    
    while(nxt!=NULL)
    {
        if(nxt->data == curr->data)
           nxt = nxt->next;
        else
        {
            curr->next = nxt;
            curr = nxt;
            nxt = nxt->next;
        }
    }
    curr->next = nxt;
    return head;
}