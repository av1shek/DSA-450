class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int cnt[3] = {0};
        
        Node* curr = head;
        
        while(curr){
            cnt[curr->data]++;
            curr = curr->next;
        }
        cnt[1] += cnt[0];
        cnt[2] += cnt[1];
        curr=head;
        for(int i=0;i<cnt[2];i++)
        {
            if(i<cnt[0]) curr->data = 0;
            else if(i<cnt[1]) curr->data = 1;
            else curr->data = 2;
            curr = curr->next;
        }
        return head;
    }
};