class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int count=0;
        int ans=0;
        int temp=0;
        int k=2;
        int l=0,r=0,j=0;
        set<int>s;
        map<int,int>mp;
        int n=nums.size();
        while(r<n){
            mp[nums[r]]++;
           // cout<<mp.size()<<" "<<r<<endl;
            if(mp.size()<=2){
                ans = max(ans, ((r-l)+1) );
            }
            else{
                mp[nums[l]]--;
                if(mp[nums[l]]==0){
                    mp.erase(nums[l]);
                }
                l++;
            }
           // cout<<mp.size()<<" "<<r<<endl<<endl;
            r++;
        }
        return ans;
    }
};