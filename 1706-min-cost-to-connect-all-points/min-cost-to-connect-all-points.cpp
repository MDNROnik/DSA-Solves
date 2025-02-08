class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        map<pair<int,int>,pair<int, int>>mp;

        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> gq;
        gq.push({0, n-1});
        mp[{points[n-1][0], points[n-1][1]}].second = 0;
        long long a=0;
        while(!gq.empty()){
            int index=gq.top().second;
            int dis = gq.top().first;
            gq.pop();
            int row = points[index][0];
            int col = points[index][1];
            if(mp[{row, col}].first==2 || mp[{row, col}].second<dis){continue;}
            mp[{row, col}].first=2;
            a+=dis;
            int c=0;
            for(int i=0;i<n;i++){
                int row2 = points[i][0];
                int col2 = points[i][1];
                if(mp[{row2, col2}].first==2){
                    continue;
                }
                int sum = abs(row-row2) + abs(col-col2);
                if(mp[{row2, col2}].first==0){
                    mp[{row2, col2}].first=1;
                    mp[{row2, col2}].second=INT_MAX;
                }
                if( mp[{row2, col2}].second > sum){
                    mp[{row2, col2}].second=sum;
                    gq.push({sum, i});
                    c++;
                }
            }

        }
        int ans = 0;
        return a;
    }
};