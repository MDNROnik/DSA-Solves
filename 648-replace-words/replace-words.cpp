class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans="";
        unordered_set<string>s(dictionary.begin(),dictionary.end());
        string x="";
        for(int i=0;i<sentence.size();)
        {
            if(sentence[i]==' ')
            {
                ans+=x;
                ans+=' ';
                x="";
            }
            else
            {
                x+=sentence[i];
                if(s.find(x)!=s.end())
                {
                    while(i<sentence.size() && sentence[i]!=' ')
                    {
                        i++;
                    }
                    ans+=x;
                    
                    x="";
                    continue;
                }
            }
            i++;
        }
        if(x.size()!=0)ans+=x;
        return ans;
    }
};