class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int low=-1;
        int large=1000;
        for(int i=0;i<nums.size();i++){
            if(large>nums[i]){
                large=nums[i];
                low=i;
            }
        }
        int count=0;
        for(int i=low;i<nums.size();i++){
            if(large<=nums[i]){
                large=nums[i];
            }
            else{
                count++;return -1;
            }
        }
        for(int i=0;i<low;i++){
            if(large<=nums[i]){
                large=nums[i];
            }
            else{
                count++;return -1;
            }
        }
        low++;
        //cout<<low<<endl;
        if(low==1){
            return 0;
        }
        else{
            return (nums.size()-low)+1;
        }
    }
};