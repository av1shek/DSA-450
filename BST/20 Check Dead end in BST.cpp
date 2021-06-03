bool solve(Node *root, int low, int high)
{
    if(root == NULL) return false;
    if(root->data+1==high && root->data-1==low) return true;
    bool a, b ;
    a = solve(root->left, low, root->data);
    b = solve(root->right, root->data, high);
    return a||b;
}
bool isDeadEnd(Node *root)
{
    return solve(root, 0, INT_MAX);
}