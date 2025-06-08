#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <iostream>
#include <functional>

using namespace std;

struct Report {
    unsigned long long totalSize;
    vector<string> topN;
};

struct Collection {
    string name;
    unsigned long long size;

    bool operator<(const Collection& a) {
        return size < a.size;
    }

    bool operator==(const Collection& a) {
        return name == a.name;
    }
};

class FileSystem {
private:
    unsigned long long d_total;
    unordered_map<string, int> filesize;
    unordered_map<string, int> collectionsize;
    // priority_queue<pair<unsigned long long, string>, vector<pair<unsigned long long, string>>> collections;
    vector<pair<unsigned long long, string>> collections;

        void validate_filename(string filename) {
            if (filename.empty()) {
                throw "empty filename";
            }
        }
        void validate_collection(string collection) {

        }
        void validate_size(int size) {

        }
public:
    FileSystem() : d_total(0) {

    }
    void add(string filename, string collection, unsigned int size) {
        // assume no duplicate filenames
        // validation
        validate_filename(filename);
        validate_collection(collection);
        validate_size(size);

        d_total += size;
        filesize[filename] = size;

        if (collection.empty()) {
            return;
        }
        if (collectionsize.find(collection) == collectionsize.end()) {
            collections.emplace_back(size, collection);
            collectionsize[collection] = size;
        } else {
            collectionsize[collection] += size;
            for (auto &coll : collections) {
                if (coll.second == collection) {
                    coll.first = collectionsize[collection];
                }
            }
            // collections.emplace_back(collectionsize[collection], collection);
        }
    }

    Report generateReport(int N) {
        vector<string> topN;
        sort(collections.begin(), collections.end(), std::greater<pair<unsigned long long, string>>());
        for (int i = 0; i < N && i < collections.size(); ++i) {            
            cout << i << "th element is " << collections[i].second << " " << collections[i].first << endl;
            topN.push_back(collections[i].second);
        }
        return Report{
            d_total,
            topN
        };
    }

};

TEST(AtlassianTest, CaseA) {
    FileSystem fs;
    fs.add("file1", "", 100);
    auto report = fs.generateReport(1);
    EXPECT_EQ(report.totalSize, 100);
    fs.add("file2", "c1", 100);
    report = fs.generateReport(1);
    EXPECT_EQ(report.totalSize, 200);
    fs.add("file3", "c1", 100);
    fs.add("file4", "c2", 100);
    fs.add("file5", "", 10);
    report = fs.generateReport(1);
    EXPECT_EQ(report.totalSize, 410);
    EXPECT_EQ(report.topN.size(), 1);
    EXPECT_EQ(report.topN[0], "c1");
    report = fs.generateReport(2);
    EXPECT_EQ(report.totalSize, 410);
    EXPECT_EQ(report.topN.size(), 2);
    EXPECT_EQ(report.topN[0], "c1");
    EXPECT_EQ(report.topN[1], "c2");
}