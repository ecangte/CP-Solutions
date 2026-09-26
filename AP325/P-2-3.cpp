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

    i64 x, y, p;
    cin >> x >> y >> p;

    cout << fpow(x, y, p) << '\n';
}