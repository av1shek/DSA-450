void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if(root==NULL) return;
    if(root->key < key)
    {
        if(pre == NULL) pre = root;
        else if( root->key > pre->key) pre = root;
    }
    if(root->key > key)
    {
        if(suc == NULL) suc = root;
        else if( root->key < suc->key ) suc = root;
    }

    findPreSuc(root->left, pre, suc, key);
    findPreSuc(root->right, pre, suc, key);
    
    return;
}