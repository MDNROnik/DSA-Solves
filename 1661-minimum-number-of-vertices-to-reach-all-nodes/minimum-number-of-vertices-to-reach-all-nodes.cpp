class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        vector<int>indegree(n, 0);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int from=edges[i][0];
            int to = edges[i][1];
            indegree[to]=1;
        }
        for(int i=0;i<n;i++){
            if(indegree[i]==0){ans.push_back(i);}
        }
        return ans;
    }
};