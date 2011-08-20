#include <unistd.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main() {
    string data;
    fstream fin("data.txt");
    while(fin >> data) {
        cout << data << '\n';
    }
    return 0;
}
