class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        map<int,vector<int>>max;
        map<int,vector<int>>targets;
        bool ans = true;
        int n = triplets.size();
        for(int j=0;j<3;j++){
            for(int i=0;i<n;i++){
                if(target[j]<triplets[i][j]){
                    max[i].push_back(target[j]);
                }
            }
        }
        vector<vector<int>> v = {{}, {}, {}};
        for(int j=0;j<3;j++){
            bool now = false;
            for(int i=0;i<n;i++){
                if( target[j] == triplets[i][j]  ){
                    if( max[i].size()==0 ){
                        v[j].push_back(i);
                    }
                    else{
                    }
                }
            }
        }
        if(v[0].size()>0 && v[1].size()>0 && v[2].size()>0){
            return true;
        }
        else{
            return false;
        }
    }
};