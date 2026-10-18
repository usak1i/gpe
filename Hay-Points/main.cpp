#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m = 0, n = 0;
    cin >> m >> n;

    unordered_map<string, int> mp;
    for (int i = 0; i < m; i++) {
        string s = "";
        int val = 0;
        cin >> s >> val;
        mp[s] = val;
    }

    int end_cnt = 0;
    int ans = 0;
    while (end_cnt < n) {
        string s = "";
        cin >> s;
        if (s == ".") {
            cout << ans << "\n";
            ans = 0;
            end_cnt++;
            continue;
        }

        if (mp.find(s) != mp.end()) {
            ans += mp[s];
        }
    }

    return 0;
}
