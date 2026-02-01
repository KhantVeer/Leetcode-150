/*
122. IPO (mapped)
Maximize capital by selecting at most k projects given initial capital W, array of profits and capital requirements.
Use a min-sort on capital and a max-heap for available profits.
*/
#include <bits/stdc++.h>
using namespace std;

int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
    int n = Profits.size();
    vector<pair<int,int>> projects(n);
    for (int i = 0; i < n; ++i) projects[i] = {Capital[i], Profits[i]};
    sort(projects.begin(), projects.end()); // sort by capital
    priority_queue<int> pq; // max-heap for profits
    int idx = 0;
    long long capital = W;
    for (int i = 0; i < k; ++i) {
        while (idx < n && projects[idx].first <= capital) {
            pq.push(projects[idx].second);
            ++idx;
        }
        if (pq.empty()) break;
        capital += pq.top(); pq.pop();
    }
    return (int)capital;
}

int main() {
    vector<int> profits{1,2,3};
    vector<int> capital{0,1,1};
    cout << "findMaximizedCapital(k=2,W=0) = " << findMaximizedCapital(2,0,profits,capital) << "\n"; // 4

    vector<int> p2{1,2,3};
    vector<int> c2{0,1,2};
    cout << "findMaximizedCapital(k=3,W=0) = " << findMaximizedCapital(3,0,p2,c2) << "\n"; // 6
    return 0;
}

// Time Complexity: O(n log n + k log n)
// Space Complexity: O(n)
