#include <bits/stdc++.h>
using namespace std;
string str;
int n, idx;

int cut(int size) {
    if (str[idx] == '0') {
        idx++;
        return 0;
    }
    if (str[idx] == '1') {
        idx++;
        return size * size;
    }
    idx++;
    int sum = 0;
    for (int i = 1; i <= 4; i++) {
        sum += cut(size / 2);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> str >> n;
    idx = 0;
    cout << cut(n) << '\n';
}