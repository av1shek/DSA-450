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

typedef ListNode* lptr;

struct comp{
    bool operator()(lptr a, lptr b){
        return a->val > b->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<lptr, vector<lptr>, comp> pq;
        int k = lists.size();
        
        for(int i=0;i<k;i++) if(lists[i]) pq.push(lists[i]);
        
        ListNode* head = new ListNode(0);
        ListNode* headit = head;
        while(!pq.empty()){
            ListNode* curr = pq.top(); pq.pop();
            if(curr->next)
                pq.push(curr->next);
            
            headit->next = curr;
            headit = headit->next;
        }
        return head->next;
    }
};