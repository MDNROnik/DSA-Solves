class Solution {
public:
    void fun(vector<int>&front, vector<int>&back, char c, int &n, string &a, map<int,pair<int,int>>&mp){
        int i=0, j=n-1, count=0, count2=0;
        for(;i<n;i++, j--){
            if(a[i]==c){
                mp[i].first = count;
                count=0;
                front.push_back(i);
            }
            else{
                count++;
            }
            if(a[j]==c){
                // cout<<j<<" UB "<<count2<<endl;
                mp[j].second = count2;
                count2=0;
                back.push_back(j);
            }
            else{
                count2++;
            }
        }
    }
    int maxConsecutiveAnswers(string a, int k) {
        map<int,pair<int,int>>mp;
        int n=a.size();
        int ans =0, t=0, f=0;
        vector<int>front, back;
        for(int i=0;i<n;i++){
            if(a[i]=='T'){t++;}
            else{
                f++;
            }
        }


        //for true
        fun(front, back, 'F', n, a, mp);
        int m=front.size();
        if(m<=k){
            return n;
        }
        for(int i=0;i<m;i++){
            int now = (i+k-1);
            if( now < m){
                // cout<<front[i]<<" "<<front[now]<<endl;
                // cout<<mp[front[i]].first<<" "<<mp[front[now]].second<<endl;
                int first = mp[front[i]].first;
                int second = mp[front[now] ].second;
                int thrid = first+second+(front[now]-front[i]+1);
                ans = max(ans, thrid);
            }
            // cout<<front[i]<<endl;
            // cout<<mp[front[i]].first<<" "<<mp[front[i]].second<<endl;
        }

        //for false
        front.clear();
        back.clear();
        mp.clear();
        fun(front, back, 'T', n, a, mp);
        m=front.size();
        if(m<=k){
            return n;
        }
        for(int i=0;i<m;i++){
            int now = (i+k-1);
            if( now < m){
                // cout<<front[i]<<" "<<front[now]<<endl;
                // cout<<mp[front[i]].first<<" "<<mp[front[now]].second<<endl;
                int first = mp[front[i]].first;
                int second = mp[front[now] ].second;
                int thrid = first+second+(front[now]-front[i]+1);
                ans = max(ans, thrid);
            }
            // cout<<front[i]<<endl;
            // cout<<mp[front[i]].first<<" "<<mp[front[i]].second<<endl;
        }

        
        return ans;
    }
};