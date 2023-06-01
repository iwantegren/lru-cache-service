#pragma once

#include <list>
#include <unordered_map>
#include <utility>
#include <mutex>

class LRUCache
{
public:
    LRUCache(int capacity);

    int get(int key);
    void set(int key, int value);

    void print() const;

private:
    bool refresh(int key);

    const int capacity;

    // We use linked list as a storage with mechainsm LRU-sorting
    // The last element in list was least recently used
    std::list<std::pair<int, int>> cache_list;

    // We use hash table for constant access to each key of cache
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> key_map;

    mutable std::recursive_mutex rmutex;
};