#include <bits/stdc++.h>
using namespace std;

bool solve(string bit_string) {
    int n = bit_string.length();
    int count_zero = 0;
    int count_ones = 0;

    for (int i = 0; i < n; i++) {

        if (bit_string[i] == '0') {
            count_ones = 0;
            count_zero++;
        } else {
            count_ones++;
            count_zero = 0;
        }

        if (count_ones == 7 || count_zero == 7) {
            return true;
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string bit_string;
    cin >> bit_string;
    
    bool is_dangerous = solve(bit_string);
    if (is_dangerous) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}