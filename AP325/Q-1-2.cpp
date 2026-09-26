#include <bits/stdc++.h>
using namespace std;

int func() {
    string str;
    cin >> str;
    
    if (str[0] == 'f') {
        int x = func();
        return 2 * x - 3;
    }

    if (str[0] == 'g') {
        int x = func();
        int y = func();
        return 2 * x + y - 7;
    }

    if (str[0] == 'h') {
        int x = func();
        int y = func();
        int z = func();
        return 3 * x - 2 * y + z;
    }

    int n = stoi(str);

    return n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    cout << func() << '\n';
}