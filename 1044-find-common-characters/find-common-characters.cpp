class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(int i=0;i<words[0].size();i++){
            int j=1,k=words.size()-1;
            bool has=true;
            while(j<=k){
                int already=0;
                int ji = words[j].find(words[0][i]);
                if(words[j].find(words[0][i]) == string::npos){
                    has=false;
                }
                else{
                    words[j].erase(ji,1);already=1;
                }
                
                j++;
            }
            if(has){
                string s="";
                s+=words[0][i];
                ans.push_back(s);
                
            }
        }
        return ans;
    }
};