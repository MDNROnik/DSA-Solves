class Solution {
public:
    string multiply(string num1, string num2) {
vector<string>vs;
        int gap = 0;
        int mi=0;

        while(num1[0]=='0' || num1[0]=='-'){
            if(num1[0]=='-'){
                mi++;
            }
            num1.erase(num1.begin() + 0);
        }
        while(num2[0]=='0' || num2[0]=='-'){
            if( num2[0]=='-'){
                mi++;
            }
            num2.erase(num2.begin() + 0);
        }
        if(num1.size()==0 || num2.size()==0 ){
            return "0";
        }
        int n=num1.size(), m=num2.size();
        int siz = n>=m ? n+10 : m+10;
        for(int i=m-1;i>=0;i--){
            string now ;
            for(int j=0; j<gap ; j++) {
                now.push_back('0');
            }
            int carry = 0;
            for(int j=n-1;j>=0;j--){
                int x= num2[i]-'0';
                int y= num1[j]-'0';
                int z = x*y;
                z+=carry;
                string stri = to_string(z);
                int num = z%10;
                int remain = z/10;
                carry=remain;
                now.push_back(num+'0');
            }
            if(carry>0){
                now.push_back(carry+'0');
            }
            gap++;
            for(int j=0;j<(siz-gap);j++){
                now.push_back('0');
            }
            vs.push_back(now);
        }
        string ans;

        int carry = 0 , o = vs.size(), p=vs[0].size();
        for(int j=0;j<p;j++){
            int now=0;  
            for(int i=0;i<o;i++){
                int temp=(vs[i][j]-'0');
                now+=temp;
            }
            int z = now+carry;
            carry = 0;
            string stri = to_string(z);
            int num = z%10;
            int remain = z/10;
            carry=remain;
            ans.push_back(num+'0');
        }
        if(carry>0){
            ans.push_back(carry+'0');
        }
        int s = ans.size()-1;
        while(ans[s]!='1' && ans[s]!='2' && ans[s]!='3' && ans[s]!='4' && ans[s]!='5' && ans[s]!='6' && ans[s]!='7' && ans[s]!='8' && ans[s]!='9' ){
            ans.pop_back();
            s=ans.size()-1;
        }
        if(mi==1){
            ans.push_back('-');
        }
        reverse(ans.begin(),ans.end());

        return ans;
    }
};