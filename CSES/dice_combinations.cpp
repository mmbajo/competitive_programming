#include <bits/stdc++.h>
using namespace std;

int dice_combinations(int n) {
    vector<int> dp(n + 1, 0);
    const int MOD = 1e9 + 7;
    dp[1] = 1;

    for (int curr_total = 2; curr_total <= n; ++curr_total) {
        for (int roll = 1; roll <= 6; ++roll) {
            if (curr_total - roll < 0) {
                break;
            }
            if (curr_total == roll) {
                dp[curr_total] += 1;
            }
            dp[curr_total] = (dp[curr_total] + dp[curr_total - roll]) % MOD;
        }
    }
    return dp[n];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int ret = dice_combinations(n);
    cout << ret << endl;
}