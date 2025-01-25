class DetectSquares {
public:
    map<pair<int,int>,int>mp;
    map<pair<pair<int,int>, int>, int> visited;
    int ml=0, mr=0, md=0, mu=0, c=0;
    DetectSquares() {
        mp.clear();
    }
    
    void add(vector<int> point) {
        mp[{point[0],point[1]}]++;
        c++;
        ml = min(ml, point[0]);
        mr = max(mr, point[0]);

        mu = max(mu, point[1]);
        md = min(md, point[1]);
    }
    int count(vector<int> point) {
        if(visited[{{point[0], point[1]}, c}]){
            return visited[{{point[0], point[1]}, c}];
        }
        int ans =0;
        // right
        int step=1;
        for(int i=point[0]+1;i<=mr;i++, step++){
            if(mp[{i, point[1]}]){
                int r =mp[{i, point[1]}];
                //up
                if(mp[ {i, point[1]+step} ]){
                    int u=mp[ {i, point[1]+step} ];
                    if(mp[ {point[0], point[1]+step} ]){
                        int l=mp[ {point[0], point[1]+step} ];
                        ans+=(r*u*l);
                    }
                }
                //down
                if(mp[ {i, point[1]-step} ]){
                    int d=mp[ {i, point[1]-step} ];
                    if(mp[ {point[0], point[1]-step} ]){
                        int l=mp[ {point[0], point[1]-step} ];
                        ans+=(r*d*l);
                    }
                }
            }
        }
        // left
        step=1;
        for(int i=point[0]-1;i>=ml;i--, step++){
            if(mp[{i, point[1]}]){
                int l =mp[{i, point[1]}];
                //up
                if(mp[ {i, point[1]+step} ]){
                    int u=mp[ {i, point[1]+step} ];
                    if(mp[ {point[0], point[1]+step} ]){
                        int r=mp[ {point[0], point[1]+step} ];
                        ans+=(l*u*r);
                    }
                }
                //down
                if(mp[ {i, point[1]-step} ]){
                    int d=mp[ {i, point[1]-step} ];
                    if(mp[ {point[0], point[1]-step} ]){
                        int r=mp[ {point[0], point[1]-step} ];
                        ans+=(l*d*r);
                    }
                }
            }
        }
        return visited[{{point[0], point[1]}, c}]=ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */