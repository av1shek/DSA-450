void dfs(Node* root, Node* newRoot, vector<int> &vis, vector<Node*> &hash)
{
 vis[root->val] = 1;
 hash[root->val] = newRoot;
 for(auto it: root->neighbors)
 {
     if(!vis[it->val]) 
     {
         Node *temp = new Node(it->val);
         dfs(it, temp, vis, hash);
     }
     (newRoot->neighbors).push_back(hash[it->val]);
 }
}

Node* cloneGraph(Node* root) {
    if(root ==NULL) return NULL;
    vector<int> vis(101, 0);
    vector<Node*> hash(101, NULL);

    Node* newRoot = new Node(root->val);
    dfs(root, newRoot, vis, hash);

    return newRoot;
}