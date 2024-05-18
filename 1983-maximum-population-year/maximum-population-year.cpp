class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n=logs.size();
        int count=0,ans=0;
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<n;j++ ){
                if(  logs[i][0] >= logs[j][0] && logs[i][0] < logs[j][1]){
                    temp++;
                }
            }
            if(count<temp ){
                count=temp;
                ans=logs[i][0];
            }
            else if(count==temp){
                if(ans>logs[i][0]){
                    ans=logs[i][0];
                }
            }
        }
        return ans;
    }
    
};