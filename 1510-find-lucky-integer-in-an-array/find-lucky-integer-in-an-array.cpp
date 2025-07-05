class Solution {
public:
    int findLucky(vector<int>& arr) {
        int ans = -1;
        int n=arr.size();
        
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        for(auto i = mp.begin();i!=mp.end();i++){
            if(i->first == i->second){
                ans = i->first;
            }
        }
        return ans;
    }
};