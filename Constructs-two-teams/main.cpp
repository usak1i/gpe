#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int len = 0;
        cin >> len;

        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) {
            int num;
            cin >> num;
            mp[num]++;
        }

        int max_dis = mp.size();

        int max_repe = 0;
        for (auto item : mp) {
            max_repe = max(max_repe, item.second);
        }

        cout << max(min(max_repe - 1, max_dis), min(max_repe, max_dis - 1)) << endl;
    }
    return 0;
}
