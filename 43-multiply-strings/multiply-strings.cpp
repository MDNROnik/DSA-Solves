class Solution {
public:
    string multiply(string num1, string num2) {
        vector<string>vs;
        int gap = 0;
        if(num1=="0" || num2=="0"){
            return "0";
        }
        int siz = num1.size()>=num2.size() ? num1.size()+10 : num2.size()+10;
        for(int i=num2.size()-1;i>=0;i--){
            string now ;
            for(int j=0; j<gap ; j++) {
                now.push_back('0');
            }
            int carry = 0;
            for(int j=num1.size()-1;j>=0;j--){
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
        // for(int i=0;i<vs.size();i++){
        //     cout<<vs[i]<<endl;
        // }
        int carry = 0;
        for(int j=0;j<vs[0].size();j++){
            int now=0;  
            for(int i=0;i<vs.size();i++){
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
        reverse(ans.begin(),ans.end());
        int n = 7;
        return ans;
    }
};