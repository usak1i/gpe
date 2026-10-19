#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int r = 0, c = 0;
        cin >> r >> c;
        vector<vector<int>> grid(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                int val = 0;
                cin >> val;
                grid[i][j] = val;
            }
        }

        vector<vector<int>> dp(r + 1, vector<int>(c + 1, 0));
        for (int i = 1; i < r + 1; i++) {
            for (int j = 1; j < c + 1; j++) {
                int cost = grid[i - 1][j - 1];

                if (i - 1 < 1) {
                    dp[i][j] = dp[i][j - 1] + cost;
                } else if (j - 1 < 1) {
                    dp[i][j] = dp[i - 1][j] + cost;
                } else if (i - 1 < 1 && j - 1 < 1) {
                    dp[i][j] = cost;
                } else {
                    dp[i][j] = min(dp[i - 1][j] + cost, dp[i][j - 1] + cost);
                }
            }
        }

        cout << dp[r][c] << "\n";
    }

    return 0;
}
