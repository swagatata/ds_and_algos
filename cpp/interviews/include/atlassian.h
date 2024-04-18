#ifndef DISTRIBUTED_SYSTEM_H
#define DISTRIBUTED_SYSTEM_H

#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstdio>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <optional>
#include <queue>
#include <random>
#include <regex>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <atomic>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>

#define FOR(i, n) for(int i = 0 ; i < n ; i++)
#define FORE(i, n) for(int i = n ; i >= 0 ; i++)

#define p(t) std::cout << (t) ;
#define pn(t) std::cout << (t) << endl ;
#define in(n) scanf("%d", &n);

// first is collection size, second is collection id
using Collection = std::pair<u_int64_t, int>;

class CollectionClass {
    int id;
    u_int64_t size;

    bool operator<(CollectionClass other) {
        return size < other.size;
    }
};

class FileSystem {
public:
    FileSystem() : d_totalSize(0) {}

    // Add your class member functions and variables here
    void addFile(u_int64_t size, int collection = -1) {
        // std::cout << "in add file \n";
        d_totalSize += size;

        // handle collections
        if (collection != -1) {
            d_collectionSizes[collection] += size;
            if (d_collectionClassSizes.count(collection) == 0)
        }
    }

    size_t totalSize() const {
        return d_totalSize;
    }

    std::vector<int> topCollections(int x) const {
        std::priority_queue<Collection> pq;
        for (auto it : d_collectionSizes) {
            pq.push(std::make_pair<>(it.second, it.first));
        }

        std::vector<int> topCollections;
        for (int i = 0; i < x && !pq.empty(); ++i) {
            topCollections.push_back(pq.top().second);
            pq.pop();            
        }

        return topCollections;
    }

    std::vector<int> topCollections2(int x) const {
        std::priority_queue<CollectionClass> pq;
        for (auto it : d_collectionSizes) {
            pq.push(CollectionClass(it.second, it.first));
        }

        std::vector<int> topCollections;
        for (int i = 0; i < x && !pq.empty(); ++i) {
            topCollections.push_back(pq.top().second);
            pq.pop();            
        }

        return topCollections;
    }    

private:
    u_int64_t d_totalSize;
    std::unordered_map<int, u_int64_t> d_collectionSizes;
    std::unordered_map<int, CollectionClass*> d_collectionClassSizes;
};
#endif // DISTRIBUTED_SYSTEM_H