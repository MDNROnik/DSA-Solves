class Solution {
public:
    vector<int> getConcatenation(vector<int>& v) {
        v.insert(v.end(), v.begin(), v.end());
        return v;
    }
};