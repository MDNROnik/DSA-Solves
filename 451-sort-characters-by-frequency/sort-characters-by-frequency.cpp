class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto a=mp.begin();a!=mp.end();a++){
            pq.push({a->second,a->first});
        }
        string str;
        while(pq.size()>0){
            int count = pq.top().first;
            while(count--){
                str.push_back(pq.top().second);
            }
            pq.pop();
        }
        return str;
        
    }
};