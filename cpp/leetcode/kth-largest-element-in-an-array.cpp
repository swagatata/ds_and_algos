class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, std::vector<int>, std::greater<int>> pq;
        for (auto n : nums)
            if (pq.size() < k)
                pq.push(n);
            else {
                if (pq.top() < n) {
                    pq.pop();
                    pq.push(n);
                }
            }
        return pq.top();
    }
};