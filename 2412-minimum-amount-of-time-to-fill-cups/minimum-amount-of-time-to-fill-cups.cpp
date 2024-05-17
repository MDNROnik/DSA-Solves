class Solution {
public:
    int fillCups(vector<int>& amount) {
        sort(amount.begin(),amount.end());
        int n = amount.size();
        int ans=0;
        for(int i=0;;i++){
            if(amount[0]<=0 && amount[1]<=0 && amount[2]<=0){
                break;
            }
            amount[2]--;
            amount[1]--;
            sort(amount.begin(),amount.end());
            ans++;
        }
        return ans;
    }
};