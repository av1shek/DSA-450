int getNthFromLast(Node *head, int n)
{
    Node* high = head, *low= head;

    while(n--){ 
        if(high==NULL) return -1;
        high = high->next;
    }
    while(high) {
        high = high->next;
        low = low->next;
    }
    return low->data;
}