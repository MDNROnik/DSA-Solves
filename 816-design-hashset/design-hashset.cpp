class MyHashSet {
public:
    vector<int> v;

    MyHashSet() {
        v = vector<int>(1000010, 0);
    }
    
    void add(int key) {
        v[key]=1;
        return;
    }
    
    void remove(int key) {
        v[key]=0;
        return;
    }
    
    bool contains(int key) {
        cout<<v[key]<<endl;
        return v[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */