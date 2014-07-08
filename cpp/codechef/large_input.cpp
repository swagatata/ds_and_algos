#include<cstdio>
#include<chrono>

using namespace std;

inline void fastRead(int *a) {
    register char c = 0;
    while (c < 33) c = getchar_unlocked();

    *a = 0;
    while(c > 33) {
        *a = (*a * 10) + c - '0'; 
        c = getchar_unlocked();
    }
}

//This function assumes that the string to be read ends with a new-line character.
//The user has to make sure the buffer size is enought to read the input string, or face the wrath of heap overflow.
inline void fastStringInput(char * str) {
    size_t index = 0;

    char c;
    c = getchar_unlocked();
    while(c != '\n') {
        str[index++] = c;
        c = getchar_unlocked();
    }

    str[index] = '\0';
}

int main() {
    int a;
    //char * input_filename = "/Users/swagat/ds_and_algos/primes";
    
    /*int N = 664579;

    auto begin = chrono::high_resolution_clock::now();
    for (int i = 0 ; i < N ; ++i) {
        fastRead(&a);
        printf("%d", a);
    }
    auto end = chrono::high_resolution_clock::now();

    auto duration = end - begin;
    printf("%lld\n", duration.count());
    */

    char * str = new char[100];
    fastStringInput(str);
    printf("%s\n", str);
}
