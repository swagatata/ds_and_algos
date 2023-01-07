class MedianFinder {
    priority_queue<int> lpq;
    std::priority_queue<int, std::vector<int>, std::greater<int> > rpq;
    int size;
public:
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {   
        if (size == 0)
            lpq.push(num);
        else if (size % 2 == 1) { // size is odd
            if (num >= lpq.top()) {
                rpq.push(num);
            } else {
                rpq.push(lpq.top());
                lpq.pop();
                lpq.push(num);
            }
        } else { // size is even        
            if (num <= lpq.top()) {
                lpq.push(num);
            } else {
                if (num > rpq.top()) {
                    lpq.push(rpq.top());
                    rpq.pop();
                    rpq.push(num);
                } else {
                    lpq.push(num);
                }
            }
        }
        size++;
    }
    
    double findMedian() {
        if (size % 2 == 1) {
            return lpq.top();
        }
        return ((double)lpq.top() + rpq.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */