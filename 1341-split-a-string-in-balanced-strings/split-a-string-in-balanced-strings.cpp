class Solution {
public:
    int balancedStringSplit(string s) {
        int count=0;
        int r=0,l=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(r==l && r>0){
                r=0,l=0;
                count++;
            }
            if(s[i]=='L'){l++;}
            else{
                r++;
            }
        }
        if(r==l && r>0){
            r=0,l=0;
            count++;
        }
        return count;
    }
};