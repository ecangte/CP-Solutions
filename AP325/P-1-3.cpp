#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> v;
int n, l;

int cut(int l, int r) {
    if (r - l <= 1) return 0;
    int mid = (v[r] + v[l]) >> 1;

    int m = l;
    while (v[m] < mid) m++;

    if (v[m - 1] - v[l] >= v[r] - v[m]) m--;

    return v[r] - v[l] + cut(l, m) + cut(m, r);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> l;

    v.resize(n + 2);

    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }

    v[0] = 0;
    v[n + 1] = l;

    cout << cut(0, n + 1) << '\n';
}

