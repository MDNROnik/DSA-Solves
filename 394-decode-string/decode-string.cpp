class Solution {
public:
    string fun(string &s, int &i, int &n){
        if(i==n){
            return "";
        }
        string digit = "";
        while(i<n && s[i]>='0' && s[i]<='9'){
            digit+=(s[i]);i++;
        }
        if(s[i]=='['){i++;}
        string str="";
        while(i<n && s[i]>='a' && s[i]<='z'){
            str+=(s[i]);i++;
        }
        if(s[i]==']'){
            if(digit.size()==0){
                digit="1";
            }
            stringstream geek;
            geek << digit;
            int count = 0;
            geek >> count;
            string now="";
            while(count--){
                now+=str;
            }
            return now;
        }
        else{
            int temp = i;
            string previous = "";
            for(;i<n;i++){
                
                if(s[i]==']'){
                    break;
                }
                else if(s[i]>='a' && s[i]<='z'){
                    previous+=s[i];
                }
                else{
                    previous+=fun(s, i, n);
                }
            }

            str+=previous;
            if(digit.size()==0){
                digit="1";
            }
            stringstream geek;
            geek << digit;
            int count = 0;
            geek >> count;
            string now="";
            while(count--){
                now+=str;
            }
            return now;
        }
    }
    string decodeString(string s) {
        int n=s.size(), i=0;
        int m = n;
        string ans ="";
        while(i<n){
            if(s[i]>='0' && s[i]<='9'){
                ans+=fun(s, i, n);
            }
            else if(s[i]>='a' && s[i]<='z') {
                ans+=s[i];
            }
            i++;
        }
        return ans;
    }
};