#include <iostream>
#include <map>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n && n != 0) {
        int win_val = 0;
        map<set<int>, int> mp;
        for (int i = 0; i < n; i++) {
            set<int> st;
            for (int j = 0; j < 5; j++) {
                int courses = 0;
                cin >> courses;
                st.insert(courses);
            }
            mp[st]++;
            win_val = max(win_val, mp[st]);
        }

        int ans = 0;
        for (auto &item : mp) {
            if (item.second == win_val) {
                ans += win_val;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
