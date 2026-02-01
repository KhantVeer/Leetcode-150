/*
116. Find Peak Element
A peak element is an element that is greater than its neighbors. Given an input array where num[i] != num[i+1], find a peak element and return its index.
Use binary search to find any peak in O(log n).
*/
#include <bits/stdc++.h>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int l = 0, r = (int)nums.size() - 1;
    while (l < r) {
        int m = l + (r - l) / 2;
        if (nums[m] > nums[m+1]) r = m;
        else l = m + 1;
    }
    return l;
}

int main() {
    vector<int> a{1,2,3,1};
    cout << "findPeakElement([1,2,3,1]) = " << findPeakElement(a) << "\n"; // expect 2
    vector<int> b{1,2,1,3,5,6,4};
    cout << "findPeakElement([1,2,1,3,5,6,4]) = " << findPeakElement(b) << "\n"; // expect one of peaks
    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
