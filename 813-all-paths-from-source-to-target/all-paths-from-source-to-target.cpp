class Solution {
public:
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        int n2=g.size();
        vector<vector<int>>ans;
        vector<int>visited(n2,0);
        vector<int>now;
        now.push_back(0);
        queue<pair<int, vector<int>>>q;
        q.push({0, now});
        while(!q.empty()){
            int node = q.front().first;
            vector<int>n = q.front().second;
            q.pop();
            // cout<<node<<endl;
            for(int i=0;i<g[node].size();i++){
                int edge = g[node][i];
                if(edge==n2-1){
                    n.push_back(edge);
                    ans.push_back(n);
                    n.pop_back();
                }
                else {
                    n.push_back(edge);
                    q.push({edge,n});
                    n.pop_back();
                }
                
            }
        }
        return ans;
    }
};