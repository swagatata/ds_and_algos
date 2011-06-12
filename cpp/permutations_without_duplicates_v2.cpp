#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

#define D(x) { cout << #x ": " << x  << endl; }

char* full_string;
int counter = 0;
void print_perms(char *str, int length) {
    if(length == 0) {
        printf("%s\n", full_string);
        ++counter;
        return;
    } else {
        // Find the smallest element set it to be the first element and recurse
        char *smallest = min_element(str, str + length);
        iter_swap(str, smallest);
        print_perms(str+1, length-1);
        
        // Look for the smallest element greater than the first element of the current string
        char *smallest_greater = str + length;
        for(char *i = str+1; i != str+length; ++i)
            if(*i > *str && (smallest_greater == str + length || *i < *smallest_greater)) 
                smallest_greater = i;
        while(smallest_greater != str+length) {
            // If such an element is found, swap it into the first slot and recurse
            iter_swap(str, smallest_greater);
            print_perms(str+1, length-1);

            // Repeat the loop if possible
            smallest_greater = str + length;
            for(char *i = str+1; i != str+length; ++i)
                if(*i > *str && (smallest_greater == str + length || *i < *smallest_greater)) 
                    smallest_greater = i;

        }
    }
}

void usage(char *program) {
    printf( "Usage: \n"
            "    %s <string to be permuted> \n\n", program);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        usage(argv[0]);
        exit(EXIT_FAILURE);
    }

    full_string = argv[1];
    print_perms(full_string, strlen(full_string));
    cout << "Count: " << counter << endl;
    return 0;
}
