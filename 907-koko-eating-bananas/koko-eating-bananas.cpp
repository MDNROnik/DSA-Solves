class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int low=1;
        int high=piles[piles.size()-1];
        //ceil((double)(v[i]) / (double)(hourly));
        
        int ans=0;
        while(low<=high){
            int mid=low+high;
            mid/=2;
            cout<<low<<" "<<mid<<" "<<high<<endl;
            int now=0;
            for(int i=0;i<piles.size();i++){
                now+=ceil((double)(piles[i]) / (double)(mid));
                if(now>h){break;}
            }
            //cout<<now<<endl;
            if(now<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }

        return ans;
    }
};