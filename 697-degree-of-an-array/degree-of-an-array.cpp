class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int, pair<int, pair<int,int> > >mp;
        int mx=-1,ans=INT_MAX;

        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[ nums[i] ].first++;
            if(mp[ nums[i] ].second.first==0){
                mp[ nums[i] ].second.first=i+1;
                mp[ nums[i] ].second.second=i+1;
            }
            else{
                mp[ nums[i] ].second.second=i+1;
            }
            mx=max(mx, mp[ nums[i] ].first);

            // if( mp[ nums[i] ].first == mx){
            //     int first = mp[ nums[i] ].second.first;
            //     int second = mp[ nums[i] ].second.second;
            //     second-=first;
            //     second++;
            //     ans=min(ans,second);
            // }

        }

        for(auto a=mp.begin();a!=mp.end();a++){
            // cout<<a->first<<" "<<a->second.first<<" "<<a->second.second.first<<" "<<a->second.second.second<<endl;
            if(a->second.first==mx){
                int first = a->second.second.first;
                int second = a->second.second.second;
                second-=first;
                second+=1;
                ans=min(ans,second);
            }
        }
        return ans;
    }
};