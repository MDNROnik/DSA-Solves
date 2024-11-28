class Solution {
public:
    bool isPalindrome(string s) {
        int i=0,j=s.size()-1;
        int c=1;
        while(i<j){
            cout<<s[i]<<" "<<s[j]<<endl;
            if( ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') ) &&
                ((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9') )
            ){
                char a=(char)tolower(s[i]);
                char b=(char)tolower(s[j]);
                cout<<a<<" IN "<<b<<endl;
                if(a!=b){
                    c=0;
                    break;
                }
                i++;j--;
            }
            else{
                
                if( ((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z') || (s[i]>='0' && s[i]<='9') )  ){
                    j--;
                }
                else if( ((s[j]>='a' && s[j]<='z') || (s[j]>='A' && s[j]<='Z') || (s[j]>='0' && s[j]<='9') ) ){
                    i++;
                }
                else{
                    i++;j--;
                }
                
            }
        }
        if(c==0){
            return false;
        }
        return true;
    }
};