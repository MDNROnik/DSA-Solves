class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int me = (abs(0-target[0]) + abs(0-target[1]) );


        int you=INT_MAX;
        int n=ghosts.size();
        for(int i=0;i<n;i++){

            int now = (abs(ghosts[i][0]-target[0]) + abs(ghosts[i][1]-target[1]) );

            you = min(you,now);
        }
        cout<<you<<" "<<me<<endl;
        return (you>me);
    }
};