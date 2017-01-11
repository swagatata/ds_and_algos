//
//  indexed_priority_queue.cpp
//  
//
//  Created by SWAGAT KONCHADA on 04/01/17.
//
//

#include "indexed_priority_queue.hpp"

#include <iostream>
#include <stdexcept>

template<typename T>
IndexedPriorityQueue<T>::IndexedPriorityQueue(unsigned int capacity) {
    _capacity = capacity;
    _array = new T[_capacity];
    _index = new unsigned int[_capacity];
    _heap_pos = new int[_capacity];
    
    for (int i = 0 ; i < _capacity ; ++i) {
        _heap_pos[i] = -1;
    }
    
    _size = 0;
}

/*  Throws length_error when insert is called on a full priority queue.
 */
template<typename T>
void IndexedPriorityQueue<T>::insert(unsigned int index, T key) {
    if (_size == _capacity) {
        throw std::length_error("IndexedPriorityQueue is full.");
    }
    
    _array[index] = key;
    
    _index[_size] = index;
    _heap_pos[index] = _size;
    ++_size;
    heap_float(_size - 1);
}

template<typename T>
const T& IndexedPriorityQueue<T>::min() {
    return _array[index[_size - 1]];
}

template<typename T>
T IndexedPriorityQueue<T>::pop_min() {
    heap_swap(0, --_size);
    
    heap_sink(0);
    
    return _array[_index[_size]];
}

template<typename T>
bool IndexedPriorityQueue<T>::contains(unsigned int index) {
    if (index >= 0 && index < _capacity)
        return _heap_pos[index] != -1;
    
    return false;
}

template<typename T>
unsigned int IndexedPriorityQueue<T>::size() {
    return _size;
}

template<typename T>
bool IndexedPriorityQueue<T>::empty() {
    return _size == 0;
}

template<typename T>
void IndexedPriorityQueue<T>::change(unsigned int index, T key) {
    auto temp = _array[index];
    if (temp == key) {
        return;
    }
    
    _array[index] = key;
    if (temp < key) {
        heap_sink(_heap_pos[index]);
    } else {
        heap_float(_heap_pos[index]);
    }
}

template<typename T>
void IndexedPriorityQueue<T>::deleteKey(unsigned int index) {
    if (!contains(index)) {
        return;
    }
    
    unsigned int i = _heap_pos[index];
    heap_swap(i, _size - 1);
    --_size;
    
    heap_float(i);
    heap_sink(i);
    
    _heap_pos[index] = -1;
    _array[index] = NULL;
}

template<typename T>
void IndexedPriorityQueue<T>::heap_float(unsigned int i) {
    while (i > 0 && less(i, (i-1)/2)) {
        heap_swap(i, (i-1)/2);
        i = (i-1)/2;
    }
}

template<typename T>
void IndexedPriorityQueue<T>::heap_swap(unsigned int i, unsigned int j) {
    if (i == j)
        return;
    
    auto temp = _index[i];
    _index[i] = _index[j];
    _heap_pos[_index[i]] = i;
    _index[j] = temp;
    _heap_pos[_index[j]] = j;
}

template<typename T>
void IndexedPriorityQueue<T>::heap_sink(unsigned int i) {
    // no sink required if size is 1.
    // no sink required if ith node is a leaf node.
    while(_size > 1 && i <= (_size - 2)/2) {
        unsigned int child_i = (i + 1) * 2 - 1;
        if (child_i + 1 < _size) {
            if (less(child_i + 1, child_i)) {
                ++child_i;
            }
        }
        
        if (more(i, child_i)) {
            heap_swap(i, child_i);
        }
        i = child_i;
    }
}

template<typename T>
void IndexedPriorityQueue<T>::print() {
    for (int i = 0 ; i < _size ; ++i) {
        std::cout << _array[_index[i]] << " " ;
    }
    std::cout << std::endl;
    for (int i = 0 ; i < _capacity ; ++i) {
        std::cout << _heap_pos[i] << " " ;
    }
    std::cout << std::endl;
}

using namespace std;

int main() {
    int _size;
    
    std::cout << "Enter sizse of Q : ";
    std::cin >> _size;
    IndexedPriorityQueue<int> ipq(_size);
    
    std::cout << "Enter integers below" << std::endl;
    int n;
    for (int i = 0 ; i < _size ; ++i) {
        std::cin >> n;
        ipq.insert(i, n);
        
    }
    
    while (true) {
        std::cout << "Enter key to delete : " ;
        std::cin >> n;
    
        ipq.deleteKey(n);
        ipq.print();
    }
    
    return 0;
}
