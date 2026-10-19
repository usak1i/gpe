#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        int num = 0;
        cin >> num;
        nums[i] = num;
    }

    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int ans = 0;
    for (int num : dp) {
        ans = max(ans, num);
    }

    cout << ans << "\n";

    return 0;
}
