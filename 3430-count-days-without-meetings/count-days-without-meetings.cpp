class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        int n=meetings.size(), ans = 0;
        map<int, int>mp;
        for(int i=0;i<n;i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            mp[start]++;
            mp[end]--;
        }
        int start = -1, end = -1, now=0;
        for(auto a=mp.begin();a!=mp.end();a++){
            if(now==0){
                start=a->first;
            }
            now+=a->second;
            if(now==0){
                end=a->first;
                ans+=((end-start)+1);
            }
        }
        return days - ans;
    }
};