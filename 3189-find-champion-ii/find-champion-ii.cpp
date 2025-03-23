class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        if(n==1){return 0;}
        vector<vector<int>>out(n);
        int m=edges.size();
        for(int i=0;i<m;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            out[a].push_back(b);
        }
        int c=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            // if(out[i].size()==0){
            //     c++;
            //     if(c>1){
            //         return -1;
            //     }
            //     continue;
            // }
            vector<int>visited(n,0);
            queue<int>q;
            q.push(i);visited[i]=1;
            int count=0;
            while(!q.empty()){
                int node = q.front();q.pop();
                int edgeSize=out[node].size();
                count++;
                for(int j=0;j<edgeSize;j++){
                    int edge = out[node][j];
                    if(visited[edge]==0){
                        visited[edge]=1;
                        q.push(edge);
                    }
                }
            }
            if(count==n){
                return i;
            }
        }
        return ans;
    }
};