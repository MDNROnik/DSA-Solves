class Solution {
public:
    int jump(vector<int>& nums) {
        int init = 0, n=nums.size(), ans = 0;
        for(int i=0;i<n;i++){
            int j;
            //cout<<"START "<<init<<" "<<i<<endl;
            int past = init;
            for(j=i;j<=past && j<n; j++){
                int step = nums[j]+j;
                //cout<<j<<" "<<nums[j]<<endl;
                if(init < step){
                    init=step;
                }
            }
            ans++;
            i=j-1;
        }
        
        return ans-1;
    }
};