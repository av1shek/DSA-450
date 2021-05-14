Node* divide(int N, Node *head){
        Node* even = new Node(0);
        Node* odd = new Node(0);
        
        Node* e = even, *o = odd;
        
        while(head)
        {
            if(head->data%2){
                o->next = head;
                o = o->next;
            }
            else{
                e->next = head;
                e = e->next;
            }
            head = head->next;
        }
        o->next = NULL;
        e->next = odd->next;
        
        return even->next;
    }