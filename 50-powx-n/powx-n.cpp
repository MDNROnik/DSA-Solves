class Solution {
public:

    double fun(double x, long n){
        if(n==1){
            return x;
        }
        double now = fun(x, n/2);

        if(n%2 == 0){
            cout<<"even"<<endl;
            double res = now*now;
            cout<<n<<" "<<now<<" "<<res<<endl;;
            return res;
        }
        else{
            cout<<"ODD"<<endl;
            double res = now*now;
            res*=x;
            cout<<n<<" "<<now<<" "<<res<<endl;;
            return res;
        }
    }
    double myPow(double x, int n) {
        if(n==0){
            return 1;
        }
        double res = fun(x, abs(static_cast<long>(n)));
        if(n>=0){
            return res;
        }
        else{
            return 1/res;
        }
    }
};