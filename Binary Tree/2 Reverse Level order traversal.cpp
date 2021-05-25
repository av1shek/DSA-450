vector<int> reverseLevelOrder(Node *root)
{
    vector<int> ans;
    if(root==NULL) return ans;
    stack<int> s;
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty())
    {
        Node* curr = q.front(); q.pop();
        s.push(curr->data);
        if(curr->right) q.push(curr->right);
        if(curr->left) q.push(curr->left);
    }
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}