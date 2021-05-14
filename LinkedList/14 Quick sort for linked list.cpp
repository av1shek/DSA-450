// https://leetcode.com/problems/sort-list/discuss/228473/quicksort-for-listclean-and-easybut-not-fast

ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0);
        ListNode* afterHead = new ListNode(0);
        ListNode* before = beforeHead;
        ListNode* after = afterHead;
        
        while(head!=nullptr)
        {
            if(head->val < x){
                before->next = head;
                before = before->next;
            }
            else{
                after->next = head;
                after = after->next;
            }
            head = head->next;
        }
        
        after->next = nullptr;
        before->next = afterHead->next;
        return beforeHead->next;
    }
    
    ListNode* sortList(ListNode* &head) {
        if(head==NULL || head->next==NULL) return head;

        ListNode* pivot = head;
        head = head->next;        
        head = partition(head, pivot->val);
        
        if(pivot->val < head->val ){
            sortList(head);
            pivot->next = head;
            head = pivot;
            return head;
        }

        ListNode* curr = head;
        
        while(curr->next != NULL && (curr->next->val <= pivot->val)) curr = curr->next;
        
        ListNode* l2 = curr->next; 
        curr->next = NULL;
        ListNode* l1 = head;
        
        sortList(l1);
        sortList(l2);
        
        ListNode* temp = l1;
        while(temp->next != NULL ) temp = temp->next;
        temp->next = pivot;
        pivot->next = l2;
        head = l1;
        
        return head;
    }