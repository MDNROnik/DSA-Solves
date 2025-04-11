class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        map<string, bool>mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]=true;
        }
        string ans=nums[0];
        for(int i=0;i<n;i++){
            if(ans[i]=='1'){
                ans[i]='0';
                if(mp[ans]==false){
                    break;
                }
                ans[i]='1';
            }
            else if(ans[i]=='0'){
                ans[i]='1';
                if(mp[ans]==false){
                    break;
                }
                ans[i]='0';
            }
        }
        return ans;
    }
};