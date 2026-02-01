/*
121. Kth Largest Element in an Array
Find the k-th largest element in an unsorted array.
We'll use nth_element for average O(n) time.
*/
#include <bits/stdc++.h>
using namespace std;

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    nth_element(nums.begin(), nums.begin() + (n - k), nums.end());
    return nums[n - k];
}

int main() {
    vector<int> a{3,2,1,5,6,4};
    cout << "kthLargest([3,2,1,5,6,4],2) = " << findKthLargest(a,2) << "\n"; // 5

    vector<int> b{3,2,3,1,2,4,5,5,6};
    cout << "kthLargest(...,4) = " << findKthLargest(b,4) << "\n"; // 4

    vector<int> c{1};
    cout << "kthLargest([1],1) = " << findKthLargest(c,1) << "\n"; // 1
    return 0;
}

// Time Complexity: Average O(n) (nth_element)
// Space Complexity: O(1)
