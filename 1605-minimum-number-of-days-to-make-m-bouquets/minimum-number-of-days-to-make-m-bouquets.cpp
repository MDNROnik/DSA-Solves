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
int findMin(vector<int> &v) {
    int maxi = INT_MAX;
    int n = v.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = min(maxi, v[i]);
    }
    return maxi;
}
    int minDays(vector<int>& bloomDay, long long int m, long long int k) {
        int maxi = findMax(bloomDay);
        int mini = findMin(bloomDay);
        int ans=0;
        long long int temp=m*k;
        if( temp > bloomDay.size()){
            //cout<<1111<<endl;
            return -1;
        }
        while(mini<=maxi){
            
            int mid=mini+maxi;
            mid/=2;
            //cout<<mini<<" "<<mid<<" "<<maxi<<endl;
            int now=0,count=0;
            for(int i=0;i<bloomDay.size();i++){
                if(bloomDay[i]<=mid){
                    count++;
                }
                else{
                    now+=(count/k);
                    count=0;
                }
            }
            now+=(count/k);
            //cout<<now<<endl;
            if(now<m){
                mini=mid+1;
            }
            else{
                ans=mid;
                maxi=mid-1;
            }
        }
        
        return ans;
    }
};