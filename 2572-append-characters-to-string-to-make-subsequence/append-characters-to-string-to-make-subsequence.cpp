class Solution {
public:
    int appendCharacters(string s, string t) {
        int n=s.size();
        int m=t.size();
        int j=0, i=0;
        for(i=0;i<m;i++){
            int c=0;
            for(;j<n;){
                if(t[i]==s[j]){
                    c=1;j+=1;break;
                }
                else{
                    j+=1;
                }
            }
            if(c==0){break;}
        }
        cout<<i<<" "<<j<<endl;
        return m-i;
    }
};