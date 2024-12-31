#define ll long long
class Solution {
public:
    bool isHappy(int n2) {
        ll n=n2,count=0;;
        while(n>1){
            cout<<"start "<<n<<endl;
            ll total=0;
            while(n>0){
                cout<<"IN "<<n<<endl;
                ll temp = n%10;
                temp*=temp;
                total+=temp;
                n/=10;
            }
            n=total;
            if(n>1 && n<10 && count==1){
                return false;
            }
            else if(n>2 && n<10){
                count++;
            }
        }
        return true;
    }
};