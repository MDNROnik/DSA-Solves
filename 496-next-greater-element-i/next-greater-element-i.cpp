class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size(), m=nums2.size();
        map<int,int>mp;
        for(int i=0;i<m;i++){
            mp[nums2[i]] = i;
        }
        for(int i=0;i<n;i++){
            int index = mp[nums1[i]];
            int great = -1;
            for(int j=index;j<m;j++){
                if(nums1[i]<nums2[j]){
                    great = nums2[j];break;
                }
            }
            ans.push_back(great);
        }
        return ans;
    }
};