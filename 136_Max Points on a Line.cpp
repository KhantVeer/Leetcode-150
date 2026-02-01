/*
136. Max Points on a Line
Given points on a plane, find the maximum number of points that lie on the same straight line.
Brute-force O(n^2) slope counting with gcd normalization.
*/
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<pair<int,int>>& points) {
    int n = points.size();
    if (n < 3) return n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        unordered_map<long long, int> cnt;
        int duplicates = 0, localMax = 0;
        for (int j = i+1; j < n; ++j) {
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            if (dx == 0 && dy == 0) { duplicates++; continue; }
            int g = gcd(dx, dy);
            if (g != 0) { dx /= g; dy /= g; }
            // normalize sign
            if (dx < 0) { dx = -dx; dy = -dy; }
            else if (dx == 0 && dy < 0) dy = -dy;
            long long key = ((long long)dx << 32) ^ (unsigned long long)(dy & 0xffffffff);
            localMax = max(localMax, ++cnt[key]);
        }
        ans = max(ans, localMax + duplicates + 1);
    }
    return ans;
}

int main() {
    vector<pair<int,int>> pts{{1,1},{2,2},{3,3}};
    cout << "maxPoints = " << maxPoints(pts) << "\n"; // 3
    vector<pair<int,int>> pts2{{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << "maxPoints = " << maxPoints(pts2) << "\n"; // 4
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
