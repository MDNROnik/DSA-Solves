class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int>ans;
        ans.push_back(first);
        int n=encoded.size();
        // a = b^c
        // a^c = b
        // a^b = c 
        for(int i=0;i<encoded.size();i++){
            ans.push_back(ans.back()^encoded[i]);
        }
        return ans;
    }
};