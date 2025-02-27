class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int ans=0;
        while(l<r){
            // cout<<l<<" "<<r<<endl;
            int temp = min(height[l],height[r]);
            temp*=(r-l);

            // cout<<temp<<endl;
            ans=max(ans,temp);
            if(height[l]<height[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return ans;
    }
};