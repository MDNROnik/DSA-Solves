class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        vector<int>zero,one;
        int n=nums.size();
        //zero.push_back(0);
        int ans=0;
        one.push_back(0);
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                one.push_back(i+1);
            }
            else{
                zero.push_back(i+1);
            }
        }
        
        // if(one.size()==2){
        //     one.push_back(one[1]);
        // }
        one.push_back(n+1);
        for(int i=0;i<one.size();i++){
            cout<<one[i]<<" ";
        }
        cout<<endl;
        if(goal==0){
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
            if(one.size()-2>=goal){
                //cout<<11<<endl;
                int l=1,r=0;
                cout<<one.size()<<endl;
                while(r<one.size()-2){
                    r=l+goal;
                    r--;
                    cout<<l<<" "<<r<<endl;
                    cout<<one[l]<<" "<<one[r]<<endl;
                    if(r>=one.size()){
                        //cout<<r<<" "<<one.size()<<endl;
                        break;
                    }
                    
                    //cout<<one[l]<<" "<<one[r]<<endl;

                    //cout<<one[l]<<" "<<one[l-1]<<endl;
                    //cout<<one[r]<<" "<<one[r+1]<<endl;
                    int left = one[l]-one[l-1];
                    int right = one[r+1]-one[r];
                    //cout<<left<<" "<<right<<endl;
                    left--;right--;
                    // if(left==0){left++;}
                    // if(right==0){right++;}
                    //cout<<left<<" "<<right<<endl<<endl;
                    // int count=0;
                    // if(left==0 || right==0){count++;}
                    cout<<left<<" "<<right<<endl<<endl;
                    // left+=right;
                    // //cout<<left<<endl;
                    // left= (left*(left+1))/2;
                    // if(count==1){left++;}
                    // //cout<<left<<endl<<endl;
                    // ans+=left;
                    //cout<<ans<<endl;
                    if(left>0 && right>0){
                        int maxi = max(left,right);
                        int mini = min(left,right);
                        int total = maxi*mini;
                        total+=maxi;
                        total+=(mini+1);
                        ans+=total;

                        
                    }
                    else if(left==0 && right==0){
                        //cout<<11<<endl;
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