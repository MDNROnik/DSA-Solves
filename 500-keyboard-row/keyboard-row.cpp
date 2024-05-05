class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string>vs;
        vs.push_back("qwertyuiop");
        vs.push_back("asdfghjkl");
        vs.push_back("zxcvbnm");
        vector<string>ans;
        int n=words.size();
        for(int i=0;i<n;i++){

            string s = words[i];

            for(int j=0;j<vs.size();j++){
                string str = vs[j];
                int count=0;
                for(int k=0;k<s.size();k++){
                    for(int l =0;l<str.size();l++){
                        if(tolower(s[k])==str[l]){
                            count++;
                        }
                        if(count==s.size()){
                            break;
                        }
                    }
                }
                if(count==s.size()){
                    ans.push_back(s);
                    break;
                }
            }
        }
        return ans;
    }
};