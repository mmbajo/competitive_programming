#include <bits/stdc++.h>
using namespace std;


int min_coins(int num_coins, int total, vector<int>& coins) {
    vector<vector<int>> dp(num_coins + 1, vector<int>(total + 1, INT_MAX));
    dp[0][0] = 0;

    for (int i = 1; i <= num_coins; ++i) {
        int curr_coin = coins[i - 1];
        for (int curr_total = 0; curr_total <= total; ++curr_total) {
            dp[i][curr_total] = dp[i - 1][curr_total];
            if (curr_total >= curr_coin && dp[i][curr_total - curr_coin] != INT_MAX) {
                dp[i][curr_total] = min(dp[i][curr_total], 1 + dp[i][curr_total - curr_coin]);
            }
            
        }
    }
    return dp[num_coins][total] == INT_MAX ? -1 : dp[num_coins][total];
}


int min_coins_less_space(int num_coins, int total, vector<int>& coins) {
    vector<int> dp(total + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= num_coins; ++i) {
        int curr_coin = coins[i - 1];
        for (int curr_total = 0; curr_total <= total; ++curr_total) {
            if (curr_total >= curr_coin && dp[curr_total - curr_coin] != INT_MAX) {
                dp[curr_total] = min(dp[curr_total], 1 + dp[curr_total - curr_coin]);
            }
            
        }
    }
    return dp[total] == INT_MAX ? -1 : dp[total];
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);
    for (int& coin : coins) {
        cin >> coin;
    }

    int result = min_coins_less_space(n, x, coins);
    cout << result << endl;
    return 0;
}