class Solution {
public:
    int bitwiseComplement(int n) {
        int m=n;int mash=0;
        if(n==0)return 1;
        while(m!=0){
            mash=(mash << 1) | 1;
            m>>=1;
        }
        int ans=(~n)&mash;
        return ans;
    }
};