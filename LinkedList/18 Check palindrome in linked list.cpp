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
    int getSize(ListNode* h)
    {
        int cnt;
        for(cnt=0; h; cnt++, h=h->next);
        return cnt;
    }
    
    ListNode* reverse(ListNode *h)
    {
        if(h==NULL || h->next==NULL) return h;
        
        ListNode *prev = NULL, *curr=h;
        
        while(curr)
        {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
    
    bool isSame(ListNode*l1, ListNode* l2)
    {
        if(l1==NULL &&  l2==NULL ) return true;
        if(l1==NULL && l2!=NULL) return false;
        if(l1!=NULL && l2==NULL) return false;
        if(l1->val != l2->val) return false;
        return isSame(l1->next, l2->next);
    }
    
    bool isPalindrome(ListNode* head) {
        int n = getSize(head);
        if(n==1) return true;
        if(n==2) return head->val == head->next->val;
        
        ListNode *l1, *l2;
        int mid = n/2;
        ListNode *midNode = head;
        int cnt = 0;
        
        while(cnt!=mid-1) {
            cnt++;
            midNode = midNode->next;
        }
        
        if(n%2)
        {
            l2 = midNode->next->next;
            ListNode *temp = midNode->next;
            midNode->next = NULL;
            midNode = temp;
            l1 = head;
        }
        else
        {
            l2 = midNode->next;
            midNode->next = NULL;
            l1 = head;
        }
        l1 = reverse(l1);
        
        return isSame(l1, l2);
    }
};

/* ---------------------- without modifying list ------------------- */
bool solve(ListNode* &low, ListNode* high)
    {
        if(low==NULL || high==NULL) return true;
        bool ans = solve(low, high->next);
        if(ans == false) return ans;
        ans = low->val == high->val;
        low = low->next;
        return ans;
    }
    bool isPalindrome(ListNode* &head) {
        return solve(head, head);
    }