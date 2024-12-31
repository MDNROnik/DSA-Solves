#define ll long long
class Solution {
public:
    void fun(vector<vector<int>> &heights, map<pair<int,int>, pair<bool, vector<ll>>> &mp, int n, int m, int i, int j){
        if(mp[{i,j}].first==true){
            auto b = mp[{i,j}].second;
            //cout<<i<<" VISITED "<<j<<endl;
            //cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl<<endl;
            return;
        }

        mp[{i, j}].first = true;

        //right
        if(j+1>=m){
           // cout<<"RIGHT Done"<<endl;
            mp[{i,j}].second[3]=1;
        }
        else if(j+1<m && heights[i][j+1]<=heights[i][j]){
           // cout<<i<<" FOR RIGHT "<<j+1<<endl;
            //cout<<heights[i][j+1]<<" values "<<heights[i][j]<<endl;
            fun(heights, mp, n, m, i, j+1);
            auto b = mp[{i,j+1}].second;
            auto a =  mp[{i,j}].second;
            a[0] = max(a[0],b[0]);
            a[1] = max(a[1],b[1]);
            a[2] = max(a[2],b[2]);
            a[3] = max(a[3],b[3]);
            mp[{i,j}].second=a;
            // mp[{i,j}].second[0]+=mp[{i,j+1}].second[0];
            // mp[{i,j}].second[1]+=mp[{i,j+1}].second[1];
            // mp[{i,j}].second[2]+=mp[{i,j+1}].second[2];
            // mp[{i,j}].second[3]+=mp[{i,j+1}].second[3];
        }
        
        //up
        //cout<<i<<" "<<j<<endl;
        if(i-1<0){
            //cout<<" UP Done"<<endl;
            mp[{i,j}].second[0]=1;
        }
        else if(i-1>=0 && heights[i-1][j]<=heights[i][j]){
            //cout<<i-1<<" FOR UP "<<j<<endl;
            //cout<<heights[i-1][j]<<" values "<<heights[i][j]<<endl;
            fun(heights, mp, n, m, i-1, j);
            auto b = mp[{i-1,j}].second;
            auto a =  mp[{i,j}].second;
            a[0] = max(a[0],b[0]);
            a[1] = max(a[1],b[1]);
            a[2] = max(a[2],b[2]);
            a[3] = max(a[3],b[3]);
            mp[{i,j}].second=a;
            // mp[{i,j}].second[0]+=mp[{i-1,j}].second[0];
            // mp[{i,j}].second[1]+=mp[{i-1,j}].second[1];
            // mp[{i,j}].second[2]+=mp[{i-1,j}].second[2];
            // mp[{i,j}].second[3]+=mp[{i-1,j}].second[3];
        }

        //Down
        if(i+1>=n){
            //cout<<"DOWN Done"<<endl;
            mp[{i,j}].second[2]=1;
        }
        else if(i+1<n && heights[i+1][j]<=heights[i][j]){
           // cout<<i+1<<" FOR DOWN "<<j<<endl;
            //cout<<heights[i+1][j]<<" values "<<heights[i][j]<<endl;
            fun(heights, mp, n, m, i+1, j);
            auto b = mp[{i+1,j}].second;
            auto a =  mp[{i,j}].second;
            a[0] = max(a[0],b[0]);
            a[1] = max(a[1],b[1]);
            a[2] = max(a[2],b[2]);
            a[3] = max(a[3],b[3]);
            mp[{i,j}].second=a;
            // mp[{i,j}].second[0]+=mp[{i+1,j}].second[0];
            // mp[{i,j}].second[1]+=mp[{i+1,j}].second[1];
            // mp[{i,j}].second[2]+=mp[{i+1,j}].second[2];
            // mp[{i,j}].second[3]+=mp[{i+1,j}].second[3];
        }

        //left
        if(j-1<0){
           // cout<<"LEFT Done"<<endl;
            mp[{i,j}].second[1]=1;
        }
        else if(j-1>=0 && heights[i][j-1]<=heights[i][j]){
           // cout<<i<<" FOR LEFT "<<j-1<<endl;
            //cout<<heights[i][j-1]<<" values "<<heights[i][j]<<endl;
            fun(heights, mp, n, m, i, j-1);
            auto b = mp[{i,j-1}].second;
            auto a =  mp[{i,j}].second;
            a[0] = max(a[0],b[0]);
            a[1] = max(a[1],b[1]);
            a[2] = max(a[2],b[2]);
            a[3] = max(a[3],b[3]);
            mp[{i,j}].second=a;
            // mp[{i,j}].second[0]+=mp[{i,j-1}].second[0];
            // mp[{i,j}].second[1]+=mp[{i,j-1}].second[1];
            // mp[{i,j}].second[2]+=mp[{i,j-1}].second[2];
            // mp[{i,j}].second[3]+=mp[{i,j-1}].second[3];
        }

        

        
        //cout<<endl;
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //up--left--down--right
        //0   1     2     3
        map<pair<int,int>, pair<bool, vector<ll>>>mp;
        int n=heights.size();
        int m=heights[0].size();
        int mm = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vector<ll> v(4,0); 
                mp[{i,j}].second = v;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                auto a = mp[{i,j}];
                if(1){
                    //cout<<"START"<<endl;
                    //cout<<"START--"<<i<<" "<<j<<endl;
                    //mp[{i,j}].first=true;
                    fun(heights, mp, n, m, i, j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0 && heights[i-1][j]<=heights[i][j]){
                    auto a = mp[{i-1,j}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }
                if(i+1<n && heights[i+1][j]<=heights[i][j]){
                    auto a = mp[{i+1,j}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }

                if(j-1>=0 && heights[i][j-1]<=heights[i][j]){
                    auto a = mp[{i,j-1}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }
                if(j+1<m && heights[i][j+1]<=heights[i][j]){
                    auto a = mp[{i,j+1}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0 && heights[i-1][j]<=heights[i][j]){
                    auto a = mp[{i-1,j}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }
                if(i+1<n && heights[i+1][j]<=heights[i][j]){
                    auto a = mp[{i+1,j}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }

                if(j-1>=0 && heights[i][j-1]<=heights[i][j]){
                    auto a = mp[{i,j-1}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }
                if(j+1<m && heights[i][j+1]<=heights[i][j]){
                    auto a = mp[{i,j+1}].second;
                    auto b = mp[{i,j}].second;
                    b[0]+=a[0]; b[1]+=a[1]; b[2]+=a[2]; b[3]+=a[3]; 
                    mp[{i,j}].second=b;
                }
            }
        }
        
        int cnt=0;
        vector<vector<int>>ans;
        for(auto a=mp.begin();a!=mp.end();a++){
            //cout<<a->first.first<<" "<<a->first.second<<endl;
            auto b = a->second.second;
            // cnt++;ans.push_back({a->first.first, a->first.second});
            
            if(b[0]>0 || b[1]>0){
                if(b[2]>0 || b[3]){
                    cnt;ans.push_back({a->first.first, a->first.second});
                }
            }

           // cout<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<endl<<endl;

        }
        cout<<cnt<<endl;

        return ans;
    }
};