class Solution {
public:
    int fun(map<pair<int,int>, pair<bool,int>>&visited, int index, int total,int n, int target,
    vector<int>& nums){
        if(index>=n){
            if(total==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(visited[{index, total}].first==true){
            return visited[{index, total}].second;
        }
        int now = total + nums[index];
        int now2= total + (nums[index]*(-1));

        int positive = fun(visited, index+1, now, n, target, nums);

        int negative = fun(visited, index+1, now2, n, target, nums);

        visited[{index, total}].first=true;

        int total2 = positive + negative;
        return visited[{index, total}].second = total2;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, pair<bool,int>> visited;
        int n = nums.size();
        return fun(visited, 0, 0, n, target, nums);
    }
};