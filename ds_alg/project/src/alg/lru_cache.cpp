#include <unordered_map>
#include <list>
#include <iostream>

// The maximum size of the queue will be equal to the total number of frames available (cache size). 
// The most recently used pages will be near front end and least recently pages will be near the rear end.

class LRUCache {

    private:
        std::list<std::pair<int, int>> cache_;
        int capacity_;
        std::unordered_map<int, std::list<std::pair<int, int>>::iterator> hash_;
    public:
        explicit LRUCache(int capacity);
        void put (int key, int value);
        int get (int key);
};

LRUCache::LRUCache(int capacity) : capacity_(capacity) {std::cout << "cache size at the beginning: " << cache_.size() << '\n'; }

void LRUCache::put(int key, int value) {

    if (cache_.size() == capacity_) {

        std::pair<int, int> item = cache_.back();
        std::cout << "deleted value: " << item.second << '\n';
        cache_.pop_back();
        hash_.erase(item.first);
    }

    if (hash_.find(key) != hash_.end()) {

        cache_.erase(hash_.at(key));
    }

    cache_.emplace_front(std::pair<int, int>({key, value}));
    hash_.emplace(std::pair<int, std::list<std::pair<int, int>>::iterator>(key,cache_.begin()));    
}


int LRUCache::get(int key) {

    if (hash_.find(key) == hash_.end()) {

        return -1;
    }

    std::list<std::pair<int, int>>::iterator it = hash_.at(key);

    std::pair<int, int> value = *it;
    cache_.erase(it);

    cache_.emplace_front(value);
    hash_.emplace(std::pair<int, std::list<std::pair<int, int>>::iterator>(key, cache_.begin()));

    return value.second;
}

int main() {

    LRUCache *cache = new LRUCache(1);

    cache->put(2,1);
    std::cout << "key 2: " << cache->get(2) << '\n';
    cache->put(3,2);
    std::cout << "key 2: " << cache->get(2) << '\n';
    std::cout << "key 3: " << cache->get(3) << '\n';

/*
    cache->put(1, 1);
    cache->put(2, 2);
    cache->put(3, 3);
    cache->put(4, 4);
    cache->put(5, 5);
    cache->put(6, 6);
    cache->put(7, 7);
    cache->put(8, 8);
    cache->put(9, 9);
    cache->put(10, 10);
    cache->put(11, 11);
    cache->put(12, 12);
    */
}

