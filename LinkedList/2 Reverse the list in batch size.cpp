class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL) return head;
        
        node *curr = head;
        node *next = NULL;
        node *prev = NULL;
        
        int cnt = 0;
        
        while(curr!=NULL && cnt<k)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }
        head->next = reverse(next, k);
        
        return prev;
    }
};