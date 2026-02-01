/*
123. Find K Pairs with Smallest Sums
Return k pairs (u,v) with smallest sums where u from nums1 and v from nums2.
Use a min-heap seeded with pairs (i,0) for each i in nums1 up to k.
*/
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    vector<pair<int,int>> res;
    if (nums1.empty() || nums2.empty() || k <= 0) return res;
    auto cmp = [&](const tuple<int,int,int>& a, const tuple<int,int,int>& b) {
        return get<0>(a) > get<0>(b);
    };
    priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, decltype(cmp)> pq(cmp);
    int n1 = nums1.size(), n2 = nums2.size();
    for (int i = 0; i < n1 && i < k; ++i) pq.emplace(nums1[i] + nums2[0], i, 0);
    while (k-- > 0 && !pq.empty()) {
        auto [sum,i,j] = pq.top(); pq.pop();
        res.emplace_back(nums1[i], nums2[j]);
        if (j + 1 < n2) pq.emplace(nums1[i] + nums2[j+1], i, j+1);
    }
    return res;
}

int main() {
    vector<int> a{1,7,11};
    vector<int> b{2,4,6};
    auto r = kSmallestPairs(a,b,3);
    cout << "kSmallestPairs(...) = ";
    for (auto &p: r) cout << "("<<p.first<<","<<p.second<<") ";
    cout << "\n"; // expected (1,2) (1,4) (1,6)

    vector<int> c{1,1,2};
    vector<int> d{1,2,3};
    auto r2 = kSmallestPairs(c,d,2);
    cout << "kSmallestPairs(...,2) = ";
    for (auto &p: r2) cout << "("<<p.first<<","<<p.second<<") ";
    cout << "\n";
    return 0;
}

// Time Complexity: O(k log min(n1,k))
// Space Complexity: O(min(n1,k))
