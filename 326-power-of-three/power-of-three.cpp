class Solution {
public:
    bool isPowerOfThree(int n) {
        int i=0;
        int m=n;
        while(i<=n){
            int mid =  i + (n-i)/2;
            if( pow(3,mid) == m ){
                return true;
            }
            else if( pow(3,mid) > m ){
                n=mid-1;
            }
            else{
                i=mid+1;
            }
        }
        return false;
    }
};