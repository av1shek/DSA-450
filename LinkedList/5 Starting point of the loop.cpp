class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head, * prev = NULL;
        
        while(fast!=NULL && fast->next !=NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow) // means loop is there
            {
                slow = head;
                
                while(slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};