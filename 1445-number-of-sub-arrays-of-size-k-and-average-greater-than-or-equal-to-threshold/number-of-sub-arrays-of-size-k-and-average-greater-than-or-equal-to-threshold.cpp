class Solution {
public:
    int numOfSubarrays(vector<int>& a, int k, int t) {
        int n=a.size();
        for(int i=1; i<n;i++){
            a[i]+=a[i-1];
        }
        int st = k-1;
        int ans = 0;
        for(int i=st; i<n;i++){
            int nnn ;
            if(i == k-1){
                nnn = a[i]/k;
            }
            else{
                nnn = (a[i]-a[i-k]) / k ;
            }

            if(nnn>=t){
                ans++;
            }
        }
        return ans;
    }
};