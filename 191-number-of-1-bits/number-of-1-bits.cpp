class Solution {
public:
    int hammingWeight(int n) {
        int ans;
        while(n!=0){
            if(n%2!=0){
                ans++;
            }
            n=n/2;
        }

        return ans;
    }
};