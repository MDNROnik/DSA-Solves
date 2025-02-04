class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int>maxi(100010, 0);
        bool ans = true;
        int n = triplets.size();
        for(int j=0;j<3;j++){
            for(int i=0;i<n;i++){
                if(target[j]<triplets[i][j]){
                    maxi[i]++;
                }
            }
        }
        vector<int>v={0,0,0};
        for(int j=0;j<3;j++){
            bool now = false;
            for(int i=0;i<n;i++){
                if( target[j] == triplets[i][j]  ){
                    if( maxi[i]==0 ){
                        v[j]++;
                    }
                    else{
                    }
                }
            }
        }
        if(v[0]>0 && v[1]>0 && v[2]>0){
            return true;
        }
        else{
            return false;
        }
    }
};