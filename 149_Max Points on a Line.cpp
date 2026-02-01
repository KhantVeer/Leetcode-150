/*
149. Max Points on a Line
Given a list of points, return the maximum number of points that lie on the same straight line.
Uses slope counting with gcd normalization; handles duplicates.
*/
#include <bits/stdc++.h>
using namespace std;

int maxPoints(vector<pair<int,int>>& points){
    int n = points.size();
    if(n < 3) return n;
    int best = 0;
    for(int i=0;i<n;i++){
        unordered_map<long long,int> cnt;
        int duplicates = 0;
        int local_max = 0;
        for(int j=i+1;j<n;j++){
            int dx = points[j].first - points[i].first;
            int dy = points[j].second - points[i].second;
            if(dx==0 && dy==0){ duplicates++; continue; }
            int g = std::gcd(dx, dy);
            dx /= g; dy /= g;
            // normalize sign
            if(dx < 0) { dx = -dx; dy = -dy; }
            if(dx == 0) dy = 1; // vertical
            if(dy == 0) dx = 1; // horizontal
            long long key = ((long long)dx << 32) ^ (unsigned long long)(dy & 0xffffffff);
            local_max = max(local_max, ++cnt[key]);
        }
        best = max(best, local_max + duplicates + 1);
    }
    return best;
}

int main(){
    vector<pair<int,int>> pts1 = {{1,1},{2,2},{3,3}};
    cout << "maxPoints([1,1],[2,2],[3,3]) = " << maxPoints(pts1) << "\n";

    vector<pair<int,int>> pts2 = {{1,1},{3,2},{5,3},{4,1},{2,3},{1,4}};
    cout << "maxPoints(example) = " << maxPoints(pts2) << "\n";

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(n)
