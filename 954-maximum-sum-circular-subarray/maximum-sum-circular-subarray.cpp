class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int ans = INT_MIN, go=0, c=0;
        vector<int>v,vec;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                go+=nums[i];
                ans=max(ans, go);
                vec.push_back(i);
            }
            else{
                go=0;c++;
            }
            ans = max(ans, nums[i]);
            if(i==0){
                v.push_back(nums[i]);
            }
            else{
                v.push_back(v[i-1]+nums[i]);
            }
            ans = max(ans, v[i]);
        }
        if(c==0){
            return ans;
        }

        int vs=vec.size();
        for(int i=0;i<vs;i++){
            int j=0 , k=i;
            // cout<<j<<" START "<<k<<endl;
            if(i>0 && (vec[i]-1==vec[i-1]) ){
                cout<<"IN"<<endl;continue;
            }
            while(j<i && k<vs){
                //first phrase
                int now = 0;
                now = v[n-1]-v[vec[i]-1];
                now+=v[vec[j]];
                ans = max(ans, now);
                j++;

                //second phrase
                int temp = v[vec[k]];
                if(vec[i]>0){
                    temp-=v[vec[i]-1];
                }
                k++;
                ans = max(ans, temp);
            }
            // cout<<j<<" "<<k<<endl;
            while(j<i){
                //first phrase
                int now = 0;
                now = v[n-1]-v[vec[i]-1];
                now+=v[vec[j]];
                ans = max(ans, now);
                j++;
            }

            while(k<vs){
                //second phrase
                int temp = v[vec[k]];
                if(vec[i]>0){
                    temp-=v[vec[i]-1];
                }
                k++;
                ans = max(ans, temp);
            } 
        }
        return ans;
    }
};