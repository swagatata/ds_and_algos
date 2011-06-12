#ifndef RAND_OBJ_GENERATOR
#define RAND_OBJ_GENERATOR

#include <cstdlib>

template<class Type>
class RandObjGenerator{

public:
    static Type * generate(){
        int type_size = sizeof(Type);
        Type * ptr = new Type();
        void * vptr = (void *)ptr;
        char * cptr = (char *)vptr;
        for (int i = 0 ; i < type_size ; i++)
            cptr[i] = rand() % 256;
            
        return ptr;
    }
};

#endif
