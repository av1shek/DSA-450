void solve(Node *root, int l, int h, int &cnt)
{
    if(root==NULL) return;
    if( (root->data >= l) && (root->data<=h) )
    {
        cnt++;
        solve(root->left, l, h, cnt);
        solve(root->right, l, h, cnt);
    }
    else if( root->data < l) solve(root->right, l, h, cnt);
    else solve(root->left, l, h, cnt);
}
int getCount(Node *root, int l, int h)
{
    int cnt = 0;
    solve(root, l, h, cnt);
    return cnt;
}