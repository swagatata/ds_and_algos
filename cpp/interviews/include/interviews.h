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
// #include <jsoncpp/json/json.h>
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

class Interviews {
public:
    // Add your class member functions and variables here
};

class CombinatorialSum {
public:
    CombinatorialSum(std::vector<u_int32_t> v): d_arr(v) {
        std::sort(d_arr.begin(), d_arr.end());
        // remove duplicates
        size_t j = 0;
        for (size_t i = 1; i < d_arr.size(); ++i) {
            if (d_arr[i] == d_arr[j]) {
                continue;
            }
            d_arr[++j] = d_arr[i];
        }
        d_arr.resize(j+1);
    }

    u_int uniqueSumCombinations(u_long sum) {
        return uniqueSumCombinationsRecursion(sum, ((int)d_arr.size()) - 1); 
    }

private:
    std::vector<u_int32_t> d_arr;

    u_int uniqueSumCombinationsRecursion(u_long sum, int lastIndex) {
        // std::cout << "recursion : " << sum << " " << lastIndex << "\n";
        if (lastIndex >= 0 && lastIndex >= d_arr.size()) {
            // std::cout << "Index out of range " << lastIndex << "\n";
            throw std::string("Index out of range");
        }

        if (lastIndex < 0)
            return sum == 0 ? 1 : 0;

        if (d_arr[lastIndex] <= sum) {
            if (lastIndex == 0) {
                if (d_arr[0] == sum) {
                    return 1;
                }
                return 0;
            }
            // consider current element
            auto subSum1 = uniqueSumCombinationsRecursion(sum - d_arr[lastIndex], lastIndex - 1);
            auto subSum2 = uniqueSumCombinationsRecursion(sum, lastIndex - 1);
            return subSum1 + subSum2;
        }
        return uniqueSumCombinationsRecursion(sum, lastIndex - 1);
    }
};
#endif // DISTRIBUTED_SYSTEM_H