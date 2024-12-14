class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>v;
        int i=0,j=0;
        int n=nums1.size(), m=nums2.size();
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                v.push_back(nums1[i]);i++;
            }
            else{
                v.push_back(nums2[j]);j++;
            }
        }
        while(i<n){
            v.push_back(nums1[i]);i++;
        }
        while(j<m){
            v.push_back(nums2[j]);j++;
        }
        n=v.size();
        if(n%2==0){
            i=n/2;i--;
            j=n/2;
            cout<<i<<" "<<j<<endl;
            return double(  (v[i]+v[j])  ) /2;
        }
        else{
            return v[n/2];
        }
    }
};