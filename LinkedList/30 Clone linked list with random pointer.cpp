/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        
        Node *h = NULL, *head2, *curr = head;
        
        while(curr)
        {
            if(h==NULL){
                h = new Node(curr->val);
                head2 = h;
                mp[curr] = h;
            }
            else{
                h->next = new Node(curr->val);
                mp[curr] = h->next;
                h = h->next;
            }
            curr = curr->next;  
        }
        
        Node* curr1 = head;
        Node* curr2 = head2;
        
        while(curr1){
            curr2->random = mp[curr1->random];
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return head2;
    }
};