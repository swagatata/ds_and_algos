#include <queue>
#include <set>
#include <vector>

namespace swagat {

// Deprecating the std::priority_queue implementatoin as 
//      it doesn't support remove key function.
// template <typename T>
// class MinQueue {
// public:
//     MinQueue() : d_pq(std::greater<T>(), std::vector<T>()) {        
//     }
//     void push(T t) {
//         d_pq.push(t);
//     }
//     T top() {
//         return d_pq.top();
//     }
//     void pop() {
//         d_pq.pop();
//     }
//     bool remove_key(T t);
// private:
//     std::priority_queue<T, std::vector<T>, std::greater<T>> d_pq;
// };

template <typename T>
class MinQueue {
public:
   MinQueue(){}
    void push(const T &t);
    void pop_min();
    void pop_max() {
    const T& min();
    const T& max();
    void remove_key(const T &t);
private:
    std::set<T> d_set;
    T d_min;
    T d_max;
};

}