#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0, m = 0;
    while (cin >> n >> m) {
        vector<int> moves(m);
        for (int i = 0; i < m; i++) {
            cin >> moves[i];
        }

        // dp[i] = when i stones left, 輪到的人是否必贏
        // dp[i] = true  -> Stan wins
        //       = false -> Ollie wins
        vector<bool> dp(n + 1, false);
        dp[0] = false; // no stone are left, 輪到的人輸

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                int take = moves[j];

                // After takes #take stones, if opponent loses, then i win
                if (take <= i && dp[i - take] == false) {
                    dp[i] = true;
                }
            }
        }

        if (dp[n]) {
            cout << "Stan wins" << "\n";
        } else {
            cout << "Ollie wins" << "\n";
        }
    }

    return 0;
}
