class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int>vec;
        int i=0,j=0;
        //cout<<i<<" "<<(m-n)<<" "<<j<<" "<<n<<endl;
        while(i<m && j<n){
            // cout<<nums1[i]<<" "<<nums2[j]<<endl;
            if(nums1[i]<=nums2[j]){
                vec.push_back(nums1[i]);i++;
            }
            else{
                vec.push_back(nums2[j]);j++;
            }
        }
        while(i<m){
            vec.push_back(nums1[i]);i++;
        }
        while(j<n){
            vec.push_back(nums2[j]);j++;
        }
        // cout<<vec.size()<<endl;
        nums1=vec;
    }
};