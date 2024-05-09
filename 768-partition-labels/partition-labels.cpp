class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,pair<int,pair<int,int>>>mp;
        vector<int>ans;

        int n=s.size();
        for(int i=0;i<n;i++){
            //cout<<mp[s[i]].second.first<<endl;
            if(mp[s[i]].first == 0){
                //cout<<s[i]<<endl;
                mp[s[i]].first = 1;
                mp[s[i]].second={i,i};
            }
            else{
                mp[s[i]].second.second=i;
            }
        }
        // vector< pair<int,int> >v;
        // for(auto a=mp.begin();a!=mp.end();a++){
        //     //cout<<a->first<<" "<<a->second.second.first<<"  "<<a->second.second.second<<endl;
        //     v.push_back({ a->second.second.second , a->second.second.first });
        // }
        // sort(v.begin(),v.end());
        // n=v.size();
        // int remain=0;
        // for(int i=0;i<n;i++){
        //     remain=v[i].first;
        //     for(int j=i;j<n;j++){
        //         if(v[j].first >= v[j].second){

        //         }
        //     }
        // }

        int low = mp[s[0]].second.first;
        int high = mp[s[0]].second.second;
        int count=0;
        for(int i=0;i<n;i++){
            count+=1;
            int l = mp[s[i]].second.first;
            int h = mp[s[i]].second.second;
            cout<<i<<endl;
            cout<<low<<" "<<high<<" "<<count<<endl;
            cout<<s[i]<<" "<<l<<" "<<h<<endl<<endl;;
            if(high==h && count==(high-low+1)){
                ans.push_back(high-low+1);
                if(i+1<n){
                    low = mp[s[i+1]].second.first;
                    high = mp[s[i+1]].second.second;
                    count=0;
                }
                else{
                    break;
                }
            }
            else if(high<h){
                high=h;
            }
            else{
                continue;
            }
        }


        return ans;
    }
};