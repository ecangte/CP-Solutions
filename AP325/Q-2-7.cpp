#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m, n;
    cin >> m >> n;

    set<int> s;
    int ans = 0;
    while (n--) {
        string str;
        cin >> str;

        int ff = (1 << m) - 1, team = 0;
        
        for (const auto& i : str) {
            team |= 1 << (i - 'A');
        }

        if (s.count(team) != 0) ans++;

        s.insert(ff - team);
    }

    cout << ans << '\n';
}