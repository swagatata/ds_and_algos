#ifndef DISTRIBUTED_SYSTEM_H
#define DISTRIBUTED_SYSTEM_H

#include <iostream>
#include <string>
#include <vector>

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
    }

    u_int uniqueSumCombinations(u_long sum) {
        return uniqueSumCombinationsRecursion(sum, ((int)d_arr.size()) - 1); 
    }

private:
    std::vector<u_int32_t> d_arr;

    u_int uniqueSumCombinationsRecursion(u_long sum, int lastIndex) {
        std::cout << "recursion : " << sum << " " << lastIndex;
        if (lastIndex >= d_arr.size())
            throw std::string("Index out of range");

        if (lastIndex < 0)
            return 0;

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