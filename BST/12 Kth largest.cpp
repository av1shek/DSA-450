void solve(Node *root, int &k, int &ans)
{
    if(root==NULL) return;
    
    solve(root->right, k, ans);
    k--;
    if(k==0)
    {
        k--;
        ans = root->data;
        return;
    }
    solve(root->left, k, ans);
}
int kthLargest(Node *root, int &K)
{
    int ans = 0;
    solve(root, K, ans);
    return ans;
}