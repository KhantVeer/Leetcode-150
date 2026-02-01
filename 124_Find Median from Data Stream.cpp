/*
124. Find Median from Data Stream
Design a data structure to maintain a stream and return the median at any time.
Solution: two heaps (max-heap for low half, min-heap for high half).
*/
#include <bits/stdc++.h>
using namespace std;

class MedianFinder {
    priority_queue<int> lo; // max-heap
    priority_queue<int, vector<int>, greater<int>> hi; // min-heap
public:
    MedianFinder() {}
    void addNum(int num) {
        if (lo.empty() || num <= lo.top()) lo.push(num);
        else hi.push(num);
        // rebalance
        if (lo.size() > hi.size() + 1) { hi.push(lo.top()); lo.pop(); }
        else if (hi.size() > lo.size()) { lo.push(hi.top()); hi.pop(); }
    }
    double findMedian() {
        if (lo.size() > hi.size()) return lo.top();
        return (lo.top() + hi.top()) / 2.0;
    }
};

int main() {
    MedianFinder mf;
    mf.addNum(1);
    mf.addNum(2);
    cout << "median after [1,2] = " << mf.findMedian() << "\n"; // 1.5
    mf.addNum(3);
    cout << "median after [1,2,3] = " << mf.findMedian() << "\n"; // 2
    return 0;
}

// Time Complexity: O(log n) per addNum, O(1) findMedian
// Space Complexity: O(n)
