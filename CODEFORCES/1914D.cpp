#include <bits/stdc++.h>
using namespace std;

vector<int> get_top_three(vector<int>& A) {
    vector<int> ret(3, -1);
    int n = A.size();

    for (int i = 0; i < n; i++) {
        if (ret[0] == -1 || A[ret[0]] < A[i]) {
            ret[2] = ret[1];
            ret[1] = ret[0];
            ret[0] = i;
        } else if (ret[1] == -1 || A[ret[1]] < A[i]) {
            ret[2] = ret[1];
            ret[1] = i;
        } else if (ret[2] == -1 || A[ret[2]] < A[i]) {
            ret[2] = i;
        }
    }
    return ret;
}

int dp(vector<vector<int>>& arr) {
    int answer = 0;

    vector<int> A = get_top_three(arr[0]);
    vector<int> B = get_top_three(arr[1]);
    vector<int> C = get_top_three(arr[2]);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                if (A[i] != B[j] && B[j] != C[k] && A[i] != C[k]) {
                    int c_sum = arr[0][A[i]] + arr[1][B[j]] + arr[2][C[k]];
                    answer = max(answer, c_sum);
                }
            }
        }
    }
    
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> arr(3, vector<int>(n, 0));
        for (int j = 0; j < 3; j++) {
            for (int i = 0; i < n; i++) {
                cin >> arr[j][i];
            }
        }

        int out = dp(arr);
        cout << out << endl;
    
    }
}