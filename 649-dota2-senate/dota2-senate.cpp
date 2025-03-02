class Solution {
public:
    string predictPartyVictory(string senate) {
        while(1){
            cout<<senate<<endl;
            int n = senate.size();
            // if(n==1){
            //     if(senate[0]=='R'){
            //         return "Radiant";
            //     }
            //     else{
            //         return "Dire";
            //     }
            // }
            string now = "";
            int r=0, d=0, remove = 0;
            for(int i=0;i<n;i++){
                if(senate[i]=='R'){
                    if(d>0){
                        d--;remove=1;
                    }
                    else{
                        r++;now.push_back('R');remove=2;
                    }
                }
                else if(senate[i]=='D'){
                    if(r>0){
                        r--;remove=1;
                    }
                    else{
                        d++;now.push_back('D');remove=2;
                    }
                }
            }
            string remainR="";
            string remainD="";
            int nowR=r, nowD=d;
            // cout<<r<<" "<<d<<endl;
            while(nowR>0){
                nowR--;
                now.pop_back();
                now.insert(0, "R");
            }
            while(nowD>0){
                nowD--;
                now.pop_back();
                now.insert(0, "D");
            }
            if(r==n){
                return "Radiant";
            }
            if(d==n){
                return "Dire";
            }
            
            senate = now;
        }
    }
};