bool isIsomorphic(Node *root1,Node *root2)
    {
        if(!root1 && !root2) return true;
        if(root1 && !root2) return false;
        if(!root1 && root2) return false;
        
        if(root1->data != root2->data) return false;
        
        bool a = false, b = false;
        a = isIsomorphic(root1->left, root2->left);
        b = isIsomorphic(root1->right, root2->right);
        
        if(a&&b) return true;
        
        a = isIsomorphic(root1->left, root2->right);
        b = isIsomorphic(root1->right, root2->left);
        
        return a&&b;
    }