#include <bits/stdc++.h>
using namespace std;

string filter_input_str(string a) {
    string answer = "";
    int n = a.size();
    for (int i = 0; i < n; i++) {
        char x = tolower(a[i]);
        if (string("aoyeui").find(x) == string::npos) {
            answer += '.';
            answer += x;
        }
    }
    return answer;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s;
    cin >> s;

    string ans = filter_input_str(s);
    cout << ans << endl;
    return 0;
}