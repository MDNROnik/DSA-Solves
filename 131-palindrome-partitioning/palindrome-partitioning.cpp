class Solution {
public:
    bool p(string &temp){
        string str = temp;
        reverse(str.begin(),str.end());
        return temp==str;
    }
    void fun(vector<vector<string>> &ans, vector<string> &now, string s){
        for(int i=0;i<now.size();i++){
            cout<<now[i]<<" - ";
        }
        cout<<s<<endl;
        int n=s.size();
        if(n==0){
            //cout<<111<<endl;
            // ans.push_back(now);
            return ;
        }
        for(int i=1;i<n;i++){
            string temp = s.substr(0,i);
            if(p(temp)){
                //cout<<s<<" "<<temp<<endl;
                now.push_back(temp);
                //cout<<s<<endl;
                string sub = s.substr((i-1) + 1);
                //cout<<sub<<endl<<endl;
                // if(sub.empty()){
                //     cout<<1111<<endl;
                // }
                //cout<<sub<<endl;
                fun(ans, now, sub);
                if(p(sub)){
                    now.push_back(sub);
                    ans.push_back(now);
                    now.pop_back();
                }
                now.pop_back();
            }
            
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        //fun(ans, s, n);
        for(int i=1;i<n;i++){
            string temp = s.substr(0,i);
            //cout<<temp<<" "<<i<<endl;
            if(p(temp)){
                vector<string> now;now.push_back(temp);
                string sub = s.substr((i-1) + 1);
                cout<<temp<<" -> "<<sub<<endl;
                fun(ans, now, sub);
                if(p(sub)){
                    now.push_back(sub);
                    ans.push_back(now);
                }
            }
        }
        if(p(s)){
            vector<string>v;v.push_back(s);
            ans.push_back(v);
        }
        return ans;
    }
};