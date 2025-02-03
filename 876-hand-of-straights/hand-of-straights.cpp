class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0){
            return false;
        }
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[hand[i]]++;
        }
        bool ans=true;
        while(ans==true){
            int now = groupSize;
            int lastValue=mp.begin()->first;
            cout<<lastValue<<endl;
            // for(auto a=mp.begin();a!=mp.end();a++){
            //     cout<<a->first<<" "<<a->second<<endl;
            // }
            lastValue-=1;
            for(auto a=mp.begin();a!=mp.end();a++){
                if(now==0){
                    break;
                }
                else{
                    if( abs(a->first-lastValue)!=1){
                        ans=false;break;
                    }
                    lastValue=a->first;
                    a->second-=1;now--;
                    if(a->second==0){
                        mp.erase(a->first);
                    }
                }
            }  
            cout<<now<<" "<<mp.size()<<endl;
            if(now>0 && mp.size()<groupSize){
                ans=false;
            }  
            else if(now==0 && mp.size()==0){
                break;
            }
        }
        return ans;
    }
};