#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int n = 0;
    while (cin >> n && n != 0) {
        nums.push_back(n);
    }

    cout << "PERFECTION OUTPUT" << "\n";

    int len = nums.size();
    for (int i = 0; i < len; i++) {
        int val = nums[i];
        int sum = 0;
        for (int j = 1; j <= val / 2; j++) {
            if (val % j == 0) {
                sum += j;
            }
        }

        string perfection = "";
        if (sum == val) {
            perfection = "PERFECT";
        } else if (sum > val) {
            perfection = "ABUNDANT";
        } else {
            perfection = "DEFICIENT";
        }

        cout << setw(5) << val << "  " << perfection << "\n";
    }

    cout << "END OF OUTPUT" << "\n";

    return 0;
}
