class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodes
        Node *fast = head, *slow = head, *prev = NULL;
        
        while(fast!=NULL && fast->next !=NULL)
        {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
            
            if(fast == slow) // means loop is there
            {
                slow = head;
                
                while(slow != fast)
                {
                    prev = fast;
                    slow = slow->next;
                    fast = fast->next;
                }
                prev->next = NULL;
                return;
            }
        }
        return;
    }
};