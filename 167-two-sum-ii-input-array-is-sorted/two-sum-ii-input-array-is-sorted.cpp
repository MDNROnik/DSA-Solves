class Solution {
public:
    vector<int> twoSum(vector<int>& v, int target) {
        vector<int>ans;
        int l=0,r=v.size()-1;
        while(l<r){
            cout<<l<<" "<<r<<endl;
            
            if(v[r]+v[l]==target){
                ans.push_back(l+1);
                ans.push_back(r+1);
                break;
            }
            else if(v[r]+v[l] > target){
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};