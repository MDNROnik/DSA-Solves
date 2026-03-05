class Solution {
public:
    vector<int> getConcatenation(vector<int>& v1) {
        v1.insert(v1.end(), v1.begin(), v1.end());
        return v1;
    }
};