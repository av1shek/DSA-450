void toSumTree(Node *node)
    {
        if(node==NULL) return;
        if(node->left==NULL && node->right==NULL)
        {
            node->data = 0;
            return;
        }
        int sum = 0;
        
        if(node->left) sum += node->left->data;
        if(node->right) sum += node->right->data;
        
        toSumTree(node->left);
        toSumTree(node->right);
        
        if(node->left) sum += node->left->data;
        if(node->right) sum += node->right->data;
        
        node->data = sum;
    }