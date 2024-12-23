class Solution {
public:
    void fun(vector<vector<int>> &ans, vector<int>&num, int index, int &siz, vector<int>&now){
        if(index==siz){
            // for(int i=0;i<siz;i++){
            //     cout<<num[i]<<" ";
            // }
            // cout<<endl;
            ans.push_back(num);return;
        }
        for(int i=index;i<siz;i++){
            swap(num[index],num[i]);
            fun(ans, num, index+1, siz, now);
            swap(num[index],num[i]);
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int>now;
        fun(ans, nums, 0, n, now);
        return ans;
    }
};