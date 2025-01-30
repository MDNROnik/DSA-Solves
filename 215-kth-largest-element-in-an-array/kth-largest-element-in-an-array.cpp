class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        k-=1;
        while(k>=1){
            cout<<k<<endl;
            pq.pop();k--;
        }
        return pq.top();
    }
};