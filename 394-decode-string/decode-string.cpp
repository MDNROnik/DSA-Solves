class Solution {
public:
    string fun(string &s, int &i, int &n, int &open){
        cout<<i<<endl;open++;
        if(i==n){
            return "";
        }
        string digit = "";
        while(i<n && s[i]>='0' && s[i]<='9'){
            digit.push_back(s[i]);i++;
        }
        if(s[i]=='['){i++;}
        string str="";
        while(i<n && s[i]>='a' && s[i]<='z'){
            str.push_back(s[i]);i++;
        }
        cout<<digit<<" "<<str<<endl;
        if(s[i]==']'){
            cout<<" CLOSED "<<i<<endl;
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
            // cout<<now<<endl;
            open--;
            return now;
        }
        else{
            cout<<"NOT CLOSED "<<i<<endl;
            int temp = i;
            string previous = "";
            for(;i<n && open>0;i++){
                
                if(s[i]==']'){
                    // i--;
                    cout<<temp<<" close "<<i<<endl;
                    break;
                }
                else if(s[i]>='a' && s[i]<='z'){
                    previous+=s[i];
                }
                else{
                    // cout<<" DIP "<<i<<" AND OPEN "<<open<<endl;
                    previous+=fun(s, i, n, open);
                    // cout<<"back "<<i<<endl;
                    // cout<<previous<<endl;
                }
            }

            cout<<temp<<" form to "<<previous<<endl;
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
        while(n-1>=0 && s[n-1]!=']'){n--;}
        if(n<0){return s;}
        int open = 0;
        while(i<n){
            cout<<"MAIN LOOP "<<i<<endl;
            if(s[i]>='0' && s[i]<='9'){
                ans+=fun(s, i, n, open);
            }
            else if(s[i]>='a' && s[i]<='z') {
                ans+=s[i];
            }
            i++;
        }
        while(n<m){
            ans.push_back(s[n]);
            n++;
        }
        return ans;
    }
};