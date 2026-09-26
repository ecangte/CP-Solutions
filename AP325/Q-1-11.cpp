#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
int m, n, ans = (int)1e9 + 1;

void func(int up, int dn, int lf, int rt, int sum) {
    if (up == dn || lf == rt) {
        ans = min(ans, sum);
        return;
    }

    // up
    int zeroCnt = 0, oneCnt = 0;
    for (int i = lf; i <= rt; i++) {
        if (v[up][i])
            oneCnt++;
        else
            zeroCnt++;
    }

    func(up + 1, dn, lf, rt, sum + min(zeroCnt, oneCnt));

    // down
    zeroCnt = 0, oneCnt = 0;
    for (int i = lf; i <= rt; i++) {
        if (v[dn][i])
            oneCnt++;
        else
            zeroCnt++;
    }

    func(up, dn - 1, lf, rt, sum + min(zeroCnt, oneCnt));

    // left
    zeroCnt = 0, oneCnt = 0;
    for (int i = up; i <= dn; i++) {
        if (v[i][lf])
            oneCnt++;
        else
            zeroCnt++;
    }

    func(up, dn, lf + 1, rt, sum + min(zeroCnt, oneCnt));

    // right
    zeroCnt = 0, oneCnt = 0;
    for (int i = up; i <= dn; i++) {
        if (v[i][rt])
            oneCnt++;
        else
            zeroCnt++;
    }

    func(up, dn, lf, rt - 1, sum + min(zeroCnt, oneCnt));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    v.resize(m, vector<int>(n));

    for (auto& vec : v) {
        for (auto& x : vec) {
            cin >> x;
        }
    }

    func(0, m - 1, 0, n - 1, 0);

    cout << ans << '\n';
}