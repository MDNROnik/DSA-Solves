class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>v(n);
        int index ;
        if(k>n){
            int remain = k%n;
            index = n-remain; 
        }
        else{
            index= n-k;
        }
        int i=index, j=0;
        for(;i<n;i++,j++){
            v[j]=nums[i];
        }
        for(i=0;i<index;i++, j++){
            v[j]=nums[i];
        }
        nums=v;
    }
};