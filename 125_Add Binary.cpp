/*
125. Add Binary
Add two binary strings and return their sum as a binary string.
*/
#include <bits/stdc++.h>
using namespace std;

string addBinary(string a, string b) {
    int i = a.size()-1, j = b.size()-1, carry = 0;
    string res;
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';
        res.push_back((char)('0' + (sum & 1)));
        carry = sum >> 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

int main() {
    cout << "addBinary('11','1') = " << addBinary("11","1") << "\n"; // 100
    cout << "addBinary('1010','1011') = " << addBinary("1010","1011") << "\n"; // 10101
    return 0;
}

// Time Complexity: O(max(len(a),len(b)))
// Space Complexity: O(max(len(a),len(b)))
