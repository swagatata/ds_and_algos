#include <queue>
#include <vector>

template <typename T>
class MinMaxQueue {
public:
    MinMaxQueue() : d_MaxQueue(), d_MinQueue(std::greater<T>(), std::vector<T>())    
    void push(T &t) {
        d_MaxQueue;
    }
private:
    std::priority_queue<T> d_MaxQueue;
    std::priority_queue<T, std::vector<T>, std::greater<T>> d_MinQueue;
};