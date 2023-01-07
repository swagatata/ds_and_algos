class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // counts
        unordered_map<int, int> counts;        
        priority_queue<pair<int, int>> pq;
        for (auto n : nums) {
            counts[n]++;            
        }
        for (auto &pair : counts) {
            pq.push(make_pair(pair.second, pair.first));
        }        
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};