int getHeight(btptr T, bool &flag)
    {
        if(T==NULL)
        return 0;
        
        if(flag==false)
            return 0;
        
        int l = getHeight(T->left, flag);
        int r = getHeight(T->right, flag);
        
        if(abs(l-r)>1)
            flag = false;
        return (1 + max(l, r));
    }
    bool isBalanced(btptr T) {
        bool flag = true;
        getHeight(T, flag);
        return flag;
    }