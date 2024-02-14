#include <bits/stdc++.h>
using namespace std;

long long get_num_flagstones(long long m, long long n, long long a) {
    long long new_m = ((m - 1 + a) / a);
    long long new_n = ((n - 1 + a) / a);
    long long answer = (new_m * new_n);

    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    long long m, n, a;
    cin >> m >> n >> a;

    long long answer = get_num_flagstones(m, n, a);
    cout << answer << endl;

    return 0;
}