class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int l=0,r=n-1;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(matrix[mid][0] > target){
                r=mid-1;
            }
            else{
                int m=matrix[mid].size();
                if(matrix[mid][m-1] >= target){
                    r=mid;break;
                }
                else{
                    l=mid+1;
                }
            }
        }
        int row=r;
        cout<<row<<endl;
        int m=matrix[0].size();
        if(row<0 || matrix[row][m-1]<target){return false;}
        l=0,r=matrix[row].size();
        while(l<=r){
            cout<<l<<" "<<r<<endl;
            int mid = l+(r-l)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if(matrix[row][mid]<target){
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return false;
    }
};