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
        // no swap case
        print_perms(str+1, length-1);

        // swap case
        char *swap_element = upper_bound(str+1, str+length, str[0]);
        while(swap_element != str + length) {
            iter_swap(str, swap_element);
            rotate(str+1, swap_element, swap_element+1);
            print_perms(str+1, length-1);
            rotate(str+1, str+2, swap_element+1);
            iter_swap(str, swap_element);
            swap_element = upper_bound(str+1, str+length, *swap_element);
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
