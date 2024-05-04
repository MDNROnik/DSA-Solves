class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        map<int,int>hash;
        for(int i=0;i<nums.size();i++){
            hash[nums[i]]=i+1;
        }
        for(int i=0;i<nums.size();i++){
            int remain = target - nums[i];
            if(hash[remain] != 0 && (hash[remain]-1) != i){
                v.push_back(i);
                v.push_back(hash[remain]-1);break;
            }
        }
        return v;
    }
};