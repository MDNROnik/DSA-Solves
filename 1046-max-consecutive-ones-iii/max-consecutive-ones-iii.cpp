class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int count=0;
        int ans=0;
        int temp=0;
        vector<int>zero;

        int l=0,r=0, i=0,j=0;
        while(i<nums.size()){
            //cout<<i<<endl;
            if(nums[i]==1){
                //cout<<"for 1"<<endl;
                r=i;
                ans = max(ans,   ((r-l)+1));
            }
            else{
                zero.push_back(i);
                //cout<<"for 0"<<endl;
                if(k>0){
                    cout<<"remain"<<endl;
                    k--;
                    r=i;
                    ans = max(ans,   ((r-l)+1));
                }
                else{
                    l = zero[j];j++;
                    l=l+1;
                    r=i;
                    ans = max(ans, ((r-l)+1) );

                    // //cout<<"no remain"<<endl;
                    // while(l<nums.size()){
                    //     if(nums[l]==0){
                    //         break;
                    //     }
                    //     l++;
                    // }
                    // l=l+1;
                    // r=i;
                    // ans = max(ans,   ((r-l)+1));
                    // //cout<<l<<" "<<r<<endl;
                }
            }
            i++;
            //cout<<l<<" "<<r<<" "<<ans<<endl;
            //cout<<endl;
        }
        return ans;
    }
};