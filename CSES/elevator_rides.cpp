#include <bits/stdc++.h>
using namespace std;

int min_elevator_rides(vector<int>& weights, int max_weight) {
    int n = weights.size();
    pair<int, int> dp[1 << n];
    dp[0] = {0, max_weight};

    for (int curr_mask = 1; curr_mask < (1 << n); ++curr_mask) {
        dp[curr_mask] = {n + 1, 0};
        for (int i = 0; i < n; ++i) {
            bool is_set = ((1 << i) & curr_mask) > 0;
            if (is_set) {
                int prev_mask = (1 << i) ^ curr_mask;
                auto [curr_groups, curr_weight] = dp[prev_mask];

                if (curr_weight + weights[i] > max_weight) {
                    curr_groups++;
                    curr_weight = weights[i];
                } else {
                    curr_weight += weights[i];
                }
                dp[curr_mask] = min(dp[curr_mask], {curr_groups, curr_weight});
            }
            
        }
    }
    return dp[(1 << n) - 1].first;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, max_weight;
    cin >> n >> max_weight;

    vector<int> weights(n);
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    int answer = min_elevator_rides(weights, max_weight);
    cout << answer << endl;
}