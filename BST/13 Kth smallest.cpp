void solve(Node *root, int &k, int &ans)
{
    if(root==NULL) return;
    
    solve(root->left, k, ans);
    k--;
    if(k==0)
    {
        k--;
        ans = root->data;
        return;
    }
    solve(root->right, k, ans);
}

int KthSmallestElement(Node *root, int K)
{
    int ans = -1;
    solve(root, K, ans);
    return ans;
}