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
        set<int> distinct;
        unordered_map<int, int> mp;
        for (int i = 0; i < len; i++) {
            int num;
            cin >> num;
            distinct.insert(num);
            mp[num]++;
        }

        // 4 5 4 1 4 2 4 -> distinct = [1, 2 ,4 ,5], repetition = [4, 4, 4, 4]
        // 2 2 4 4 -> d = [2 ,4], r = [2, 2]
        int max_dis = distinct.size();

        int max_repe = 0;
        for (auto item : mp) {
            max_repe = max(max_repe, item.second);
        }

        // max_dis = 3, max_repe = 4
        int ans = min(max_repe, max_dis);

        cout << ans << endl;
    }
    return 0;
}
