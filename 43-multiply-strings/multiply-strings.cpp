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
                //cout<<x<<" "<<y<<endl;

                int z = x*y;
                z+=carry;
                string stri = to_string(z);
                int num = z%10;
                int remain = z/10;
                carry=remain;
                now.push_back(num+'0');
                //cout<<"TOTLA"<<endl;
                //cout<<z<<endl;
                // if(stri.size()>1){
                //     //cout<<"size is 2"<<endl;
                //     string a;
                //     string b;
                //     a.push_back(stri[0]);
                //     b.push_back(stri[1]);
                //     now+=(b);
                //     carry = a[0]-'0';
                // }
                // else{
                //     //cout<<"size is 1"<<endl;
                //     string a;
                //     string b;
                //     a.push_back(stri[0]);
                //     b.push_back(stri[1]);
                //     now+=(a);
                //     //cout<<a<<" "<<b<<endl;
                //     carry = 0;
                // }
                //cout<<now<<endl;
            }
            if(carry>0){
                //cout<<" "<<carry<<endl;
                now.push_back(carry+'0');
                //<<now<<endl;
            }
            gap++;
            //cout<<now<<" " ;
            for(int j=0;j<(siz-gap);j++){
                now.push_back('0');
            }
            //cout<<now;
            //cout<<endl<<endl;
            vs.push_back(now);
        }
        string ans;
        for(int i=0;i<vs.size();i++){
            cout<<vs[i]<<endl;
        }
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
            //cout<<num<<" "<<remain<<endl;
            //cout<<z<<endl;
           // cout<<z<<" "<<carry<<endl;
            // if(stri.size()>1){
            //     //cout<<"size is 2"<<endl;
            //     string a;
            //     string b;
            //     a.push_back(stri[0]);
            //     b.push_back(stri[1]);
            //     ans+=(b);
            //     carry = a[0]-'0';
            // }
            // else{
            //     //cout<<"size is 1"<<endl;
            //     string a;
            //     string b;
            //     a.push_back(stri[0]);
            //     b.push_back(stri[1]);
            //     ans+=(a);
            //     //cout<<a<<" "<<b<<endl;
            //     carry = 0;
            // }
            //cout<<ans<<endl;
        }
        if(carry>0){
            ans.push_back(carry+'0');
        }
        int s = ans.size()-1;
        while(ans[s]!='1' && ans[s]!='2' && ans[s]!='3' && ans[s]!='4' && ans[s]!='5' && ans[s]!='6' && ans[s]!='7' && ans[s]!='8' && ans[s]!='9' ){
            ans.pop_back();
            s=ans.size()-1;
        }
       // cout<<endl;
        cout<<ans<<endl;
        reverse(ans.begin(),ans.end());
        int n = 7;
       
        return ans;
    }
};