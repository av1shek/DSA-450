class Solution {
public:
    int getMin(TreeNode *root)
    {
        while(root->left)
            root = root->left;
        return root->val;
    }
    
    TreeNode* deleteNode(TreeNode* &root, int key) {
        if(root == NULL) return root;
        if(root->val== key)
        {
            if( !root->right && !root->left) root = NULL;
            else if(root->right && !root->left) root = root->right;
            else if(!root->right && root->left) root = root->left;
            else{
                int temp = getMin(root->right);
                deleteNode(root->right, temp);
                root->val = temp;
            }
        }
        else if(root->val > key) deleteNode(root->left, key);
        else  deleteNode(root->right, key);
        return root;
    }
};