class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        map<int, stack<int> > mp;
        for(int i=0;i<2*e-1;i+=2)
            mp[A[i]].push(A[i+1]);
        for(int i=0;i<2*e-1;i+=2)
            if(mp[B[i]].top()!=B[i+1]) return false;
            else mp[B[i]].pop();
        return true;
    }
};