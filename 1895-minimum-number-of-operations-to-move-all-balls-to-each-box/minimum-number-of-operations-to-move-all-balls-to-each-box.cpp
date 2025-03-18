class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>pre(n, 0);
        int count=0, steps=0;
        for(int i=0;i<n;i++){
            steps+=count;
            if(boxes[i]=='1'){
                count++;
            }
            pre[i] = (steps);
        }
        count=0, steps=0;
        for(int i=n-1;i>=0;i--){
            steps+=count;
            if(boxes[i]=='1'){
                count++;
            }
            pre[i] = (pre[i]+steps);
        } 
        return pre;
    }
};