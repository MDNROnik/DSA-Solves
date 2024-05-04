class Solution {
public:
int fibona(int i,int j,int n){
        int temp=(i+j);
        i=j;j=temp;
        if(n==2){
            return j;
        }
        return fibona(i,j,n-1);
    }
    int climbStairs(int n) {
        int i=0,j=1;int ans=i+j;
        if(n==0){return 1;}
        if(n==1){return 1;}
        ans=fibona(i,j,n+1);
        return ans;
    }
};