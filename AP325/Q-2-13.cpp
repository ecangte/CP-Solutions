#include <bits/stdc++.h>
#define int int64_t
using namespace std;
constexpr int P = 1e9 + 9;

struct Node {
    int x, y;
};

Node times(Node a, Node b) {
    Node c;
    c.x = ((a.x * b.x) % P + (2 * (a.y * b.y) % P) % P) % P;
    c.y = ((a.x * b.y) % P + (a.y * b.x) % P) % P;
    return c;
}

Node z = {1, 0};

Node fpow(Node num, int cnt) {
    if (cnt == 0) return z;
    if (cnt & 1) return times(num, fpow(num, cnt - 1));
    Node temp = fpow(num, cnt >> 1);
    return times(temp, temp);
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Node xy;
    int n;
    cin >> xy.x >> xy.y >> n;

    Node ans = fpow(xy, n);
    cout << ans.x << ' ' << ans.y << '\n';
}