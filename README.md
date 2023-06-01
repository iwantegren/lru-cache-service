# LRU-cache RESTful service

This is a simple RESTful service implementing Least Recently Used (LRU) cache (https://en.wikipedia.org/wiki/Cache_replacement_policies#LRU) with maximum capacity and processing 2 requests:
- GET(key) - returns the value of the key if the key exists in cache, otherwise -1.
- POST (key, value) - updates the value of the key, if it exists, otherwise adds the (key, value) pair to the cache. Key-value pair is sent in JSON format.

## Example:
```
// Starting service with capacity 2

POST (1, 1) // cache {1=1}
POST (2, 2) // cache {1=1, 2=2}
GET(1) // return 1
POST(3, 3) // delete key 2, cache {1=1, 3=3}
GET(2) // return -1 (no key in the cache)
POST(4, 4) // delete key 1, cache {4=4, 3=3}
GET(1) // return -1 (no key in the cache)
GET(3) // return 3
GET(4) // return 4
```

## Structure
`src/` contains own files with C++ code including main.cpp

`bin/` contains binaries for both linux and windows

`script/` contains bash scripts for testing service

`drogon/` external repository for working with REST