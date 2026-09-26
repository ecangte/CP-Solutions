#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);
    map<int, int> m;

    for (auto& x : v) {
        cin >> x;
        m[x] = 0;
    }

    int idx = 0;
    for (auto& x : m) {
        x.second = idx++;
    }

    for (const auto& x : v) {
        cout << m[x] << ' ';
    }
    
}