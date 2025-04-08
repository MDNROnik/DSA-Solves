class Solution {
public:
    vector<int> getAverages(vector<int>& aaa, int k) {
        int n=aaa.size();
        vector<long long>a;
        a.push_back(aaa[0]);
        for(int i=1; i<n;i++){
            a.push_back(a[i-1]+aaa[i]);
        }
        vector<int> ans(n, -1);
        for(int i=k; i+k<n;i++){
            int nnn ;
            if(i == k){
                nnn = a[i+k]/(k+k+1);
            }
            else{
                nnn = (a[i+k]-a[i-k-1])/(k+k+1);
            }
            ans[i] = (nnn);
        }
        return ans;
    }
};