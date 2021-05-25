class Solution{
    public:
    int height(struct Node* node){
        if(node==NULL) return 0;
        if(node->right==NULL && node->left==NULL) return 1;
        return 1 + max(height(node->right), height(node->left));
    }
};