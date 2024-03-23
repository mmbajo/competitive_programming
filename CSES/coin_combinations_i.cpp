#include <bits/stdc++.h>
using namespace std;

int count_ways(int total, vector<int>& coins) {
    int n = coins.size();
    int MOD = 1e9 + 7;
    vector<int> dp(total + 1, 0);
    dp[0] = 1;
    for (int curr_total = 1; curr_total <= total; ++curr_total) {
        for (auto& coin : coins) {
            if (curr_total >= coin) {
                dp[curr_total] = (dp[curr_total] + dp[curr_total - coin]) % MOD;
            }
        }
    }
    return dp[total];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, total;
    cin >> n >> total;

    vector<int> coins(n);
    for (int& coin: coins) {
        cin >> coin;
    }

    int ret = count_ways(total, coins);
    cout << ret << endl;

    return 0;
}