#include <bits/stdc++.h>
#define int int64_t

using namespace std;
int n, p;

void rec(int idx, int sum, const vector<int>& v, set<int>& s) {
    if (sum > p) {
        return;
    }
    
    if (idx >= v.size()) {
        s.insert(sum);
        return;
    }

    rec(idx + 1, sum + v[idx], v, s);
    rec(idx + 1, sum, v, s);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;

    vector<int> v1, v2;

    int i;
    for (i = 0; i < n / 2; i++) {
        int x; cin >> x;
        v1.push_back(x);
    }
    for (; i < n; i++) {
        int x; cin >> x;
        v2.push_back(x);
    }
    
    set<int> s1, s2;
    
    rec(0, 0, v1, s1);
    rec(0, 0, v2, s2);

    int ans = max(*(s1.rbegin()), *(s2.rbegin()));

    for (const auto& a : s1) {
        int bfind = p - a;
        auto it = s2.upper_bound(bfind);
        if (it != s2.begin()) {
            it--;
            ans = max(ans, a + *it);
        }
    }

    cout << ans << '\n';
}