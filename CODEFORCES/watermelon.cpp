#include <bits/stdc++.h>
using namespace std;

void solve() {
    int w;
    cin >> w;

    if ((w > 2) && (w % 2 == 0)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}