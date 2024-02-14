#include <bits/stdc++.h>
using namespace std;

int non_decreasing_lis(vector<int>& A) {
    int n = A.size();
    vector<int> sub;

    for (int i = 0; i < n; i++) {
        if (sub.empty() || sub[sub.size() - 1] <= A[i]) {
            sub.push_back(A[i]);
        } else {
            int index = lower_bound(sub.begin(), sub.end(), A[i]) - sub.begin();
            sub[index] = A[i];
        }
    }

    return sub.size();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int answer = non_decreasing_lis(nums);
    cout << answer << endl;

    return 0;
}