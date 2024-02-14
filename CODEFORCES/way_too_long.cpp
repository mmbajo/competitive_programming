#include <bits/stdc++.h>
using namespace std;

void solve() {
    string word;
    cin >> word;
    int n = word.length();

    if (n <= 10) {
        cout << word << endl;
    } else {
        char first = word.front();
        char last = word.back();

        int m = n - 2;

        string result = string(1, first) + to_string(m) + string(1, last);

        cout << result << endl;
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}