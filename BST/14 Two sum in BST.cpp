int countPairs(Node* root1, Node* root2, int x)
{
    stack<Node*> s1, s2;
    
    while(root1) {
        s1.push(root1);
        root1 = root1->left;
    }
    
    while(root2){
        s2.push(root2);
        root2 = root2->right;
    }
    int cnt = 0;
    while(!s1.empty() && !s2.empty()){
        int low = s1.top()->data;
        int high = s2.top()->data;
        
        if(low+high==x)
        {
            cnt++;
            Node* a = s1.top(); s1.pop(); a = a->right;
            Node* b = s2.top(); s2.pop(); b = b->left;
            
            while(a){
                s1.push(a);
                a = a->left;
            }
            
            while(b){
                s2.push(b);
                b = b->right;
            }
        }
        else if(low + high < x){
            Node* a = s1.top(); s1.pop(); a = a->right;
            while(a){
                s1.push(a);
                a = a->left;
            }
        }
        else if(low + high > x){
            Node* b = s2.top(); s2.pop(); b = b->left;
            while(b){
                s2.push(b);
                b = b->right;
            }
        }
    }
    return cnt;
}