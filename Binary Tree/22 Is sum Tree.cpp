int solve(Node* root, bool &flag)
    {
        if(root == NULL) return 0;
        if(root->left==NULL && root->right==NULL) return root->data;
        
        int x = solve(root->right, flag); 
        if(flag == false) return 0;
        int y = solve(root->left, flag);
        if(flag == false) return 0;
        
        if(x+y != root->data) 
        {
            flag = false;
            return 0;
        }
        return x+y + root->data;
    }
    bool isSumTree(Node* root)
    {
        bool flag = true;
        solve(root, flag);
        
        return flag;

    }