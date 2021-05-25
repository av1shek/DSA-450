string solve(Node *root, unordered_map<string, int> &mp)
{
    if(root==NULL) return "$";
    
    if(!root->left && !root->right)
    {
        string s = to_string(root->data);
        return s;
    }
    
    string s = to_string(root->data);
    s += solve(root->left, mp);
    s += solve(root->right, mp);
    mp[s]++;
    return s;
}
bool dupSub(Node *root)
{
    unordered_map<string, int> mp;
     solve(root, mp);
     for(auto it: mp)
     {
         if(it.second >= 2){ return true; }
     }
     return false;
}