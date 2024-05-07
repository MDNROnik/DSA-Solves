class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int arr[1000] = {0};
        int count=0;

        for(int i=0;i<stones.size();i++){
            arr[stones[i]]++;
        }
        for(int i=0;i<jewels.size();i++){
            count+=arr[jewels[i]];
        }
        return count;
    }
};