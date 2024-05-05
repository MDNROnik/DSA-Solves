class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        map<int,bool>mp;
        int n=nums1.size();
        for(int i=0;i<n;i++){
            mp[ nums1[i] ] = true ;
        }
        n=nums2.size();
        for(int i=0;i<n;i++){
            if( mp[ nums2[i] ] ){
                ans.push_back( nums2[i] );
                mp[ nums2[i] ] = false; 
            }
        }
        return ans;
    }
};