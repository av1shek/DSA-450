class Solution{
public:
    vector<int> findTwoElement(int *arr, int n) {
        int xorr = 0;
        for(int i=1;i<=n;i++) xorr = xorr ^ i;
        for(int i=0;i<n;i++) xorr = xorr ^ arr[i];
        
        int cnt = 0;
        while((xorr & 1) == 0){
            xorr = xorr>>1;
            cnt++;
        }
        int a = 0, b = 0;
        for(int i=1;i<=n;i++){
            if( ((i>>cnt)&1) == 0 ) a = a ^ i;
            else b = b ^ i;
        }
        for(int i=0;i<n;i++){
            if( ((arr[i]>>cnt)&1) == 0 ) a = a ^ arr[i];
            else b = b ^ arr[i];
        }
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(arr[i] == a){
                ans.push_back(a);
                ans.push_back(b);   break;
            }
            else if(arr[i]==b){
                ans.push_back(b);
                ans.push_back(a);   break;
            }
        }
        return ans;
    }
};