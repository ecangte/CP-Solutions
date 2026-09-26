#include <bits/stdc++.h>
using namespace std;
vector<int> v;
int n, p, ans = 0;

void func(int idx, int sum) {
    if (sum > p) 
        return;
    
    if (idx >= n) {
        ans = max(ans, sum);
        return;
    }

    func(idx + 1, sum + v[idx]);
    func(idx + 1, sum);

    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;
    v.resize(n);

    for (auto& x : v) 
        cin >> x;

    func(0, 0);
    
    cout << ans << '\n';
}