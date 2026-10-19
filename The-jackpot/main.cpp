#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n && n != 0) {
        vector<int> bets(n);
        for (int i = 0; i < n; i++) {
            int num = 0;
            cin >> num;
            bets[i] = num;
        }

        int prefixSum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += bets[i];
            if (prefixSum < 0) {
                prefixSum = 0;
                continue;
            }

            ans = max(ans, prefixSum);
        }

        if (ans > 0) {
            cout << "The maximum winning streak is " << ans << ".\n";
        } else {
            cout << "Losing streak.\n";
        }
    }

    return 0;
}
