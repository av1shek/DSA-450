// https://www.onlinegdb.com/s/as/22991
// Taking a Break through coding
// can lead to breakthroughs
#include <bits/stdc++.h>
using namespace std;

int G[100][100];
int N = 100;    /// No of vertices

void addEdge(int u, int v)
{
    G[u][v] = 1;

}

void initialize()
{
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            G[i][j] = 0;
}

/// in undirected graph both indegree and outdegree
int* outDegree()
{
    int *ans = new int[N]{0};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(G[i][j])
                ans[i]++;
    return ans;
}

int* inDegree()
{
    int *ans = new int[N]{0};
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            if(G[i][j])
                ans[j]++;
    return ans;
}

float dfs(int currVertex, float time[])
{
    if(currVertex == N-1)
        return 0.0;     /// dest vertex
    
    float maxx = -9999.0;
    for(int i=0;i<N;i++)
        if( G[currVertex][i]==1 )
            maxx = max( maxx, dfs(i, time) );
    return (maxx + time[currVertex]);
}

float EarliestCompTime(float time[])
{
    int *inD = inDegree();
    int *outD = outDegree();

    for(int i=1;i<N-1;i++)
    {
        if(inD[i]==0)
            addEdge(0, i);
        else if(outD[i]==0)
            addEdge(i, N-1);
    }

     return dfs(0, time);
}

int main()
{
    int v, e;
    v = 7;
    N = v+2;
    initialize();
    float time[N];

    time[0] = 0.0;    /// src
    time[N-1] = 0.0;  /// sink

    time[1] = 3.1;
    time[2] = 2.0;
    time[3] = 4.6;
    time[4] = 1.8;
    time[5] = 0.3;
    time[6] = 4.0;
    time[7] = 3.7;

    addEdge(1, 3);
    addEdge(1, 5);
    addEdge(2, 5);
    addEdge(3, 4);
    addEdge(3, 6);
    addEdge(5, 6);
    addEdge(4, 7);
    addEdge(6, 7);

    cout<<EarliestCompTime(time);

    return 0;
}



