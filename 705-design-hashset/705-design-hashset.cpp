class MyHashSet {
public:
    vector<int>val;
    
    MyHashSet() {
       
    }
    
    void add(int key) {
        
        val.push_back(key);
        
    }
    
    void remove(int key) {
        
        for(int i=0;i<val.size();i++){
            if(val[i]==key){
                val.erase(val.begin()+i);
            }
        }
        if(contains(key))
            remove(key);
    }
    
    bool contains(int key) {
        for(int i=0;i<val.size();i++){
            if(key == val[i])
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