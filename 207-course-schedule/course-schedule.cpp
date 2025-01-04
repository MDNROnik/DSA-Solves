class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        vector<int>indegree(numCourses, 0);
        vector<int>visited(numCourses, 0);
        map<int,vector<int>>mp;
        int n= pre.size();
        for(int i=0;i<n;i++){
            mp[pre[i][1]].push_back(pre[i][0]);
            visited[pre[i][1]]++;
            indegree[pre[i][0]]++;
        }

        queue<int>q;
        for(int i =0;i< numCourses; i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            numCourses--;
            int node = q.front();
            q.pop();
            vector<int>v = mp[node];
            int n = v.size();
            for(int i=0;i<n;i++){
                indegree[v[i]]--;
                if( indegree[v[i]] == 0){
                    q.push(v[i]);
                }
                else if(indegree[v[i]]<0){
                    return false;
                }
            }
        }
        if(numCourses){
            return false;
        }
        return true;
    }
};