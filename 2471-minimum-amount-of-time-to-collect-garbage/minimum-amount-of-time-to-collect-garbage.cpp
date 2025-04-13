class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int ansp = 0, ansg=0, ansm=0;
        int travelp=0, travelg=0, travelm=0;
        for(int i=0;i<n;i++){
            int g=0, p=0, m=0;
            int o=garbage[i].size();
            for(int j=0;j<o;j++){
                if(garbage[i][j]=='G'){g++;}
                if(garbage[i][j]=='P'){p++;}
                if(garbage[i][j]=='M'){m++;}
            }
            if(i==0){
                ansp+=p;
                ansg+=g;
                ansm+=m;
            }
            else{
                travelp+=travel[i-1];
                travelg+=travel[i-1];
                travelm+=travel[i-1];
                if(p>0){
                    ansp+=(p+travelp);
                    travelp=0;
                }
                if(g>0){
                    ansg+=(g+travelg);
                    travelg=0;
                }
                if(m>0){
                    ansm+=(m+travelm);
                    travelm=0;
                }
            }
        }
        // cout<<ansp<<" "<<ansg<<" "<<ansm<<endl;
        int ans=ansp+ansg+ansm;
        return ans;
    }
};