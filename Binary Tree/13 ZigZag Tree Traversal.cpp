vector <int> zigZagTraversal(Node* root)
{
	vector<int> ans;
	if(root == NULL) return ans;
	
	deque<Node*> q;
	q.push_back(root);
	int cnt = 1;
	while(!q.empty())
	{
	    int N = q.size();
	    
	    for(int i=0;i<N;i++)
	    {
	        Node* curr;
	        if(cnt%2) { curr = q.front(); q.pop_front(); }
	        else { curr = q.back(); q.pop_back(); }
	        
	        ans.push_back(curr->data);
	        
	        if(cnt%2) 
	        {
	            if(curr->left ) q.push_back(curr->left);
	            if(curr->right) q.push_back(curr->right);
	            
	        }
	        else
	        {
	            if(curr->right) q.push_front(curr->right);
	            if(curr->left ) q.push_front(curr->left);
	            
	        }
	        
	    }
	    cnt++;
	}
	return ans;
}