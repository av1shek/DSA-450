// recursive
void helper(TreeNode* node, map<int, vector<int> > &mp, int dig)
 {
     if(node == NULL) return;
     helper(node->left, mp, dig+1);
     mp[dig].push_back(node->val);
     helper(node->right, mp, dig);
 }
vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int> > mp;
    helper(A, mp, 1);
    vector<int> ans;
    for(auto diagonals : mp)
    {
        for(auto it:diagonals.second)
        ans.push_back(it);
    }
    return ans;
}


// iterative

vector<int> Solution::solve(TreeNode* root) {
    if (!root) return {};

    vector<int> ans;

    deque<TreeNode*> dq;
    dq.push_front(root);

    while (!dq.empty()) {
        TreeNode* node = dq.front();
        dq.pop_front();

        ans.push_back(node->val);

        if (node->left)
            dq.push_back(node->left);

        if (node->right) 
            dq.push_front(node->right);

    }

    return ans;
}
