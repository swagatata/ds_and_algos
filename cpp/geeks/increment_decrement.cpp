#include <string>
#include <cassert>
#include <queue>

/**
*  Problem : Given a pattern (string) consisting I & D, ex: IIDD
*  where I represents an increment and D a decrement,
*  return a list of numbers which follow the increments and decrements order.
*  For example: 
    II can be solved with 1,2,3 or 2,3,4
*   DD can be solved with 3,2,1
*   return the minimum solution
*/

bool validate(char c, int d1, int d2) {
    if (c == 'I') {
        if (d1 >= d2) {
            return false;
        }
    }
    if (c == 'D') {
        if (d1 <= d2) {
            return false;
        }
    }

    return true;
}

std::string increment_decrement(const std::string &pattern) {    
    std::vector<int> digits;
    std::priority_queue<char, std::minimum> pq;
    for (int i = 1; i < 10; ++i) {
        pq.push(i);
    }
    digits.push_back(1);
    int n_Ds = 0;
    for (size_t i = 1; i < pattern.size(); ++i) {
        auto new_char = pattern[i];
        auto next_digit = pq.top();
        if (new_char == 'I') {
            if (n_Ds > 0) {
                
                n_Ds = 0;   
            }
            digits.push_back(next_digit);
            continue;   
        }
        // calculate number of Ds
        n_Ds++;
    }


    return digits;
}

int main() {
    assert(increment_decrement("II") == "123");
    assert(increment_decrement("DD") == "321");
    assert(increment_decrement("DID") == "2143");
    assert(increment_decrement("DIID") == "21354");
}