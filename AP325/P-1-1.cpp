#include <bits/stdc++.h>
using namespace std;

int func() {
    string str;
    cin >> str;

    if (str[0] == 'f') {
        int x = func();
        return 2 * x - 1;
    }

    if (str[0] == 'g') {
        int x = func();
        int y = func();
        return x + 2 * y - 3;
    }

    int n = stoi(str);

    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << func() << '\n';
}