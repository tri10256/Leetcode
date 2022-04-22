class MyHashMap {
public:
    
    vector<pair<int,int>>record;
    
    MyHashMap() {
        
    }
    
    bool exist(int key,vector<pair<int,int>>&record){
        
        for(int i=0;i<record.size();i++){
            if(record[i].first == key)
                return true;
        }
        return false;
    }
    void put(int key, int value) {
        if(exist(key,record)){
            for(int i=0;i<record.size();i++){
                if(record[i].first == key){
                   record[i].second = value;
                }
            }
        }
        else
        {
            record.push_back({key,value});
        }
    }
    
    int get(int key) {
        
        for(int i=0;i<record.size();i++){
            if(record[i].first == key)
                return record[i].second;
        }
        return -1;
    }
    
    void remove(int key) {
        
        for(int i=0;i<record.size();i++){
            if(record[i].first == key)
                record.erase(record.begin()+i);
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */