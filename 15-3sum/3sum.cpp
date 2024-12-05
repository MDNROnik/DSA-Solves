class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& v) {
        
        set<vector<int>>s;
        sort(v.begin(),v.end());
        int n = v.size();
        for (int i = 0; i < n; i++) {
            int l = i+1, r = n-1;
            if (i > 0 && v[i] == v[i - 1]) continue;

            while (l < r) {
                //cout<<v[i]<<" "<<
                if (v[r] + v[l] + v[i] == 0) {
                    vector<int>a;
                    a.push_back(v[i]);
                    a.push_back(v[l]);
                    a.push_back(v[r]);
                    
                    s.insert(a);
                    l++;
                    r--;
                    
                } else if (v[r] + v[l] + v[i] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        vector<vector<int>> ans(s.begin(), s.end());

        return ans;
    }
};