#define ll long long
class Solution {
public:
    void fun(vector<vector<int>> &heights, map<pair<int,int>, pair<bool, vector<ll>>> &mp, int n, int m, int i, int j){
        if(mp[{i,j}].first==true){
            auto b = mp[{i,j}].second;
           
            return;
        }

        mp[{i, j}].first = true;

        //right
        if(j+1>=m){
            mp[{i,j}].second[3]=1;
        }
        else if(j+1<m && heights[i][j+1]<=heights[i][j]){
            fun(heights, mp, n, m, i, j+1);
            mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i,j+1}].second[0]   );
            mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i,j+1}].second[1]   );
            mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i,j+1}].second[2]   );
            mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i,j+1}].second[3]   );
        }
        
        //up
        
        if(i-1<0){
            mp[{i,j}].second[0]=1;
        }
        else if(i-1>=0 && heights[i-1][j]<=heights[i][j]){

            fun(heights, mp, n, m, i-1, j);
            mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i-1,j}].second[0]   );
            mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i-1,j}].second[1]   );
            mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i-1,j}].second[2]   );
            mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i-1,j}].second[3]   );
        }

        //Down
        if(i+1>=n){

            mp[{i,j}].second[2]=1;
        }
        else if(i+1<n && heights[i+1][j]<=heights[i][j]){

            fun(heights, mp, n, m, i+1, j);
            mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i+1,j}].second[0]   );
            mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i+1,j}].second[1]   );
            mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i+1,j}].second[2]   );
            mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i+1,j}].second[3]   );

        }

        //left
        if(j-1<0){

            mp[{i,j}].second[1]=1;
        }
        else if(j-1>=0 && heights[i][j-1]<=heights[i][j]){
            fun(heights, mp, n, m, i, j-1);
            mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i,j-1}].second[0]   );
            mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i,j-1}].second[1]   );
            mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i,j-1}].second[2]   );
            mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i,j-1}].second[3]   );

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

                    fun(heights, mp, n, m, i, j);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i-1>=0 && heights[i-1][j]<=heights[i][j]){
                    mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i-1,j}].second[0]   );
                    mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i-1,j}].second[1]   );
                    mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i-1,j}].second[2]   );
                    mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i-1,j}].second[3]   );
                }
                if(i+1<n && heights[i+1][j]<=heights[i][j]){
            mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i+1,j}].second[0]   );
            mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i+1,j}].second[1]   );
            mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i+1,j}].second[2]   );
            mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i+1,j}].second[3]   );
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
                    mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i-1,j}].second[0]   );
                    mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i-1,j}].second[1]   );
                    mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i-1,j}].second[2]   );
                    mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i-1,j}].second[3]   );
                }
                if(i+1<n && heights[i+1][j]<=heights[i][j]){
            mp[{i,j}].second[0] = max( mp[{i,j}].second[0], mp[{i+1,j}].second[0]   );
            mp[{i,j}].second[1] = max( mp[{i,j}].second[1], mp[{i+1,j}].second[1]   );
            mp[{i,j}].second[2] = max( mp[{i,j}].second[2], mp[{i+1,j}].second[2]   );
            mp[{i,j}].second[3] = max( mp[{i,j}].second[3], mp[{i+1,j}].second[3]   );
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

            auto b = a->second.second;

            
            if(b[0]>0 || b[1]>0){
                if(b[2]>0 || b[3]){
                    cnt;ans.push_back({a->first.first, a->first.second});
                }
            }


        }


        return ans;
    }
};