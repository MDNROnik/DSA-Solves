
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string>v{".-","-...","-.-.","-..",".","..-.","--.","....",
                     "..",".---","-.-",".-..","--","-.","---",".--.",
                     "--.-",".-.","...","-","..-","...-",".--","-..-",
                     "-.--","--.."};
        
        map<string,int>mp;
        for(int i=0;i<words.size();i++){
            string str="";
            for(int j=0;j<words[i].size();j++){
                int now = words[i][j];
                now-=97;
                //cout<<v[now]<<endl;
                str+=v[now];
            }
            //cout<<str<<endl;
            mp[str];
        }
        
        return mp.size();
    }
};