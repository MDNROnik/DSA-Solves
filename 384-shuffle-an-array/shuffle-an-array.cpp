class Solution {
public:
    vector<int>o,r;
    Solution(vector<int>& nums) {
        o=nums;
        r=nums;
    }
    
    vector<int> reset() {
        return o;
    }
    
    vector<int> shuffle() {
        
        int i=0;
        do {
            if(i==1){break;}
            i++;
        }while (next_permutation(r.begin(), r.end()));
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */