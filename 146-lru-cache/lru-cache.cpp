class LRUCache {
public:
    vector<pair<int,int>>v; // value, current
    int siz=0;
    int curadd=0;
    int nowdelete=0;
    int now=0;
    vector<int> least;
public:
    LRUCache(int capacity) {
        siz=capacity;
        for(int i=0;i<=10005;i++){
            v.push_back({-1,-1});
        }
    }
    
    int get(int key) {
        if(v[key].first==-1){
            return v[key].first;
        }
        least.push_back(key);
        curadd+=1;
        v[key].second=curadd;
        return v[key].first;
    }
    
    void put(int key, int value) {
        if(v[key].first!=-1){
            least.push_back(key);
            curadd+=1;
            v[key]={value,curadd};
            return;
        }
        siz-=1;
        if(siz>=0){

            least.push_back(key);
            curadd+=1;
            v[key]={value,curadd};
        }
        else{
            
            int n=least.size();
            //cout<<key<<" "<<value<<endl;
            for(;now<n;){
                if( (v[least[now]].second == -1) ||  v[least[now]].second != now+1 ){
                    now++;
                }
                else{
                    break;
                }
            }
            //cout<<now<<" HELLO "<<least[now]<<endl;
            v[ least[now] ] = {-1,-1}; now+=1;
            least.push_back(key);
            curadd+=1;
            v[key]={value,curadd};
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */