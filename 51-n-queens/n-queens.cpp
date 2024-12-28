class Solution {
public:
    bool check(vector<string> &ans, int siz, int row, int col){
        //col
        if( row>=siz ){return false;}
        int cnt = 0,cnt2=0;;
        for(int i=0;i<siz;i++){
            if(ans[row][i]=='Q'){cnt++;}
            if(cnt==2){
                return false;
            }
            if(ans[i][col]=='Q'){cnt2++;}
            if(cnt2==2){
                return false;
            }
        }
        //row
        cnt=0;
        // for(int i=0;i<siz;i++){
        //     if(ans[i][col]=='Q'){cnt++;}
        //     if(cnt==2){
        //         return false;
        //     }
        // }

        //dia
        cnt=0;
        int i, j;
        i=row, j=col;
        while(i>=0 && j>=0){
            if(ans[i][j]=='Q'){cnt++;}
            if(cnt==2){
                return false;
            }
            i--;j--;
        }
        //dia
        cnt=0;
        i=row, j=col;
        while(i<siz && j<siz){
            if(ans[i][j]=='Q'){cnt++;}
            if(cnt==2){
                return false;
            }
            i++;j++;
        }
        //dia
        cnt=0;
        i=row, j=col;
        while(i>=0 && j<siz){
            if(ans[i][j]=='Q'){cnt++;}
            if(cnt==2){
                return false;
            }
            i--;j++;
        }
        //dia
        cnt=0;
        i=row, j=col;
        while(i<siz && j>=0){
            if(ans[i][j]=='Q'){cnt++;}
            if(cnt==2){
                return false;
            }
            i++;j--;
        }
        //cout<<" HELLO "<<endl;
        


        return true;
    }
    bool fun(vector<vector<string>> &a, vector<string> &ans, int i, int j, int n, int siz){
        
        // for(int k=0;k<siz;k++){
        //     for(int l=0;l<siz;l++){
        //         cout<<ans[k][l]<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        if(n<=0){
            cout<<11<<endl;
            a.push_back(ans);
        }
        if( i>=siz ){return false;}
        
        
        for(int col=0;col<siz;col++){
            ans[i][col] = 'Q';
            if( check(ans, siz, i, col)==false ){
                ans[i][col]='.';
                continue;
            }
            fun(a, ans, i+1, col, n-1, siz); 
            ans[i][col]='.';
        }

        return false;
    }
    vector<vector<string>> solveNQueens(int n) {
        string s (n,'.');
        vector<string> ans (n, s);
        
        vector<vector<string>> a;
        fun(a,ans, 0, 0, n, n);
        
        return a;
    }
};