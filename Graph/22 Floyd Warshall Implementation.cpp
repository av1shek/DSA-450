class Solution {
  public:
	void shortest_distance(vector<vector<int>>&dist){
	    int n = dist.size();
	    
	    
	    for(int k=0;k<n;k++)
	        for(int u =0;u<n;u++)
	            for(int v = 0;v<n;v++)
	                if(  
	                    (dist[u][k] != -1) && (dist[k][v]!=-1) &&  
	                    ( (dist[u][v] > dist[u][k] + dist[k][v]) || (dist[u][v]==-1) ) 
	                )
	                    dist[u][v] = dist[u][k] + dist[k][v];
	                    
	   
	}
};