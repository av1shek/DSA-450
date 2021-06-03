bool solve(Node *root, int mini, int maxi)
{
    if(root==NULL) return true;
    if( root->data>mini && root->data < maxi)
        return ( solve(root->left, mini, root->data) && solve(root->right, root->data, maxi) );
    return false;
}
bool isBST(Node* root) 
{  return solve(root, INT_MIN, INT_MAX);  }