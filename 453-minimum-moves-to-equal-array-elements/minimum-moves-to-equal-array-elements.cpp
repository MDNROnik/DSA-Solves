class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int total=0,cur=0;
        int n=nums.size();
        if(n==1){
            return 0;
        }
        int j=n-2;
        int now = nums[0];
        int pre_last = nums[j];
        int high = nums[n-1];
        while(j>-1){
            int temp = abs(now-high);
            total+=temp;
            cur=temp;
            cout<<now<<" "<<pre_last<<" "<<high<<endl;;
            cout<<cur<<" "<<total<<" "<<0<<endl<<endl;;

            now+=cur;
            pre_last+=total;

            high=pre_last;
            j--;
            if(j>-1){
                pre_last = nums[j];
            }
        }
        return total;
    }
};