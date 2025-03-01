#ifndef LFU_CACHE_HPP
#define LFU_CACHE_HPP

#include <unordered_map>
#include <list>

using namespace std;

struct CacheNode {
    int key;
    int value;
    int freq;
    list<int>::const_iterator it; // 指向頻率列表中的位置
};

class LFUCache {
public:
    LFUCache(int capacity);
    int get(int key);
    void put(int key, int value);

private:
    void touch(CacheNode& node);
    
    int capacity_;
    int min_freq_;
    
    unordered_map<int, CacheNode> n_; // key -> CacheNode
    unordered_map<int, list<int>> l_; // freq -> key list
};

#endif // LFU_CACHE_HPP
