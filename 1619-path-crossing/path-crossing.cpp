class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<int,int>, bool>mp;
        int n=path.size();
        int i=0, j=0;
        mp[{0,0}]=true;
        for(int k=0;k<n;k++){
            if(path[k]=='N'){i++;}
            if(path[k]=='S'){i--;}
            if(path[k]=='E'){j++;}
            if(path[k]=='W'){j--;}
            cout<<i<<" "<<j<<endl;
            cout<<mp[{i, j}]<<endl;
            if(mp[{i,j}]==false){
                mp[{i,j}]=true;
            }
            else{
                return true;
            }
        }
        return false;
    }
};