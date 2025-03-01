#include "LRUCache.hpp"

LRUCache::LRUCache(int capacity){
    LRUCache::capacity_= capacity;
}

void LRUCache::put(int key, int value){
    auto it = m_.find(key);
        if(it!=m_.end()){
            it->second->second = value;
            cache_.splice(cache_.begin(),cache_,it->second);
            return;
        }

        if(cache_.size()== capacity_){
            auto last = cache_.back();
            m_.erase(last.first);
            cache_.pop_back();

        }
        cache_.emplace_front(key,value);
        m_[key] = cache_.begin();

}


int LRUCache::get(int key){
    auto it = m_.find(key);

    if(it==m_.end()){
        return -1;
    }

    cache_.splice(cache_.begin(),cache_,it->second);
    return it->second->second;

}