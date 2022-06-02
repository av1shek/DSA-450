/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isValid(ListNode* head, int k)
    {;
        int cnt = 0;
        while(head)
        {
            cnt++;
            head = head->next;
            if(cnt==k) return true; 
        }
    
        return false;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(!isValid(head, k)) return head;
        int cnt = 0;
        ListNode* newHead = NULL;
        ListNode* kthnode = head; // head will be kth node after reversing
        while(head && cnt<k)
        {
            ListNode* curr = head;
            head = head->next;
            curr->next = newHead;
            newHead = curr;
            cnt++;
        }
        
        if(head)
            kthnode->next = reverseKGroup(head, k);
        return newHead;
    }
};
