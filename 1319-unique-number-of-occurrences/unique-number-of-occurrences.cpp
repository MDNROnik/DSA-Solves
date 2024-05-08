class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int>mp;
        map<int,int>::iterator it,it2;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(it=mp.begin();it!=mp.end();it++){
            int num=0;
            for(it2=mp.begin();it2!=mp.end();it2++){
                if(it->second == it2->second){num++;}
            }
            if(num!=1){return false;}
        }
        return true;
    }
};