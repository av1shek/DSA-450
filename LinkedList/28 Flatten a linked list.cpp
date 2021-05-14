Node* merge(Node* h1, Node* h2)
{
    if(h1==NULL) return h2;
    if(h2==NULL) return h1;
    
    if(h1->data < h2->data) 
    {
        h1->bottom = merge(h1->bottom, h2);
        return h1;
    }
    else
    {
        h2->bottom = merge(h1, h2->bottom);
        return h2;
    }
    return h1;
}
Node *flatten(Node *root)
{
   if(root == NULL) return root;
   
   Node* nxt = root->next;
   
   while(nxt){
       Node* temp = nxt->next;
       root = merge(root, nxt);
       nxt = temp;
   }
   return root;
}