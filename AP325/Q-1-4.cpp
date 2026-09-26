#include <bits/stdc++.h>
#define int int64_t
using namespace std;
vector<int> v, pre, prei;
int n, k;

int fSum(int s, int t, int m) {
    int pisum = prei[t] - prei[s - 1];
    int pmsum = (pre[t] - pre[s - 1]) * m;
    return pisum - pmsum;
}

int cut(int ql, int qr, int level) {
    if (qr - ql < 2 || level >= k) return 0;

    int l = ql, r = qr;
    while (l + 1 != r) {
        int m = (l + r) >> 1;
        if (fSum(ql, qr, m) <= 0) {
            r = m;
        } else {
            l = m;
        }
    }

    int best;
    if (l == ql) {
        best = r;
    } else if (r == qr) {
        best = l;
    } else {
        if (abs(fSum(ql, qr, l)) <= abs(fSum(ql, qr, r))) {
            best = l;
        } else {
            best = r;
        }
    }

    return v[best] + cut(ql, best - 1, level + 1) + cut(best + 1, qr, level + 1);
}

int32_t main() {
    cin.tie(nullptr)->ios_base::sync_with_stdio(false);

    cin >> n >> k;

    v.resize(n + 1);
    pre.resize(n + 1);
    prei.resize(n + 1);

    pre[0] = prei[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pre[i] = pre[i - 1] + v[i];
        prei[i] = prei[i - 1] + v[i] * i;
    }

    cout << cut(1, n, 0) << '\n';
}