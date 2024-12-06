class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int>v(n,0);
        int last_max=0;
        for(int j=n-1;j>=0;j--){
            v[j]=last_max;
            last_max=max(last_max,height[j]);
        }
        int ans=0;
        int i=0;
        while(i<n){
            if(height[i]>0){break;}
            i++;
        }
        if(i==n){return ans;}
        int run=0;
        last_max=0;
        while(i<n){
            cout<<i<<" "<<run<<" ";
            if(run==0){
                if(height[i]<=v[i]){
                    last_max=height[i];run=1;i++;
                }
                else{
                    last_max=v[i];run=1;i++;
                }
            }
            else if(run==1){
                if(last_max >= height[i]){
                    //cout<<111<<endl;
                    ans+=(last_max-height[i]);
                    if(height[i]==last_max){
                        run=0;//cout<<111<<endl;
                    }
                    else{
                        i++;
                    }
                }
                else{
                    run=0;
                }
            }
            cout<<ans<<endl;
        }
        return ans;
        
    }
};