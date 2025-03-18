class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre(n, 0);
        vector<int>suf(n, 0);
        int count=0, steps=0;
        for(int i=0;i<n;i++){
            steps+=count;
            if(boxes[i]=='1'){
                count++;
            }
            pre[i] = (steps);
        }
        vector<int>ans(n,0);
        count=0, steps=0;
        for(int i=n-1;i>=0;i--){
            steps+=count;
            if(boxes[i]=='1'){
                count++;
            }ans[i] = (pre[i]+steps);
            suf[i] = (steps);
        }
        // int j=0;vector<int>ans;
        // for(int i=0;i<n;i++){
        //     ans.push_back(pre[i]+suf[i]);
        // }

        
        return ans;
    }
};