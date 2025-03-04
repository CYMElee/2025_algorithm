class LRUCache {
private:
    struct Node {
        int key, value;
        Node(int k, int v) : key(k), value(v) {}
    };

    int capacity;
    std::list<Node> cacheList;  
    std::unordered_map<int, std::list<Node>::iterator> cacheMap;

    void moveToHead(std::list<Node>::iterator it) {
        cacheList.splice(cacheList.begin(), cacheList, it);
    }

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key) {
        auto it = cacheMap.find(key);
        if (it == cacheMap.end()) return -1; 

        moveToHead(it->second);
        return it->second->value;
    }

    void put(int key, int value) {
        auto it = cacheMap.find(key);
        if (it != cacheMap.end()) {
            it->second->value = value;
            moveToHead(it->second);
            return;
        }

        if (cacheList.size() >= capacity) { 
            cacheMap.erase(cacheList.back().key);
            cacheList.pop_back();
        }

        cacheList.emplace_front(key, value);
        cacheMap[key] = cacheList.begin();
    }
};
