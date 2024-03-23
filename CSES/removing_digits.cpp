#include <bits/stdc++.h>
using namespace std;

vector<int> get_digits(int n) {
    vector<int> nums;
    while (n > 0) {
        int curr_num = n % 10;
        if (curr_num != 0) {
            nums.push_back(curr_num);
        }
        n = n / 10;
    }
    return nums;
}

int count_min_ways(int n) {
    if (n < 10) {
        return n == 0 ? 0 : 1;
    }
    vector<int> dp(n + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < 10; ++i) {
        dp[i] = 1;
    }

    for (int i = 10; i <= n; ++i) {
        vector<int> curr_digits = get_digits(i);
        for (auto& digit: curr_digits) {
            dp[i] = min(dp[i], 1 + dp[i - digit]);
        }
    }

    return dp[n];

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int ret = count_min_ways(n);
    cout << ret << endl;

    return 0;
}