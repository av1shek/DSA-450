pair<pair<bool, int>, pair<int, int> > solve(Node *root, int &ans)
{
    if(root==NULL) return { {true, 0}, {INT_MAX, INT_MIN } };
    
    pair<pair<bool, int>, pair<int, int> > a, b;
    
    a = solve(root->left, ans);
    b = solve(root->right, ans);
    
    if( !a.first.first  || !b.first.first) return { {false, 0}, {0, 0} };
    
    int val = root->data;
    int mini = a.second.second;
    int maxi = b.second.first;
    int size = a.first.second + b.first.second + 1;
    
    if( val>mini && val<maxi )
    {
        ans = max(ans, size);
        return { {true, size}, {min(val, a.second.first), max(val, b.second.second)} };
    }
    
    return { {false, 0}, {0, 0} };
}
int largestBst(Node *root)
{
	if(!root) return 0;
	int ans = 1;
	solve(root, ans);
	return ans;
}