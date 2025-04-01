class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int t=0, t2=0;
        int count=0, count2=0;
        while(t<n && t2<m){
            int i=0, j=m-1;
            while(i<j){
                if(grid[t][i]!=grid[t][j]){
                    count++;
                }
                i++;j--;
            }
            i=0, j=n-1;
            while(i<j){
                if(grid[i][t2]!=grid[j][t2]){
                    count2++;
                }
                i++;j--;
            }

            t++, t2++;
        }
        while(t<n){
            int i=0, j=m-1;
            while(i<j){
                if(grid[t][i]!=grid[t][j]){
                    count++;
                }
                i++;j--;
            }
            t++;
        }
        while(t2<m){
            int i=0, j=n-1;
            while(i<j){
                if(grid[i][t2]!=grid[j][t2]){
                    count2++;
                }
                i++;j--;
            }

            t2++;
        }
        return min(count,count2);
    }
};