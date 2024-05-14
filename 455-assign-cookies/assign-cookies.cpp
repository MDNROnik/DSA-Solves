class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int total=0;
        int n=g.size();
        int m=s.size();
        for(int i=0,j=0;i<n && j<m;){
            if(g[i]<=s[j]){
                i++,j++;total++;
            }
            else{
                j++;
            }
        }
        return total;
    }
};