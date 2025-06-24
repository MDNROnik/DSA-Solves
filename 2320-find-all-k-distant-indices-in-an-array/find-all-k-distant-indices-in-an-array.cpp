class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>visited(n+10, 0);
        vector<int>ans;
        int mi = INT_MAX, mx=INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]==key){
                int tempmi = i-(k);
                int tempmx = i+(k);
                
                if(tempmi<0){tempmi=0;}
                if(tempmx>=n){
                    tempmx=n-1;
                }
                visited[tempmi]++;
                visited[tempmx+1]--;
            }       
        }

        if(visited[0]>0){
            ans.push_back(0);
        }
        
        for(int i=1;i<n;i++){
            visited[i]+=visited[i-1];
            //cout<<i<<" "<<visited[i]<<endl;
            if(visited[i]>0){
                ans.push_back(i);
            }
        }
        
        
        return ans;
    }
};