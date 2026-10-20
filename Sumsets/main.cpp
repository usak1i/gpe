#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n && n != 0) {
        vector<long long> st(n);
        for (int i = 0; i < n; i++) {
            cin >> st[i];
        }

        sort(st.begin(), st.end());
        bool found = false;
        long long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            long long target = st[i];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long num1 = st[j];
                int left = j + 1, right = n - 1;
                while (left < right) {
                    if (left == i) {
                        left++;
                        continue;
                    } else if (right == i) {
                        right--;
                        continue;
                    }
                    long long sum = num1 + st[left] + st[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        found = true;
                        ans = target;
                        break;
                    }
                }
                if (found) break;
            }
            if (found) break;
        }
        if (found) {
            cout << ans << "\n";
        } else {
            cout << "no solution\n";
        }
    }

    return 0;
}
