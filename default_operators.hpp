template<class T>
struct StaticCmp {
    int operator()(const T& lhs, const T& rhs) const {
        return T::cmp(lhs, rhs); // calls a static cmp method in the chosen class
    }
};

template<class T, class CompareFunction = StaticCmp<T> >
class default_operators {
    // This class provides all the comparator operators based
    // on the existence of a single cmp function
    //
    // Usage:
    //   class SomeClass : public default_operators<SomeClass> {
    //      public:
    //          static int cmp(const SomeClass &lhs, const SomeClass &rhs) {
    //              return -1, 0 or 1 depending on lhs <, = or > rhs;
    //          }
    //
    //      // Generates operators for <, <=, ==, !=, >, >= automatically
    //   }
    //
    //
    // Alternative Usage:
    //  class SomeClass : public default_operators<SomeClass, MemberCmp> {
    //      public:
    //          int cmp(const SomeClass &rhs) const {
    //              return -1, 0, or 1;
    //          }
    //  }
    //
    //
    // Suggested example implementation of the cmp function:
    //  static int cmp(const SomeClass &lhs, const SomeClass &rhs) {
    //      int value_differences[] = {lhs.value1 - rhs.value1, lhs.value2 - rhs.value2, lhs.value3 - rhs.value3};
    //      for(int i = 0; i < 3; ++i) if(value_differences[i]) return value_differences[i];
    //      return 0;
    //  }
    
    //   a function object that provides the comparison function.
    //   Must Provide: int operator()(const T& lhs, const T& rhs)
    CompareFunction cmp;
    
public:
    default_operators()  {} // Default construct cmp -> The comparison functor.
    
    bool operator<(const T& rhs) const {
        return cmp(*static_cast<const T *>(this),rhs) < 0;
    }
    
    bool operator<=(const T& rhs) const {
        return cmp(*static_cast<const T *>(this),rhs) <= 0;
    }
    
    bool operator==(const T& rhs) const {
        return cmp(*static_cast<const T *>(this),rhs) == 0;
    }
    
    bool operator!=(const T& rhs) const {
        return cmp(*static_cast<const T *>(this), rhs) != 0;
    }
    
    bool operator>=(const T& rhs) const {
        return cmp(*static_cast<const T *>(*this), rhs) >= 0;
    }
    
    bool operator>(const T& rhs) const {
        return cmp(*static_cast<const T *>(this), rhs) > 0;
    }
    
};


//------------------------------------------------------------------------------
// These classes provide alternative ways to provide the cmp(lhs, rhs) function
// to the default_operators class.
// Use these classes as template parameters for the CompareFunction template
// parameter of the default_operators<T, CompareFunction> class.

template<class T>
struct MemberCmp {
    int operator()(const T& lhs, const T& rhs) const {
        return lhs.cmp(rhs); // calls a member cmp function
    }
};

template<class T>
struct GeneralCmpFunction {
    typedef int (*CmpFunction)(const T& lhs, const T& rhs);

    CmpFunction func_ptr;
    GeneralCmpFunction(CmpFunction fptr) : func_ptr(fptr) {}
    
    int operator()(const T& lhs, const T& rhs) const {
        return func_ptr(lhs, rhs); // Calls a generic function pointer for comparison
    }
};

template<class T>
struct LessCmpFunction {
    // Use this option when you provide an operator< in your class and you want
    // the other methods to be generated for you
    int operator()(const T& lhs, const T& rhs) {
        if(lhs < rhs) return -1;
        if(!(rhs < lhs)) return 0; // equal
        return 1;
    }
}
