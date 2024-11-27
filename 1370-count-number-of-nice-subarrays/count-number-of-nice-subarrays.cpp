class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int>zero,one;
        int n=nums.size();
        int ans=0;
        one.push_back(0);
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                one.push_back(i+1);
            }
            
        }

        one.push_back(n+1);
        
        if(k==0){
            if(zero.size()==n){
                return (n*(n+1))/2;
            }
            int count=1;
            for(int i=0;i<n;i++){
                
                if(nums[i]==0){
                    ans+=count;count+=1;
                }
                else{
                    count=1;
                }
            }
        }
        else{
            if(one.size()-2>=k){
                int l=1,r=0;
                while(r<one.size()-2){
                    r=l+k;
                    r--;
                    
                    if(r>=one.size()){
                        break;
                    }

                    int left = one[l]-one[l-1];
                    int right = one[r+1]-one[r];
                    left--;right--;

                    if(left>0 && right>0){
                        int maxi = max(left,right);
                        int mini = min(left,right);
                        int total = maxi*mini;
                        total+=maxi;
                        total+=(mini+1);
                        ans+=total;

                        
                    }
                    else if(left==0 && right==0){
                        ans++;
                    }
                    else if(left==0){
                        ans+=right;
                        ans++;
                    }
                    else if(right==0){
                        ans+=left;
                        ans++;
                    }
                    
                    
                    l++;
                }
            }
            else{
                return 0;
            }
        }
        return ans;
    }
};