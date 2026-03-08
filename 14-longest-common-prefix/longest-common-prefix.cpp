class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int i=0, n=strs.size();
        bool run = true;
        while(run){
            for(int j=0;j<n;j++){
                int m = strs[j].size();
                if(i<m){
                    if(j==0){continue;}
                    else if(strs[0][i] == strs[j][i]){
                    
                    }
                    else{
                        run = false;break;
                    }
                }
                else{
                    run = false;break;
                }
            }
            if(run==true){
                ans.push_back(strs[0][i]);i++;
            }
        }
        return ans;
    }
};