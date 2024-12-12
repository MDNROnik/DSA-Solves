#define ll long long
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        ll ans = 0;
        ll l=1,r=1000000000;
        int n=piles.size();
        while(l<=r){
            ll mid = l+(r-l)/2;
            int count=0;
            for(int i=0;i<n;i++){
                int temp = piles[i]/mid;
                if( (piles[i] % mid) != 0 ){
                    temp++;
                }
                count+=temp;
                if(count>h){break;}
            }
            if(count>h){
                l=mid+1;
            }
            else{
                r=mid-1;
                ans=mid;
            }
        }
        return ans;
    }
};