// https://leetcode.com/problems/balance-a-binary-search-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root, vector<int> &arr)
    {
        if(root==NULL) return;
        if(root->left) inorder(root->left, arr);
        arr.push_back(root->val);
        if(root->right) inorder(root->right, arr);
    }
    
    TreeNode* buildTree(vector<int> &arr, int low, int high)
    {
        if(low > high) return NULL;
        int mid = (low + high)/2;
        TreeNode* root = new TreeNode(arr[mid]);
        root->left = buildTree(arr, low, mid-1);
        root->right = buildTree(arr, mid+1, high);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        if(root==NULL) return root;
        vector<int> arr;
        inorder(root, arr);
        TreeNode *newRoot = buildTree(arr, 0, arr.size()-1);
        return newRoot;
    }
};