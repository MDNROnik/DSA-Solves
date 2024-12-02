class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        vector<int>v,vec;
        sort(intervals.begin(),intervals.end());

        for(int i=0;i<intervals.size();i++){
            v.push_back(intervals[i][0]);
            v.push_back(intervals[i][1]);
        }
        v.push_back(INT_MAX);
        v.push_back(INT_MAX);

        vec.push_back(v[0]);
        int cur=v[1];
        for(int i=2;i<v.size();){
            cout<<cur<<" "<<v[i+1]<<endl;
            if(v[i]<=cur && v[i+1]>=cur){
                cur=v[i+1];
                i=i+2;
            }
            else if(v[i+1]<=cur){
                i=i+2;
            }
            else{
                vec.push_back(cur);
                vec.push_back(v[i]);
                cur=v[i+1];
            }
        }
        // for(int i=0;i<vec.size();i++){
        //     cout<<vec[i]<<" ";
        // }
        // cout<<endl;


        // cout<<vec.size()<<endl;
        for(int i=0;i<vec.size();i=i+2){
            if(i+1>=vec.size()){break;}
            vector<int>a;
            a.push_back(vec[i]);
            a.push_back(vec[i+1]);
            ans.push_back(a);
        }
        //cout<<endl;

        
        return ans;
    }
};