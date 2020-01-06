#include <unordered_map>
#include <list>

// The maximum size of the queue will be equal to the total number of frames available (cache size). 
// The most recently used pages will be near front end and least recently pages will be near the rear end.

class LRUCache {

    private:
        std::list<int> cache_;
        int capacity_;
        std::unordered_map<int, std::list<int>::iterator> hash_;
    public:
        explicit LRUCache(int capacity);
        void put (int key, int value);
        int get (int key);
};

LRUCache::LRUCache(int capacity) : capacity_(capacity) {}

void LRUCache::put(int key, int value) {

    if (cache_.size() == capacity_) {

        int last = cache_.back();
        cache_.pop_back();
        hash_.erase(last);
    }

    if (hash_.find(key) != hash_.end()) {

        cache_.erase(hash_.at(key));
    }

    cache_.emplace_front(value);
    hash_.emplace(std::pair<int, std::list<int>::iterator>(key,cache_.begin()));    
}


int LRUCache::get(int key) {

    if (hash_.find(key) == hash_.end()) {

        return -1;
    }

    std::list<int>::iterator it = hash_.at(key);

    int value = *it;
    cache_.erase(it);

    cache_.emplace_front(value);
    hash_.emplace(std::pair<int, std::list<int>::iterator>(key, cache_.begin()));

    return value;
}

int main() {

    LRUCache cache(10);

    cache.put(1, 1);
    cache.put(2, 2);
    cache.put(3, 3);
    cache.put(4, 4);
    cache.put(5, 5);
    cache.put(6, 6);
    cache.put(7, 7);
    cache.put(8, 8);
    cache.put(9, 9);
    cache.put(10, 10);
    cache.put(11, 11);
}

