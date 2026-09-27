#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
static constexpr i64 MAX = 1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    i64 k;
    int m, n;
    cin >> k >> m >> n;   
    vector vec(m, vector<i64>(n));

    for (auto& x : vec) {
        for (auto& i : x) {
            cin >> i;
        }
    }

    i64 ans = -MAX;

    for (int top = 0; top < m; top++) {
        
        vector<i64> nowSum(n, 0);

        for (int bottom = top; bottom < m; bottom++) {
            for (int r = 0; r < n; r++) {
                nowSum[r] += vec[bottom][r];
            }  

            set<i64> s{0};
            i64 pres = 0;

            for (int i = 0; i < n; i++) {
                pres += nowSum[i];

                auto it = s.lower_bound(pres - k);

                if (it != s.end()) {
                    ans = max(ans, pres - *it);
                }

                s.insert(pres);
            }
        }
    }

    cout << ans << '\n';
}