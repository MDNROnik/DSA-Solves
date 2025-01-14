class Solution {
public:
    int fun(map<pair<int,int>, bool> &visited, map<pair<int,int>, int> &value, int index, int total,int n, int target,
    vector<int>& nums){
        if(index>=n){
            if(total==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(visited[{index, total}]==true){
            return value[{index, total}];
        }
        int now = total + nums[index];
        int now2= total + (nums[index]*(-1));

        int positive = fun(visited, value, index+1, now, n, target, nums);

        int negative = fun(visited, value, index+1, now2, n, target, nums);

        visited[{index, total}]=true;

        int total2 = positive + negative;
        return value[{index, total}] = total2;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, bool> visited;
        map<pair<int,int>, int> value;
        int n = nums.size();
        return fun(visited, value, 0, 0, n, target, nums);
    }
};