class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int>ans;
        queue<pair<pair<int,int>,char>>q;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==c){
                ans.push_back(0);
                q.push({ {i-1,1},'l' });
                q.push({ {i+1,1},'r' });
            }
            else{
                ans.push_back(INT_MAX);
            }
        }
        while(q.size()>0){
            pair<pair<int,int>,char> p = q.front();
            q.pop();
            pair<int,int> pa=p.first;
            char dir = p.second;
            int index = pa.first, step = pa.second;
            cout<<index<<" "<<step<<" "<<dir<<endl;
            if(index>=0 && index<n){
                ans[index]= min(ans[index],step);
                if(dir=='l'){
                    q.push( { { index-1,step+1}, 'l'} );
                }
                else{
                    q.push( { { index+1,step+1}, 'r'} );
                }
            }
            else{continue;} 
        }
        return ans;
    }
};