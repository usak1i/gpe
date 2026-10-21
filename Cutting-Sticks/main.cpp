#include <bits/stdc++.h>

using namespace std;

int memo(int left, int right, vector<int> &cuts, vector<vector<int>> &dp) {
    if (right - left <= 1) return 0;
    if (dp[left][right] != -1) return dp[left][right];

    int best = INT_MAX;
    for (int i = left + 1; i < right; i++) {
        best = min(best, memo(left, i, cuts, dp) + memo(i, right, cuts, dp));
    }

    return dp[left][right] = best + (cuts[right] - cuts[left]);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int len = 0;
    while (cin >> len && len) {
        int n = 0;
        cin >> n;
        vector<int> cuts;
        cuts.push_back(0);
        for (int i = 0; i < n; i++) {
            int num = 0;
            cin >> num;
            cuts.push_back(num);
        }
        cuts.push_back(len);

        int sz = cuts.size();
        vector<vector<int>> dp(sz, vector<int>(sz, -1));

        int ans = memo(0, sz - 1, cuts, dp);

        cout << "The minimum cutting is " << ans << "." << endl;
    }

    return 0;
}
