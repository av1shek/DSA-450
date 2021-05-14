class Solution
{
    public:
    Node *compute(Node *head)
    {
        if(head == NULL || head->next == NULL) return head;
         Node* nextNode = compute(head->next);
 
         if(nextNode->data > head->data) return nextNode;
         head->next = nextNode;
         return head;
    }
};