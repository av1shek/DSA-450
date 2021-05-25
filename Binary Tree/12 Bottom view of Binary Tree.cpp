void solve(Node *root, int x,int y,  map<int, pair<int, int> > &mp)
{
    if(root==NULL) return;
    if(mp.find(x)==mp.end())
        mp[x] = {root->data, y};
    else if( mp[x].second <= y)
         mp[x] = {root->data, y};

    solve(root->left, x-1, y+1, mp);
    solve(root->right, x+1, y+1, mp);
}
vector <int> bottomView(Node *root)
{
    map<int, pair<int, int> > mp;
    solve(root, 0,0, mp);
    vector<int> ans;
    for(auto it:mp) ans.push_back(it.second.first);
    return ans;
}
