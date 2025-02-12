class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int k =0;
        for(int i=0;i<n;){
            // cout<<i<<" "<<nums[i]<<endl;
            int c=0;
            if( i+2<n && nums[i]==nums[i+1] && nums[i]==nums[i+2] ){
                for(int j=i+2;j<n;j++){
                    if(nums[i]==nums[j]){
                        k++;
                        nums[j]=INT_MAX;
                    }
                    else{
                        i=j;c++;
                        break;
                    }
                }
                if(c==0){
                    i=n;
                }
            }
            else{
                i+=1;
            }
        }
        sort(nums.begin(), nums.end());
        return n-k;
    }
};