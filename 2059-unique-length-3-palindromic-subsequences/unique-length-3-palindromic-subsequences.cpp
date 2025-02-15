class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<vector<int>>vec;
        vector<int>v(26, 0);
        int n = s.size();
        vector<vector<int>>index(26, vector<int>(2, -1));
        for(int i=0;i<n;i++){
            int now = (int)s[i];
            now-=97;
            v[now]++;
            vec.push_back(v);
            if(index[now][0]==-1){
                index[now][0]=i;
            }
            index[now][1]=i;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            int left = index[i][0];
            int right = index[i][1];
            if(left==-1){continue;}
            int count=0;

            for(int j=0;j<26;j++){
                if( (vec[right][j]-vec[left][j]) >=1  && vec[right][j]==2 && j==i){
                }
                else if( (vec[right][j]-vec[left][j]) >=1 ){
                    count++;
                }
            }
            ans+=count;
        }
        return ans;
    }
};