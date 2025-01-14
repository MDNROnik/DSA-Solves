class Solution {
public:
    int fun(map<pair<int,int>, bool> &visited, map<pair<int,int>, int> &value, int index, int total,int n, int target,
    vector<int>& nums, vector<int> &v){
        if(index>=n){
            if(total==target){
                cout<<1111<<endl;
                return 1;
            }
            else{
                return 0;
            }
        }
        if(visited[{index, total}]==true){
            //cout<<1111<<endl;
            return value[{index, total}];
        }
        //cout<<index<<endl;
        int now = total + nums[index];
        int now2= total + (nums[index]*(-1));

        v.push_back(nums[index]);
        int positive = fun(visited, value, index+1, now, n, target, nums, v);

        v.pop_back();v.push_back(nums[index]*(-1));
        int negative = fun(visited, value, index+1, now2, n, target, nums, v);

        visited[{index, total}]=true;

        int total2 = positive + negative;
        //cout<<positive<<" "<<negative<<endl;
        return value[{index, total}] = total2;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        map<pair<int,int>, bool> visited;
        map<pair<int,int>, int> value;
        int n = nums.size();
        vector<int>v;
        return fun(visited, value, 0, 0, n, target, nums, v);
    }
};