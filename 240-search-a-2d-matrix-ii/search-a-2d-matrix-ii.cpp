class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int s=0;
        int e=matrix.size()-1;
        int mid=s+(e-s)/2;
        while(s<e){
            //cout<<s<<" "<<e<<endl;
            if(matrix[e][0]>target){
                e--;
            }
            if((matrix[s][0] < target) && (matrix[s][matrix[s].size()-1] < target)){
                s++;
            }
            if((matrix[s][0] <= target) && (matrix[s][matrix[s].size()-1] >= target)){
                if((matrix[e][0] <= target) && (matrix[s][matrix[e].size()-1] >= target)){
                    break;
                }
            }
        }
        //cout<<s<<" "<<e<<endl;
        //cout<<"hello"<<endl;
        while(s<=e){
            //cout<<s<<" "<<e<<endl;
            int ss=0;
            int ee=matrix[s].size()-1;
            mid=ss+(ee-ss)/2;
            while(ss<=ee){
                //cout<<ss<<" "<<ee<<" "<<mid<<" "<<s<<endl;
                if(matrix[s][mid]<target){
                    ss=mid+1;
                }
                else if(matrix[s][mid]>target){
                    ee=mid-1;
                }
                else if(matrix[s][mid]==target){
                    return true;
                }
                mid=ss+(ee-ss)/2;
            }
            s++;
        }
        return false;
    }
};