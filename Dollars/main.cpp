#include <iostream>
#include <vector>

using namespace std;

int main() {
    // 題目說所有的面額和金額都是 5c 的倍數，所以可以直接把 5c 變成一個單位
    // 0.05 -> 1 (multiply by 20)
    int coins[11] = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};

    // max amount is $300
    // 300 * 20 = 6000
    int MAX = 6000;
    vector<long long> dp(MAX + 1, 0);
    dp[0] = 1;

    // Build the whole table
    for (int c : coins) {
        for (int j = c; j <= MAX; j++) {
            dp[j] += dp[j - c];
        }
    }

    double x = 0;
    while (cin >> x && x != 0) {
        int cents = (int)round(x * 100);
        int units = cents / 5;

        printf("%6.2f%17lld\n", x, dp[units]);
    }

    return 0;
}
