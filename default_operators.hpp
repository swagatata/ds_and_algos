template<class T>
class default_operators {
    // This class provides all the comparator operators based
    // on the existence of a single cmp function
    
    // Required: 
    //   a function named cmp in class T
    //   signature: static int cmp(const T& lhs, const T& rhs)
    //   returns: 0 if equal, < 0 if lhs < rhs, > 0 if lhs > rhs
    
public:
    
    bool operator<(const T& rhs) const {
        return T::cmp(*static_cast<const T *>(this),rhs) < 0;
    }
    
    bool operator<=(const T& rhs) const {
        return T::cmp(*static_cast<const T *>(this),rhs) <= 0;
    }
    
    bool operator==(const T& rhs) const {
        return T::cmp(*static_cast<const T *>(this),rhs) == 0;
    }
    
    bool operator!=(const T& rhs) const {
        return T::cmp(*static_cast<const T *>(this), rhs) != 0;
    }
    
    bool operator>=(const T& rhs) const {
        return T::cmp(*static_cast<const T *>(*this), rhs) >= 0;
    }
    
    bool operator>(const T& rhs) const {
        return T::cmp(*static_cast<const T *>(this), rhs) > 0;
    }
    
};
