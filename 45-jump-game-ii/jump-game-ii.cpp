class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0;
        int n=nums.size();
        if(n==1){return 0;}
        for(int i=0;i<n;){
            int can = nums[i];
            int maxi = 0, j = 0, in = i, jn =i;
            cout<<i<<" "<<nums[i]<<endl;
            for(j=i+1; can>0 &&  j<n ;j++){
                cout<<j<<" -- "<<nums[j]<<endl;
                
                if( j+nums[j] >maxi || j+nums[j]>=n-1){
                    if(j+nums[j]>=n-1){}
                    maxi=j+nums[j];
                    in=j;
                }
                // if(maxi<nums[j]){
                //     maxi=nums[j];
                //     in=j;
                // }
                can--;
            }
            ans++;
            i=in;
            //cout<<i<<" "<<nums[i]<<endl<<endl;;
            if(i>=n-1){break;}
        }

        
        return ans;
    }
};