class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        int n=points.size();
        for(int i=0;i<n;i++){
            int temp = pow(points[i][0], 2) + pow(points[i][1], 2);
            pq.push({temp, {points[i][0], points[i][1]}});
        }
        vector<vector<int>>ans;
        while(k--){
            vector<int>a;
            a.push_back(pq.top().second.first);
            a.push_back(pq.top().second.second);
            ans.push_back(a);
            pq.pop();
        }
        return ans;
    }
};