class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        // sort(points.begin(),points.end());
        map<pair<int,int>,pair<int, int>>mp;
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> gq;
        gq.push({0, n-1});
        // mp[{points[n-1][0], points[n-1][1]}].first=true;
        mp[{points[n-1][0], points[n-1][1]}].second = 0;
        int a=0;
        while(!gq.empty()){
            int index=gq.top().second;
            int dis = gq.top().first;
            gq.pop();
            int row = points[index][0];
            int col = points[index][1];
            mp[{row, col}].first=2;
            // a+=dis;
            // cout<<row<<" "<<col<<endl;
            for(int i=0;i<n;i++){
                int row2 = points[i][0];
                int col2 = points[i][1];
                if(mp[{row2, col2}].first==2){
                    continue;
                }
                // cout<<row2<<" "<<col2<<endl;
                int sum = abs(row-row2) + abs(col-col2);
                if(mp[{row2, col2}].first==0){
                    mp[{row2, col2}].first=1;
                    mp[{row2, col2}].second=INT_MAX;
                }
                // cout<<mp[{row2, col2}].second<<" "<<sum<<endl<<endl;;
                if( mp[{row2, col2}].second > sum){
                    mp[{row2, col2}].second=sum;
                    gq.push({sum, i});
                }
            }
        }
        int ans = 0;
        for(auto a=mp.begin();a!=mp.end();a++){
            // cout<<a->first.first<<" "<<a->first.second<<" --- "<<a->second.first<<" "<<a->second.second<<endl;
            ans+=a->second.second;
        }
        return ans;
    }
};