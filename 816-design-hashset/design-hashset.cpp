int n = 1000000;
// vector<bool>hash_set(n, false);
map<int,bool>hash_set;
class MyHashSet {
public:
    MyHashSet() {
        hash_set.clear();
    }
    
    void add(int key) {
        hash_set[key] = true;
    }
    
    void remove(int key) {
        hash_set[key] = false;
    }
    
    bool contains(int key) {
        if(hash_set[key]){
            return true;
        }
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */