#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

i64 fpow(i64 x, i64 y, i64 p) {
    if (!y) return (i64)1;
    if (y & 1) return (x * fpow(x, y - 1, p)) % p;

    i64 temp = fpow(x, y >> 1, p);

    return (temp * temp) % p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    i64 x = 0, y, p;
    cin >> str >> y >> p;
    for (const auto& i : str) {
        x = (x * 10) % p;
        x = (x + i - '0') % p;
    }

    cout << fpow(x, y, p) << '\n';
}