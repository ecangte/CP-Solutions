#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> v;
vector<bool> used, usedlf, usedrt;
int ans = 0;
int n;

void func(int now, int score) {
    if (now >= n) {
        ans = max(ans, score);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (used[i] || usedlf[now - i + n] || usedrt[now + i]) 
            continue;
        
        used[i] = true;
        usedlf[now - i + n] = true;
        usedrt[now + i] = true;

        func(now + 1, score + v[now][i]);

        used[i] = false;
        usedlf[now - i + n] = false;
        usedrt[now + i] = false;
    }

    func(now + 1, score);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    v.resize(n, vector<int>(n));
    used.resize(n, false);
    usedlf.resize(n * 2 + 1, false);
    usedrt.resize(n * 2 + 1, false);

    for (auto& vec : v) {
        for (auto& x : vec) {
            cin >> x;
        }
    }

    func(0, 0);

    cout << ans << endl;
}