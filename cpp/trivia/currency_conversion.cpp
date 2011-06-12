/**
 * Convert a currency value provided in words into its numerical equivalent.
 * eg. Two thousand three hundred twenty three == 2323
 *
 * Author: Divye Kapoor
 * Date: 13 June 2011
 *
 * Compile with: g++ -std=c++0x currency_conversion.cpp
 */
#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;

int main() {
    map<string, int> multipliers;
    multipliers["hundred"] = 100;
    multipliers["thousand"] = 1000;
    multipliers["lakh"] = 1e5;
    multipliers["crore"] = 1e7;

    map<string, int> values;
    // Irregular values
    const char* vals[] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
    const char* tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
    
    int counter = 0;
    for_each(vals, vals+20, [&values, &counter](const char* str_rep){ values[str_rep] = counter++; });
    for_each(tens, tens+8, [&values, &counter](const char * str_rep){ values[str_rep] = counter; counter += 10; });

    int result = 0;
    int current_value = 0;
    for_each(istream_iterator<string>(cin), istream_iterator<string>(), [&](const string &s) {
        auto it = multipliers.find(s);
        if(it != multipliers.end()) {
            result += current_value * it->second;
            current_value = 0;
        } else {
            auto it_v = values.find(s);
            if(it_v == values.end()) cerr << "Warning: " << s << " not understood. Ignoring.\n";
            else current_value += it_v->second;
        }
    });
    cout << result + current_value << endl;
    return 0;
}
