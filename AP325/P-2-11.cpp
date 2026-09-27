#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, pres = 0;
    cin >> n >> k;

    set s{0};
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        pres += x;

        auto it = s.lower_bound(pres - k);
        if (it != s.end()) {
            ans = max(ans, pres - *it);
        }

        s.insert(pres);
    }

    cout << ans << '\n';
}