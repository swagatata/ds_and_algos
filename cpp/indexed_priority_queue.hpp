//
//  indexed_priority_queue.hpp
//  
//
//  Created by SWAGAT KONCHADA on 04/01/17.
//
//

#ifndef indexed_priority_queue_hpp
#define indexed_priority_queue_hpp

template<typename T>
class IndexedPriorityQueue {
public:
    IndexedPriorityQueue(unsigned int capacity);
    void insert(unsigned int index, T key);
    const T& min();
    T pop_min();
    bool contains(unsigned int index);
    unsigned int size();
    bool empty();
    
    // "modify key" functions
    void change(unsigned int index, T key);
    void deleteKey(unsigned int index);
    
    // debug member functions
    void print();
    
private:
    void heap_float(unsigned int i);
    void heap_swap(unsigned int i, unsigned int j);
    void heap_sink(unsigned int i);
    bool less(unsigned int i, unsigned int j) {
        return _array[_index[i]] < _array[_index[j]];
    }
    bool more(unsigned int i, unsigned int j) {
        return _array[_index[i]] > _array[_index[j]];
    }
    
    // array of indices
    unsigned int * _index;
    
    // get heap position from index
    int * _heap_pos;
    
    // array of keys/elements whose priority is compared
    T * _array;
    
    // max capacity of the IPQ
    unsigned int _capacity;
    
    // number of elements currently in the IPQ
    unsigned int _size;
};

#endif /* indexed_priority_queue_hpp */
