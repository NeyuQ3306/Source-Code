#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> cnt(10, 0);

    int sum = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;

        cnt[x]++;
        sum += x;
    }

    auto remove_one = [&](int rem) {
        for (int d = 1; d <= 9; d++) {
            if (d % 3 == rem && cnt[d]) {
                cnt[d]--;
                return true;
            }
        }
        return false;
    };

    auto remove_two = [&](int rem) {
        int need = 2;

        for (int d = 1; d <= 9; d++) {
            while (cnt[d] && d % 3 == rem && need) {
                cnt[d]--;
                need--;
            }
        }

        return need == 0;
    };

    int r = sum % 3;

    if (r == 1) {
        if (!remove_one(1)) {
            if (!remove_two(2)) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    else if (r == 2) {
        if (!remove_one(2)) {
            if (!remove_two(1)) {
                cout << -1 << '\n';
                return;
            }
        }
    }

    string ans = "";

    for (int d = 9; d >= 0; d--) {
        ans += string(cnt[d], char(d + '0'));
    }

    if (ans.empty()) {
        cout << -1 << '\n';
        return;
    }

    // toàn số 0
    if (ans[0] == '0') {
        cout << 0 << '\n';
        return;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        solve();
    }

    return 0;
}