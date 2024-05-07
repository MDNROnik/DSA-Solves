class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto it=mp.begin();it!=mp.end();it++)
        {
            pq.push({make_pair(it->second,it->first)});   
        }
        int count=0,currsize=0;
        while(!pq.empty())
        {
            pair<int,int> p=pq.top();
            pq.pop();
            
            int ele = p.second;
            int freq = p.first;
            //cout<<ele<<" "<<freq<<endl;
            
            count=count+1;
                
            currsize = currsize + freq;
        
            if(currsize >= (n/2))
            {
                return count;    	
            }	
        }
        return count;
    }
};