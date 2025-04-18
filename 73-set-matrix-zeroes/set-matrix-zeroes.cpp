class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int>row, col;
        int n=matrix.size(),m=matrix[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for(auto it=row.begin();it!=row.end();it++){
            for(int j=0;j<m;j++){
                matrix[*it][j]=0;
            }
        }

        for(auto it=col.begin();it!=col.end();it++){
            for(int i=0;i<n;i++){
                matrix[i][*it]=0;
            }
        }

    }
};