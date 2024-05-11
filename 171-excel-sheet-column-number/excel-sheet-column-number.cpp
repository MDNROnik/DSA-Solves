class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.size();
        long long total=0,m=1;

        for(int i=n-1;i>=0;i--){
            cout<<total<<" "<<m<<endl;
            total+=(columnTitle[i]-'A'+1)*m;
            m*=26;
        }
        cout<<total<<" "<<m<<endl;
        return total;
    }
};