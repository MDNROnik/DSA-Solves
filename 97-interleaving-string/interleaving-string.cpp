class Solution {
public:
    int fun(string &s1, string &s2, string &s3, string &s4 , vector< vector<int> >&vp, int i, int j, int k, int &n, int &m){
        
        if(i==n && j==m ){
            return 1;
        }
        if(i<n && j<m){
            if(vp[i][j] != -1){
                return vp[i][j];
            }
        }

        int ans = 0;
        if(s1[i]==s3[k] && s2[j]==s3[k]){
            //cout<<3<<endl;
            int ans1= fun(s1, s2, s3, s4, vp, i+1, j, k+1, n, m);
            int ans2= fun(s1, s2, s3, s4, vp, i, j+1, k+1, n, m);
            return vp[i][j] = ans1 || ans2;
        }
        else if(s1[i]==s3[k] && i<n){
            //cout<<1<<endl;
            int ans = fun(s1, s2, s3, s4, vp, i+1, j, k+1, n, m);
            return vp[i][j]=ans;
        }
        else if(s2[j]==s3[k] && j<m){
            //cout<<2<<endl;
            int ans = fun(s1, s2, s3, s4, vp, i, j+1, k+1, n, m);
            return vp[i][j]=ans;
        }
        else{
            return vp[i][j] = 0;
        }
        // if(i<n){
        //     s4.push_back(s1[i]);
        //     firstTake = fun(s1, s2, s3, s4, vp, i+1, j, n, m);
        //     s4.pop_back();
        // }
        // if(j<m){
        //     s4.push_back(s2[j]);
        //     secondTake = fun(s1, s2, s3, s4, vp, i, j+1, n, m);
        //     s4.pop_back();
        // }
        // cout<<11111<<endl;
        return 0;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size(), m=s2.size(), o=s3.size();
        if(n+m > o || n+m < o){
            return false;
        }
        vector< vector<int> >vp(n+10, vector<int> (m+10, -1));
        string s4="";

        return fun(s1, s2, s3, s4, vp, 0, 0, 0, n, m);
    }
};