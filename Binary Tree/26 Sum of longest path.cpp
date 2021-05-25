pair<int, int> solve(Node* root)
{
    if(root==NULL) return {0, 0};
    
    pair<int, int> l = solve(root->left);
    pair<int, int> r = solve(root->right);
    
    pair<int, int> ans;
    if(l.first > r.first) ans = l;
    else if(l.first < r.first) ans = r;
    else if(l.second > r.second) ans = l;
    else ans = r;
    

    ans.first++;
    ans.second += root->data;
    return ans;
}

int sumOfLongRootToLeafPath(Node* root)
{
	return solve(root).second;
}