class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<double, int>mp;
        long long ans = 0;
        int n = rectangles.size();
        for(int i=0;i<n;i++){
            double d = double(double(rectangles[i][0]) / double(rectangles[i][1]));
            // cout<<rectangles[i][0]<<" "<<rectangles[i][1]<<" "<<endl;
            // cout << setprecision(15) << d << endl;
            mp[d]++;
        }
        for(auto a=mp.begin();a!=mp.end();a++){
            long long now = a->second-1;
            now = (now*(now+1))/2;
            ans+=now;
        }
        return ans;
    }
};