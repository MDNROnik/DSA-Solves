class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(m>0 && n==0){return;}
        else if(m==0 && n>0){
            nums1=nums2;return;
        }
        vector<int>vec;
        int i=0;int j=0;
        int temp=nums2[n-1];
        while(i<m && j<n){
            if(nums1[i]<nums2[j] ){
                vec.push_back(nums1[i]);i++;
            }
            else if(nums1[i]>nums2[j]){
                vec.push_back(nums2[j]);j++;
            }
            else if(nums1[i]==nums2[j]){
                vec.push_back(nums1[i]);i++;
                vec.push_back(nums2[j]);j++;
            }
        }
        if(j<n){
            for(;j<n;j++){
                vec.push_back(nums2[j]);
            } 
        }
        else if(i<m){
            for(;i<m;i++){
                vec.push_back(nums1[i]);
            } 
        }
        
        nums1=vec;
    }
};