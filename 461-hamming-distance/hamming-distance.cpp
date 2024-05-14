class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans=0;
        while(y>0 || x>0){
            int t=-1, t2=-1;
            t=x%2;x/=2;
            t2=y%2;y/=2;
            //cout<<t<<" "<<t2<<endl;
            if(t!=t2){ans++;}
        }
        return ans;
    }
};