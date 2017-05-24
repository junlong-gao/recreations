class LRUCache {
    struct bucket_t {
        int k, v;
    };
    unordered_map<int, list<bucket_t>::iterator> lk;
    list<bucket_t> data;
    int cap;
        
public:
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (lk.count(key) == 0) {
            return -1;
        }
        int ret = lk[key]->v;
        data.erase(lk[key]);
        data.push_front(bucket_t{key, ret});
        lk[key] = data.begin();
        return ret;
    }
    
    void put(int key, int value) {
        if (lk.count(key)) {
            data.erase(lk[key]);
            data.push_front(bucket_t{key, value});
            lk[key] = data.begin();
            return;
        }
        
        if (cap == data.size()) {
            lk.erase(data.back().k);
            data.pop_back();
        }
        
        data.push_front(bucket_t{key, value});
        lk[key] = data.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
