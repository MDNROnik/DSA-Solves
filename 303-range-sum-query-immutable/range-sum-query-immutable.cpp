class NumArray {
public:
    vector<int>nums;
    NumArray(vector<int>& num) {
        int n= num.size();
        nums.push_back(num[0]);
        for(int i=1;i<n;i++){
            nums.push_back(nums[i-1]+num[i]);
        }
        cout<<nums.size()<<endl;
    }
    
    int sumRange(int left, int right) {
        if(left==0){
            return nums[right];
        }
        else{
            // cout<<nums[right]<<" "<<nums[left-1]<<endl;
            return nums[right]-nums[left-1];
        }
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */