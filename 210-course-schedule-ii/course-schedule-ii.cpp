class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<int>indegree(numCourses, 0);

        map<int,vector<int>>mp;
        int n= pre.size();
        for(int i=0;i<n;i++){
            mp[pre[i][1]].push_back(pre[i][0]);
            indegree[pre[i][0]]++;
        }

        queue<int>q;
        vector<int>ans;
        for(int i =0;i< numCourses; i++){
            if(indegree[i]==0){
                ans.push_back(i);
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
                    ans.push_back(v[i]);
                    q.push(v[i]);
                }
                else if(indegree[v[i]]<0){
                    return {};
                }
            }
        }
        if(numCourses){
            return {};
        }
        return ans;
    }
};