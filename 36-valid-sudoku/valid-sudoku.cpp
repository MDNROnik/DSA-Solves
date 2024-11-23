#define Maximum_Digits 10
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;

        // int i = 4;
        // char c = '0' + i;
        // cout<<c<<endl;

        vector<vector<int>> row(12, vector<int> (12, 0));
        vector<vector<int>> col(12, vector<int> (12, 0));
        vector<vector<int>> box(12, vector<int> (12, 0));
        vector<pair<int,int>>vp;
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    vp.push_back({i,j});
                    continue;
                }

                char num = board[i][j];
                int n = num -'0';
                row[i][n]++;
                col[j][n]++;
                //if(board[i][j]=='5'){cout<<i<<" "<<j<<" "<<n<<endl;}

                int boxi,boxj;
                if(i<=2){boxi=0;}
                else if(i<=5){boxi=3;}
                else if(i<=8){boxi=6;}

                if(j<=2){boxi+=0;}
                else if(j<=5){boxi+=1;}
                else if(j<=8){boxi+=2;}

                box[boxi][n]++;

                if(row[i][n]>1 || col[j][n]>1 || box[boxi][n]>1){return false;}
            }
        }

        // for(int i=0;i<vp.size();i++){
        //     int r = vp[i].first, c = vp[i].second;
        //     int count=0;
        //     for(int j=1;j<=9;j++){

        //         int boxi,boxj;
        //         if(r<=2){boxi=0;}
        //         else if(r<=5){boxi=3;}
        //         else if(r<=8){boxi=6;}

        //         if(c<=2){boxi+=0;}
        //         else if(c<=5){boxi+=1;}
        //         else if(c<=8){boxi+=2;}

        //         if(row[r][j]==0 && col[c][j]==0 && box[boxi][j]==0){
        //             //board[r][c] = '0'+j;
        //             //cout<<r<<" "<<c<<" "<<j<<endl;
        //             row[r][j]=1 , col[c][j]=1 , box[boxi][j]=1;count=1;break;
        //         }
        //     }
        //     if(count==0){
        //         //cout<<r<<" "<<c<<endl;
        //         return false;
        //     }
        // }
        // cout<<11111111<<endl;
        // for(int i=0;i<9;i++){
        //     for(int j=0;j<9;j++){
        //         cout<<board[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<col[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        // for(int i=0;i<10;i++){
        //     for(int j=0;j<10;j++){
        //         cout<<box[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return true;
    }
};