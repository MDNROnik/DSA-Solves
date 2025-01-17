class Solution {
public:
    int fun(vector<int> &v, int &n, string &s, int i){
        if(i==n){
            return 1;
        }
        if(v[i]!=-1){
            return v[i];
        }
        if(s[i] == '0'){
            return v[i]=0;
        }
        
        int oneStep = 0, twoStep = 0;
        cout<<"step 1 " <<s[i]<<endl;
        oneStep = fun(v, n, s, i+1);
        int now = s[i]-'0';
        now*=10;
        if(i+1<n){
            now+=s[i+1]-'0';
            //cout<<now<<endl;
            if(now>0 && now<27){
                cout<<"step 2 " <<s[i]<<s[i+1]<<endl;
                twoStep = fun(v, n, s, i+2);
            }
        }
        //cout<<s[i]<<" "<<oneStep<<" "<<twoStep<<endl;
        return v[i] = oneStep+twoStep;
    }
    int numDecodings(string s) {
        int n=s.size();
        vector<int>v(n+10, -1);
        return fun(v, n, s, 0);
    }
};