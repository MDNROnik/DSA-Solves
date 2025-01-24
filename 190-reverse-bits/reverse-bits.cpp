class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        cout<<n<<endl;
        string str;
        while(n>0){
            if(n%2==0){
                str.push_back('0');
            }
            else{
                str.push_back('1');
            }
            n/=2;
        }
        cout<<str<<endl;
        //reverse(str.begin(),str.end());
        while(str.size()<=31){
            str.push_back('0');
        }
        cout<<str<<endl;
        reverse(str.begin(),str.end());
        n=0;
        long long pow = 1;
        for(int i=0;i<str.size();i++){
            if(str[i]=='1'){
                n+=pow;
            }
            pow+=pow;
        }

        return n;
    }
};