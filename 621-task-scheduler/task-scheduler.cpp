class Solution {
public:
    int leastInterval(vector<char>& tasks, int m) {
        vector<int>v(30, 0);
        int n=tasks.size();
        for(int i=0;i<tasks.size();i++){
            int ind = tasks[i];
            ind-=65;
            v[ind]++;
        }
        if(m==1){
            vector<int>count;
            for(int i=0;i<30;i++){
                if(v[i]>0){
                    count.push_back(v[i]);
                }
            }
            sort(count.begin(),count.end());
            int id=0, ans=0, l=0, r=count.size()-1;

            while(n>0){
                int loop=0;
                while(count[l]==0){
                    l++;
                }
                while(count[r]==0){
                    r--;
                }
                while(l<=r){
                    if(id<=m && id!=0){
                        break;
                    }
                    id++;n--;count[l]--;ans++;
                    if(count[l]==0){l++;}
                    if(l>=r){break;}
                    id++,n--;count[r]--;ans++;
                    if(count[r]==0){r--;}
                }
                if( ((id<=m && count.size()==1) || id<m) && n>0){
                    ans+=(m-id)+1;
                }
                id=0;
                l=0;
                r=count.size()-1;
            }
            return ans;
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

            while(id!=0 && id<=m){
                id++;ans++;
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