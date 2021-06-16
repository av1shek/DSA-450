// https://practice.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
// same question no 24
bool isValid(bool graph[101][101], int color[], int pos, int v){
    for(int i=0;i<v;i++){
        if(graph[pos][i] == true && color[i] == color[pos])
            return false;
    }
    return true;
}

bool check(bool graph[101][101], int color[], int pos, int v, int m)
{
    if(pos == v) return true;
    
    for(int c=0;c<m;c++)
    {
        color[pos] = c;
        if(isValid(graph, color, pos, v))
        {
            if(check(graph, color, pos+1, v, m))
                return true;
        }
        color[pos] = -1;
        
    }
    return false;
}
bool graphColoring(bool graph[101][101], int m, int v) {
    int color[v];
    memset(color, -1, sizeof(color));
    return check(graph, color, 0, v, m);
}