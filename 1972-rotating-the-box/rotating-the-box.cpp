class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int row = boxGrid.size();
        int col = boxGrid[0].size();
        vector<vector<char>> ans;
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         cout<<boxGrid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i=0;i<row;i++){
            int gap=col-1;
            while(gap>0 ){
                // cout<<gap<<" "<<boxGrid[i][gap]<<endl;
                if(boxGrid[i][gap]=='.'){
                    int now = gap-1;
                    int in=0;
                    while(now>=0){
                        if(boxGrid[i][now]=='*'){
                            // cout<<i<<" 1 "<<gap<<" "<<now<<endl;
                            in++;gap=now-1;break;
                        }
                        else if(boxGrid[i][now]=='#'){
                            // cout<<i<<" 2 "<<gap<<" "<<now<<endl;
                            swap(boxGrid[i][gap], boxGrid[i][now]);
                            in++;gap=gap;break;
                        }
                        now--;
                    }
                    // cout<<in<<endl;
                    if(in==0){
                        gap--;
                    }
                }
                else{
                    gap--;
                }
            }
        }
        // for(int i=0;i<row;i++){
        //     for(int j=0;j<col;j++){
        //         cout<<boxGrid[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<col;i++){
            vector<char>v;
            for(int j=row-1;j>=0;j--){
                v.push_back(boxGrid[j][i]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};