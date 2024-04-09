#include <min_queue.hpp>
#include <iostream>

namespace swagat {

// template<typename T>
// bool MinQueue<T>::remove_key(T t) {
//     return true;
// }

template<typename T>
void MinQueue<T>::push(const T &t) {
    if (d_set.size() == 0) {
        d_min = t;
        d_max = t;
    } else if (t < d_min) {
        d_min = t;
    } else if (t > d_max) {
        d_max = t;
    }
    d_set.insert(t);
}

template<typename T>
void MinQueue<T>::pop_min() {
    if (d_set.size() > 1) {
        auto next_min = d_set.upper_bound(d_min);    
        d_set.erase(d_min);
        d_min = *next_min;
        return;
    }
    d_set.clear(); 
}

template<typename T>
void MinQueue<T>::pop_max() {
    d_set.erase(d_max);
    if (d_set.size() > 0) {
        auto next_max = d_set.lower_bound(d_max);    
        d_min = *next_min;
        return;
    }
    d_set.clear(); 
}

template<typename T>
const T& MinQueue<T>::min() {
    return d_min;
}

template<typename T>
const T& MinQueue<T>::max() {
    return d_max;
}

template<typename T>
void MinQueue<T>::remove_key(const T& t) {
    if (t == d_min) {
        pop_min();
    }
    d_set.erase(t);
}

} // namespace swagat

int main() {
    swagat::MinQueue<int> minq;
    minq.push(1);
    minq.push(2);
    minq.push(3);
    std::cout << minq.top() << "\n";
    minq.pop_min();
    std::cout << minq.top() << "\n";
    minq.push(4);
    std::cout << minq.top() << "\n"; 
    minq.remove_key(2);
    std::cout << minq.top() << "\n"; 
}