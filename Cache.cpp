#include "Cache.h"
#include <iostream>

LRUCache::LRUCache(int cap)
    : capacity(cap)
{
}

int LRUCache::get(int key)
{
    std::lock_guard<std::recursive_mutex> l(rmutex);

    if (refresh(key))
    {
        return cache_list.front().second;
    }
    else
    {
        return -1;
    }
}

void LRUCache::set(int key, int value)
{
    std::lock_guard<std::recursive_mutex> l(rmutex);

    if (refresh(key))
    {
        cache_list.front().second = value;
    }
    else // New element in cache
    {
        if (cache_list.size() == capacity) // Delete last element
        {
            key_map.erase(cache_list.back().first);
            cache_list.pop_back();
        }

        cache_list.emplace_front(key, value);
        key_map.emplace(key, cache_list.begin());
    }
}

bool LRUCache::refresh(int key)
{
    std::lock_guard<std::recursive_mutex> l(rmutex);

    auto map_iter = key_map.find(key);
    if (map_iter != key_map.end())
    {
        auto cache_iter = map_iter->second;

        // Move used element to front
        cache_list.push_front(*cache_iter);
        cache_list.erase(cache_iter);

        // Update iterator in map
        map_iter->second = cache_list.begin();

        return true;
    }
    else // No such key in cache
    {
        return false;
    }
}

void LRUCache::print() const
{
    std::lock_guard<std::recursive_mutex> l(rmutex);

    for (auto &pair : cache_list)
    {
        std::cout << "{" << pair.first << " : " << pair.second << "}\n";
    }
}