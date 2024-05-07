class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string n,n2;
        int count=0,count2=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='#'){
                count++;
            }
            else{
                if(count>0){
                    count--;
                }
                else{
                    n.push_back(s[i]);
                }
            }
        }
        for(int i=t.size()-1;i>=0;i--){
            if(t[i]=='#'){
                count2++;
            }
            else{
                if(count2>0){
                    count2--;
                }
                else{
                    n2.push_back(t[i]);
                }
            }
        }

        return (n == n2);

    }
};