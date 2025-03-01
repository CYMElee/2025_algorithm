#ifndef LRUCACHE_H
#define LRUCACHE_H


#include <list>
#include <unordered_map>
#include <utility>

class LRUCache
{
private:
    int capacity_;
    std::list<std::pair<int, int>> cache_;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_; 
    
public:
    LRUCache(int capacity);
    void put(int key,int value);
    int get(int key);

};

#endif 