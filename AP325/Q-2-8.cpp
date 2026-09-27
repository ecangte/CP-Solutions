#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
int P;

i64 fpow(i64 x, int y) {
    if (!y) return (i64)1;
    if (y & 1) return (x * fpow(x, y - 1)) % P;
    i64 temp = fpow(x, y >> 1);
    return (temp * temp) % P;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n >> P;
    while (n--) {
        int x;
        cin >> x;
        cout << fpow(x, P - 2) << ' ';       
    }
}