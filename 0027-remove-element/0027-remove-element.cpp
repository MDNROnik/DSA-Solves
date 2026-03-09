class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int j=n-1, ans = 0;
        for(int i=0;i<n;i++){
            if(nums[i]!=val){
                ans++;
            }
            else{
                cout<<"IN  "<<i<<" "<<j<<endl;
                if(i>=j){break;}
                while(j>=i){
                    if(nums[j]==val){
                        j--;
                    }
                    else{
                        cout<<"SWAP"<<endl;
                        swap(nums[i], nums[j]);
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};