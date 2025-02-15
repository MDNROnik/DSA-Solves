class Solution {
public:
    string removeStars(string s) {
        stack<char>sc;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]!='*'){
                sc.push(s[i]);
            }
            else{
                if(sc.size()==0){

                }
                else{
                    sc.pop();
                }
            }
        }
        int now = sc.size();
        string str(now, ' ');
        while(now--){
            str[now] = sc.top();
            sc.pop();
        }
        return str;
    }
};