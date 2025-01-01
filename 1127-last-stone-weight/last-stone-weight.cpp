class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        int n = stones.size();
        for(int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int x = pq.top();pq.pop();
            int y = pq.top();pq.pop();
            if(x==y){
                n-=2;
                continue;
            }
            else{
                n-=1;
                x-=y;
                pq.push(x);
            }
        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();
    }
};