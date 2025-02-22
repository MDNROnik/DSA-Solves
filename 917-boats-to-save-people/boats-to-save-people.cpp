class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i=0, j=people.size()-1;
        int cnt=0;
        while(i<=j){
            if(i==j){
                cnt++;break;
            }
            if((people[i]+people[j]) <= limit){
                cnt++;i++;j--;
            }
            else{
                cnt++;j--;
            }
        }
        return cnt;
    }
};