#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
int n, ans = 0;
vector<int> v;
static constexpr int P = 10009;

void func(int idx, i64 sum) {
    if (idx >= n) {
        if (sum % P == 1) {
            ans++;
        } 
        return;
    }
    
    func(idx + 1, (sum * v[idx]) % P);
    func(idx + 1, sum);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    
    v.resize(n);
    for (auto& x : v) cin >> x;
    
    func(0, 1);
    
    cout << ans - 1 << '\n';
}