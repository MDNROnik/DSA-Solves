#define ll long long int

class Solution {
public:
    int mySqrt(int n) {
        ll low=1,high=n;
        ll ans=1;
        while(low<=high){
            ll mid=low+high;
            mid/=2;
            ll m=mid;
            mid*=mid;
            
            if(mid <= n){
                
                ans=m;
                low=m+1;
            }
            else{
                
                high=m-1;
            }
        }
        return high;
    }
};