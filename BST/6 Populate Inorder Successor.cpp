void solve(node *curr, node* &prev)
{
    if(curr==NULL) return;
    solve(curr->left, prev);
    
    if(prev != NULL)
        prev->next = curr;
    prev = curr;
    
    solve(curr->right, prev);
}
void populateNext(struct node* p)
{ 
    node* prev = NULL;
    solve(p, prev);
}