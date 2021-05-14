Node* reverseDLL(Node* head)
{
    Node* h = head;
    while(head)
    {
        swap(head->next, head->prev);
        h = head;
        head = head->prev;
    }
    return h;
}