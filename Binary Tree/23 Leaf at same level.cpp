bool check(Node *root)
    {
        if(root==NULL) return true;
        
        queue<Node*> q;
        q.push(root);
        
        bool flag = false;
        while(!q.empty())
        {
            int n = q.size();
            for(int i=0;i<n;i++)
            {
                Node* curr = q.front(); q.pop();
                
                if(curr->right==NULL && curr->left==NULL)
                {
                    flag =true;
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            if(flag) 
            return q.size()==0;
        }
        return false;
    }