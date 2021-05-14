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
    int getSize(ListNode* h){
        int cnt = 0;
        while(h){
            h = h->next;
            cnt++;
        }
        return cnt;
    }
    ListNode* getTail(ListNode* h){
        if(h==NULL) return h;
        while(h->next) h = h->next;
        return h;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL) return head;
        int n = getSize(head); k = k%n;
        if(n==1 || k==0) return head;
        int pos = n-k;
        
        ListNode *curr = head;
        int cnt = 1;
        while(cnt < pos){
            cnt++;
            curr = curr->next;
        }
        
        ListNode* newHead = curr->next;
        curr->next = NULL;
        ListNode* tail = getTail(newHead);
        
        tail->next = head;
        return newHead;
    }
};