class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<pair<int,int>>vp;

        for(int i=0;i<nums.size();i++){
            vp.push_back({nums[i], i});
        }

        sort(vp.begin(), vp.end());

        int count=0, current = vp[0].first;

        for(int i=0;i<vp.size();i++){
            cout<<vp[i].first<<" "<<vp[i].second<<endl;
            if(vp[i].first != current){
                cout<<"IN 1"<<endl;
                // count++;
                nums[vp[i].second]=i;
                current = vp[i].first;
                count=i;
            }
            else{
                cout<<"IN 2"<<endl;
                nums[vp[i].second]=count;
            }
            cout<<endl;
        }

        return nums;

    }
};