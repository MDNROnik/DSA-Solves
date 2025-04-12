class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int n=bank.size();
        int now = 0, start=0, ans = 0;
        for(int i=0;i<n;i++){
            if(start == 0){
                int m = bank[i].size();
                for(int j=0;j<m;j++){
                    if(bank[i][j]=='1'){now++;start=1;}
                }
            }
            else{
                int next = 0;
                int m = bank[i].size();
                for(int j=0;j<m;j++){
                    if(bank[i][j]=='1'){next++;}
                }
                ans+=(now*next);
                if(next!=0){
                    now=next;
                }
            }
            cout<<now<<endl;
        }
        return ans;
    }
};