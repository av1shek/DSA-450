// recursive
void solve(TreeNode *root, vector<int> &ans)
    {
        if(root==NULL) return;
        ans.push_back(root->val);
        solve(root->left, ans);
        solve(root->right, ans);
        return;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root, ans);
        return ans;
    }


// iterative

   vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root==NULL) return ans;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty())
        {
            TreeNode *curr = s.top(); s.pop();
            ans.push_back(curr->val);
            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
        return ans;
    }