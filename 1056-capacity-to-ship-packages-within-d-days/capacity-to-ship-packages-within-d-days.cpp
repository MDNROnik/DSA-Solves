class Solution {
public:
    int findMax(vector<int> &v) {
        int maxi = INT_MIN;
        int n = v.size();
        //find the maximum:
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, v[i]);
        }
        return maxi;
    }
    int shipWithinDays(vector<int>& a, int days) {
        //sort(a.begin(),a.end());
        int maxi = accumulate(a.begin(), a.end(), 0);
        int mini = findMax(a);
        while(mini<=maxi){
            int mid= maxi+mini;
            mid/=2;
            cout<<mini<<" "<<mid<<" "<<maxi<<endl;
            int total=1,sum=0;
            for(int i=0;i<a.size();i++){
                if(a[i]+sum > mid){
                    total++;
                    sum=a[i];
                }
                else{
                    sum+=a[i];
                }
            }
            if(total>days){
                mini=mid+1;
            }
            else{
                maxi=mid-1;
            }
        }
        return mini;
    }
};