class Solution
{
    public:
    void solve(Node *head, int &carry)
    {
        if(head == NULL) return;
        
        if(head->next==NULL)
        {
            head->data += 1;
            carry= head->data / 10;
            head->data = head->data % 10;
            return;
        }
        solve(head->next, carry);
        head->data += carry;
        carry= head->data / 10;
        head->data = head->data % 10;
        
        return;
    }
    
    Node* addOne(Node *head) 
    {
        int carry = 0;
        solve(head, carry);
        if(carry) {
            Node *temp = new Node(carry);
            temp->next = head;
            head = temp;
        }
        return head;
    }
};