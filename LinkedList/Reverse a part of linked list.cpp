// https://leetcode.com/problems/reverse-linked-list-ii/
/*

LeftNode => starting point from where we have to reverse
RightNode => end point till where we have to reverse

LeftEnd=> node just before LeftNode
RightEnd => node just after RightNode

i) First disconnect the part of list which is to be reversed
ii) Reverse that disconnected part.
iii) Join again that reveresed part using rightEnd and leftEnd node.

revereseList => it reverse the list and returns the last pointer of list
and stores the head of list in a variable which is passed by refrence

*/
class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode* &h)
    {
        if(head == NULL || head->next==NULL)
        {
            h = head;
            return h;
        }
        ListNode *temp = reverseList(head->next, h);
        head->next = NULL;
        temp->next = head;
        return head;
    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *prev = new ListNode(0);
        prev->next = head;
        head = prev;
        
        ListNode *leftEnd, *rightEnd, *leftNode, *rightNode;
        ListNode *curr = head;
        
        for(int i=0; i<=right+1 ;i++)
        {
            if(i == left-1)
                leftEnd = curr;
            else if(i == left)
                leftNode = curr;
            if(i == right)
                rightNode = curr;
            else if(i == right+1 )
                rightEnd = curr;
            if(curr)
                curr = curr->next;
        }
        
        
        rightNode->next = NULL;
        ListNode *reverseHead = NULL;
        rightNode = reverseList(leftNode, reverseHead);

        leftEnd->next = reverseHead;
        rightNode->next = rightEnd;
        
        return head->next;
    }
};