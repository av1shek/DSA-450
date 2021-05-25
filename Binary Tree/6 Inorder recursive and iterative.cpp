// recursive

class Solution {
public:
    void solve(TreeNode* root, vector<int> &ans)
    {
        if(root==NULL) return;
        solve(root->left, ans); 
        ans.push_back(root->val);
        solve(root->right, ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }
};

// iterative

vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        while(curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        
        while(!s.empty())
        {
            curr = s.top(); s.pop();
            ans.push_back(curr->val);
            
            curr = curr->right;
            while(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
        }
        return ans;
    }



