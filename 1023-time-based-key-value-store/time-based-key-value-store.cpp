#include <bits/stdc++.h>

class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>>mp;
    TimeMap() { }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto& v = mp[key] ;
        int r=v.size()-1;
        int l=0;
        //sort(v.begin(),v.end());
        string ans = "";
        while(l<=r){
            int mid = l + (r-l)/2;
            if(v[mid].first==timestamp){
                return v[mid].second;
            }
            else if(v[mid].first>timestamp){
                r=mid-1;
            }
            else{
                ans=v[mid].second;
                l=mid+1;
            }
        }
        
        return ans;
    }
};

// class TimeMap {
// private:
//     unordered_map<string, vector<pair<int, string>>> keyStore;

// public:
//     TimeMap() {}

//     void set(string key, string value, int timestamp) {
//         keyStore[key].emplace_back(timestamp, value);
//     }

//     string get(string key, int timestamp) {
//         auto& values = keyStore[key];
//         int left = 0, right = values.size() - 1;
//         string result = "";

//         while (left <= right) {
//             int mid = left + (right - left) / 2;
//             if (values[mid].first <= timestamp) {
//                 result = values[mid].second;
//                 left = mid + 1;
//             } else {
//                 right = mid - 1;
//             }
//         }

//         return result;
//     }
// };
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */