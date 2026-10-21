#include <bits/stdc++.h>

using namespace std;

void dfs(int i, vector<int> &nums, vector<int> &dp, vector<int> &path, vector<vector<int>> &res) {
    path.push_back(nums[i]);
    if (dp[i] == 1) {
        res.push_back(path);
    } else {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[j] > nums[i] && dp[j] == dp[i] - 1) {
                dfs(j, nums, dp, path, res);
            }
        }
    }
    path.pop_back();
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int len = 0;
        cin >> len;
        vector<int> nums(len);
        for (int i = 0; i < len; i++) {
            cin >> nums[i];
        }

        vector<int> dp(len, 1);
        for (int i = len - 1; i >= 0; i--) {
            for (int j = i + 1; j < len; j++) {
                if (nums[j] > nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        int maxlen = *max_element(dp.begin(), dp.end());

        vector<vector<int>> res;
        vector<int> path;

        for (int i = 0; i < len; i++) {
            if (dp[i] == maxlen) {
                dfs(i, nums, dp, path, res);
            }
        }

        int lmis_sz = res.size();
        cout << lmis_sz << endl;

        for (int i = 0; i < lmis_sz; i++) {
            for (int j = 0; j < res[i].size(); j++) {
                if (j == res[i].size() - 1) cout << res[i][j];
                else cout << res[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
