void inorder(Node* root, vector<int> &nodeArr)
{
    if(root == NULL) return;
    inorder(root->left, nodeArr);
    nodeArr.push_back(root->data);
    inorder(root->right, nodeArr);
}
void setInorder(Node *root, vector<int> &nodeArr, int &i)
{
    if(root==NULL) return;
    setInorder(root->left, nodeArr, i);
    root->data = nodeArr[i++];
    setInorder(root->right, nodeArr, i);
}
Node *binaryTreeToBST (Node *root)
{
    vector<int> nodeArr;
    inorder(root, nodeArr);
    
    sort(nodeArr.begin(), nodeArr.end());
    int i = 0;
    setInorder(root, nodeArr, i);
    return root;
}
