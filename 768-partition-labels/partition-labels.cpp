class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int>v(30,-1);
        int n = s.size();
        for(int i=0;i<n;i++){
            int index = s[i];
            index-=97;
            v[index] = i; 
        }
        vector<int>ans;
        for(int i=0;i<n;){
            int j = i;
            int maxIndex=i;
            int count=0;
            while(j<=maxIndex && j<n){
                int index = s[j];
                index-=97;
                maxIndex= max(maxIndex, v[index]);
                count++;
                j++;
            }
            cout<<count<<" "<<j<<endl;
            i=j;
            ans.push_back(count);
        }
        return ans;
    }
};