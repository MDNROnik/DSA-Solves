class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;int k=0;
        for(int i=0;i<numRows;i++){
            vector<int>v((i+1),0);
            if(i==0){
                v[0]=1;
                ans.push_back(v);
            }
            else{
                
                vector<int>vec=ans[k];
                for(int j=0;j<vec.size();j++){
                    v[j]+=vec[j];
                    v[j+1]+=vec[j];
                }
                ans.push_back(v);
                k++;
            }
        }
        return ans;
    }
};