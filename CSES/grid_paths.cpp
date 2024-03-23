#include <bits/stdc++.h>
using namespace std;

int count_paths(vector<vector<char>> grid) {
    int R = grid.size();
    int C = grid[0].size();
    int MOD = 1e9 + 7;
    vector<vector<int>> dp(R, vector<int>(C, 0));
    for (int i = 0; i < R; ++i) {
        if (grid[i][0] == '.') {
            dp[i][0] = 1;
        } else {
            break;
        }
    }

    for (int j = 0; j < C; ++j) {
        if (grid[0][j] == '.') {
            dp[0][j] = 1;
        } else {
            break;
        }
    }

    for (int i = 1; i < R; ++i) {
        for (int j = 1; j < C; ++j) {
            if (grid[i][j] == '*') {
                continue;
            }
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
        }
    }

    return dp[R - 1][C - 1];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; ++i) {
        for (char& x: grid[i]) {
            cin >> x;
        }
    }
    int ret = count_paths(grid);
    cout << ret << endl;

    return 0;
}