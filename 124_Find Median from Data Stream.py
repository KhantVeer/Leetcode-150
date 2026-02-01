"""
124. Find Median from Data Stream
Two-heap approach: max-heap for lower half, min-heap for upper half.
"""
import heapq

class MedianFinder:
    def __init__(self):
        self.lo = []  # max-heap (store negatives)
        self.hi = []  # min-heap

    def addNum(self, num: int) -> None:
        if not self.lo or num <= -self.lo[0]:
            heapq.heappush(self.lo, -num)
        else:
            heapq.heappush(self.hi, num)
        # rebalance
        if len(self.lo) > len(self.hi) + 1:
            heapq.heappush(self.hi, -heapq.heappop(self.lo))
        elif len(self.hi) > len(self.lo):
            heapq.heappush(self.lo, -heapq.heappop(self.hi))

    def findMedian(self) -> float:
        if len(self.lo) > len(self.hi):
            return -self.lo[0]
        return (-self.lo[0] + self.hi[0]) / 2.0

if __name__ == '__main__':
    mf = MedianFinder()
    mf.addNum(1)
    mf.addNum(2)
    print('median after [1,2] =', mf.findMedian())  # 1.5
    mf.addNum(3)
    print('median after [1,2,3] =', mf.findMedian())  # 2

# Time Complexity: O(log n) per addNum, O(1) findMedian
# Space Complexity: O(n)
