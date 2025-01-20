class Solution {
public:
    int reverse(int y) {
        long long n=0,x=y;
        int tag=0;
        if(x<0){
            tag=1;
            x=abs(x);
        }
        while(x>0){
            long long temp = x%10;
            
            n=(n*10)+temp;
            cout<<temp<<" "<<n<<endl;
            x/=10;
        }

        if(tag==1){
            n = -n;
        }
        if(n>INT_MAX || n<INT_MIN){return 0;}
        
        return n;
    }
};