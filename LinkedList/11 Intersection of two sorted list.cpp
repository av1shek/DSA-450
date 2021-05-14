Node* findIntersection(Node* head1, Node* head2)
{
    Node *h1 = head1, *h2 = head2, *h3 = NULL;
    Node *curr = NULL;
    while(h1 && h2)
    {
        if( h1->data > h2-> data) h2 = h2->next;
        else if(h2->data > h1->data) h1 = h1->next;
        else
        {
            if(curr == NULL)
            {
                h3 = new Node(h1->data);
                curr = h3;
            }
            else
            {
                h3->next = new Node(h1->data);
                h3 = h3->next;
            }
            h1 = h1->next;
            h2 = h2->next;
        }
    }
    return curr;
}