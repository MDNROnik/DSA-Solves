class Solution {
public:
    string removeDuplicates(string s) {
        for(int i=0;i<s.size();){
            //cout<<i<<" "<<s<<endl;
            if(s[i]==s[i+1]){
                s.erase(i,2);
                if(i!=0){
                    i--;
                }
            }
            else{
                i++;
            }
        }
        return s;
    }
};