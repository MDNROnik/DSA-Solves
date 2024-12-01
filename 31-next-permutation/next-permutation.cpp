class Solution {
public:
    void nextPermutation(vector<int>& v) {
        vector<int>v2=v;
        while (next_permutation(v.begin(), v.end())){
            break;
            for(int i=0;i<v.size();i++){
                cout<<v[i]<<" ";

            }
            cout<<endl;
        }
    }
};