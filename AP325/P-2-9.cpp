#include <bits/stdc++.h>
#define int int64_t
using namespace std;
int n, p;

void rec(int idx, int sum, const vector<int>& v, map<int, int>& m) {
    if (idx >= v.size()) {
        m[sum]++;
        return;
    }

    rec(idx + 1, (sum * v[idx]) % p, v, m);
    rec(idx + 1, sum, v, m);
}

int fpow(int x, int y) {
    if (!y) return (int)1;
    if (y & 1) return (x * fpow(x, y - 1)) % p;
    int temp = fpow(x, y >> 1);
    return (temp * temp) % p;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> p;

    vector<int> v1, v2;
    
    int i;
    for (i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        v1.push_back(x);
    }

    for (; i < n; i++) {
        int x;
        cin >> x;
        v2.push_back(x);
    }

    map<int, int> m1, m2;

    rec(0, 1, v1, m1);
    rec(0, 1, v2, m2);
    
    m1[1]--;
    m2[1]--;

    int ans = (m1[1] + m2[1]) % p;

    for (const auto [a, acnt] : m1) {
        int b = fpow(a, p - 2);
        auto it = m2.find(b);
        if (it != m2.end()) {
            ans = (ans + acnt*it->second) % p;
        }
    }   

    cout << ans << '\n';
}