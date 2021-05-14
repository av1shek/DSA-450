Node* reverse(Node* head)
    {
        Node *curr = head, *prev = NULL, *next = NULL;
        
        while(curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node *h1 = reverse(first), *h2 = reverse(second);
        
        Node *h3 = new Node(0);
        int carry  = 0, num = 0;
        Node *curr = h3;
        while ( h1!=NULL || h2 != NULL )
        {
            if(h1 == NULL)
            {
                num = h2->data + carry;
                h2 = h2->next;
            }
                
            else if (h2 == NULL)
            {
                num = h1->data + carry;
                h1 = h1->next;
            }
                
            else 
            {
                num = h1->data + h2->data + carry;
                h2 = h2->next;
                h1 = h1->next;
            }
                
            
            curr->data = num%10;
            carry = num/10;
            
            
            if( h1!=NULL || h2 != NULL )
            {
                curr->next = new Node(0);
                curr = curr->next;
            }
            
        }
        if(carry)
         curr->next = new Node(carry);
        return reverse(h3);
    }


/* --------------------- without reversing -------------------- */
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    int getSize(Node *h1)
    {
        int cnt = 0;
        while(h1) {
            h1 = h1->next;
            cnt++;
        }
        return cnt;
    }
    Node* addList(Node* h1, Node*h2, int &carry)
    {
        if(h1==NULL) return h1;
        Node *h3 = new Node(0);
        h3->next = addList(h1->next, h2->next, carry);
        int sum = h1->data + h2->data + carry;
        h3->data = sum%10;
        carry = sum/10;
        return h3;
    }
    void addCarry(Node *start, Node* last, int &carry)
    {
        if(start == last) return;
        addCarry(start->next, last, carry);
        start->data += carry;
        carry = start->data / 10;
        start->data %= 10;
        return;
    }
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        
        Node *h1 = first, *h2 = second;
        int l1 = getSize(h1), l2 = getSize(h2);
        int carry =0;
        if(l2> l1) swap(h1, h2), swap(l1, l2);
        
        if(l1==l2)
        {
            Node* h3 = addList(h1, h2, carry);
            if(carry)
            {
                Node* temp = new Node(carry);
                temp->next = h3;
                h3 = temp;
            }
            return h3;
        }
        int diff = l1 - l2 - 1;
        Node *curr = h1;
        for(curr=h1; diff ; curr=curr->next, diff--);

        Node* h3 = addList(curr->next, h2, carry);
        
        curr->next = h3;
        if(carry) addCarry(h1, curr->next, carry);
        if(carry) {
            Node *temp = new Node(carry);
            temp->next = h1;
            h1 = temp;
        }
        return h1;
    }
};