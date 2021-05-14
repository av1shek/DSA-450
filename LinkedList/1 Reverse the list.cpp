class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
     {
        if(head == NULL) return head;
        Node *h1 = head, *h2 = head->next;
        h1->next = NULL;
        if(h2 == NULL) return h1;
        if(h2->next == NULL) { h2->next = h1; return h2; }
        
        while(h2->next != NULL)
        {
            Node *temp = h2->next;
            h2->next = h1;
            h1 = h2;
            h2 = temp;
        }
        h2->next = h1;
        return h2;
    }
    
};
    
/* ----------- recursive --------------*/
class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
     {
        if(head == NULL) return head;
        if(head->next == NULL) return head;
        
        Node *temp = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return temp; 
        
    }
    
};