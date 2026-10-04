#include <bits/stdc++.h>
using namespace std;

bool check(const string& s, int left, int right) {
    stack<char> st;
    for (int i = left; i <= right; i++) {
        char c = s[i];
        if (c == '(' || c == '[') {
            st.push(c);
        } else if (c == ')') {
            if (st.empty() || st.top() != '(') return false;
            st.pop();
        } else { // c == ']'
            if (st.empty() || st.top() != '[') return false;
            st.pop();
        }
    }
    return st.empty();
}

int count(const string& s, int left, int right) {
    int cnt = 0;
    for (int i = left; i <= right; i++)
        if (s[i] == '[') cnt++;
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();

    int ans = 0;
    // Duyệt mọi cặp (i, j)
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j += 2) { // độ dài phải chẵn
            if (check(s, i, j)) {
                ans = max(ans, count(s, i, j));
            }
        }
    }

    cout << ans << endl;
    return 0;
}