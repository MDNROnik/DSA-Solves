class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(n==k){
            return true;
        }
        else if(n<k){
            return false;
        }

        map<int,int>mp;
        int ans=0;
        for(int i=0;i<n;i++){
            mp[ s[i] ]++;
            if( mp[ s[i] ]%2==0 ){
                ans--;
            }
            else{
                ans++;
            }
        }
        //cout<<ans<<endl;
        if(ans<=k){
            return true;
        }
        else{
            return false;
        }
    }
};