Node* findLCA(Node* root, int a, int b)
{
    if(root==NULL) return root;
    
    if(root->data == a || root->data == b) return root;
    
    Node *lc = findLCA(root->left, a, b);
    Node *rc = findLCA(root->right, a, b);
    
    if(lc && rc ) return root;
    return (lc ? lc : rc);
}
int distance(Node *root, int val)
{
    if(root==NULL ) return -1;
    if(root->data == val) return 0;
    
    int a = distance(root->left, val);
    int b = distance(root->right, val);
    
    if(a==-1 && b==-1) return -1;
    
    if(a!=-1) return 1+a;
    return 1+b;
}
int findDist(Node* root, int a, int b) {
    Node *lca = findLCA(root, a, b);
    return ( distance(lca, a) + distance(lca, b));
}