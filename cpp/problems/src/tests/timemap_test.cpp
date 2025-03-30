#include <gtest/gtest.h>
#include <string>
#include <map>
#include <unordered_map>
#include <optional>

using namespace std;

/**
 * Design a time-based key-value data structure that can store multiple values for the same key at different time stamps and retrieve the key's value at a certain timestamp.

Implement the TimeMap class:

TimeMap() Initializes the object of the data structure.
void set(String key, String value, int timestamp) Stores the key key with the value value at the given time timestamp.
String get(String key, int timestamp) Returns a value such that set was called previously, with timestamp_prev <= timestamp. If there are multiple such values, it returns the value associated with the largest timestamp_prev. If there are no values, it returns "".

["TimeMap", "set", "get", "get", "set", "get", "get"]
[[], ["foo", "bar", 1], ["foo", 1], ["foo", 3], ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
Output
[null, null, "bar", "bar", null, "bar2", "bar2"]
 */

class TimeMap {
private:
    using TMap = map<int, string>;
    unordered_map<string, TMap> d_data;
public:
    void set(string key, string value, int time);
    optional<string> get(string key, int time);
};

void TimeMap::set(string key, string value, int time) {
    auto it = d_data.find(key);
    if (it == d_data.end()) {
        d_data[key].insert(make_pair(time, value));
        return;
    }
    it->second.insert(make_pair(time, value));
}

optional<string> TimeMap::get(string key, int time) {
    auto it = d_data.find(key);
    if (it == d_data.end()) {
        return nullopt;
    }
    auto it1 = it->second.upper_bound(time);
    if (it1 == it->second.begin()) {
        return nullopt;
    }
    it1--;
    return it1->second;
}

TEST(TimeMapTest, NoOp) {
    TimeMap tmap;
    tmap.set("foo", "bar", 1);
    EXPECT_EQ(tmap.get("foo", 1), "bar");
    EXPECT_EQ(tmap.get("foo", 3), "bar");
    tmap.set("foo", "bar2", 4);
    EXPECT_EQ(tmap.get("foo", 4), "bar2");
    EXPECT_EQ(tmap.get("foo", 5), "bar2");
}