#include <bits/stdc++.h>
using namespace std;

void func(vector<int> vec, vector<int>& ans) {
    sort(vec.begin(), vec.end());

    ans.push_back(vec[0]);
    for (int i = 1; i < (int)vec.size(); i++) {
        if (vec[i] != vec[i - 1]) {
            ans.push_back(vec[i]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> v(n);

    for (auto& x : v) 
        cin >> x;

    vector<int> ans;
    func(v, ans);

    for (const auto& x : v) {
        cout << lower_bound(ans.begin(), ans.end(), x) - ans.begin() << ' ';
    }
}