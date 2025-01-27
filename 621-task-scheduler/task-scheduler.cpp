class Solution {
public:
    int leastInterval(vector<char>& tasks, int m) {
        vector<int>v(26, 0);
        int n=tasks.size();
        for(int i=0;i<tasks.size();i++){
            int ind = tasks[i];
            ind-=65;
            v[ind]++;
        }
        vector<int>count;
        for(int i=0;i<26;i++){
            if(v[i]>0){
                count.push_back(v[i]);
            }
        }
        
        int id=0, ans=0;;
        while(n>0){

            vector<int>c;
            for(int i=0;i<count.size();i++){
                if(count[i]>0){
                    c.push_back(count[i]);
                }
            }
            sort(c.begin(),c.end());
            reverse(c.begin(),c.end());

            if(id!=0 && id<=m){
                ans+=(m-id)+1;
            }
            id=0;
            int i=0;
            
            for(;i<c.size();i++){
                if(c[i]>0){
                    ans++;
                    c[i]--;
                    id++;
                    n--;
                }
                if(id>m){
                    sort(c.begin(),c.end());
                    reverse(c.begin(),c.end());
                    id=0;i=-1;
                }
            }
            count=c;
        }
        return ans;
    }
};