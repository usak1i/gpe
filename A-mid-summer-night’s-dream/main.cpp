#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        // minval of A | # that satisfy the property of A | possible diff vals
        // of A
        int lo = nums[(n - 1) / 2];
        int hi = nums[n / 2];

        int A = lo;

        int cntA = count(nums.begin(), nums.end(), A);

        int ways = hi - lo + 1;

        cout << A << ' ' << cntA << ' ' << ways << endl;
    }

    return 0;
}
