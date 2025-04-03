class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        map<long long, int>mp;
        sort(skill.begin(), skill.end());
        int i=0, j=skill.size()-1;
        long long ans = -1, ans2=0;
        while(i<j){
            long long a=skill[i];
            long long b=skill[j];
            // cout<<a<<" "<<b<<endl;
            int c=skill[i]+skill[j];
            a*=b;
            // cout<<a<<' '<<ans<<endl;
            if(ans != c){
                if(ans==-1){
                    ans=c;
                }
                else{
                    return -1;    
                }
            }
            ans2+=a;
            i++;j--;
        }
        return ans2;
    }
};