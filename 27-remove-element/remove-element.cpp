class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        queue<int>st;
        int n = nums.size();
        int re = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==val){
                re++;
            }
            else{
                st.push(nums[i]);
            }
        }
        n-=re;
        for(int i=0;i<n;i++){
            nums[i]=st.front();
            st.pop();
        }
        return n;
    }
};