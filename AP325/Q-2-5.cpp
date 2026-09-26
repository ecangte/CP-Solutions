#include <bits/stdc++.h>
#define int int64_t
using namespace std;
static constexpr int P = 1e9 + 7;

vector<vector<int>> fib1{{1, 1},
                         {1, 0}};

vector<vector<int>> times(vector<vector<int>> a, vector<vector<int>> b) {
    vector<vector<int>> c(a.size(), vector<int>(b[0].size(), 0));

    for (int i = 0; i < c.size(); i++) {
        for (int j = 0; j < c[0].size(); j++) {
            for (int k = 0; k < c.size(); k++) {
                c[i][j] = (c[i][j] + (a[i][k] * b[k][j]) % P) % P;
            }
        }
    }

    return c;
}

vector<vector<int>> fpow(int y) {
    if (y == 1) return fib1;
    if (y & 1) return times(fib1, fpow(y - 1));
    vector<vector<int>> temp = fpow(y >> 1);
    return times(temp, temp);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n) {
        if (n == -1) return 0;
        cout << fpow(n - 1)[0][0] << '\n';
    }
}