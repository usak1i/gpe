#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n) {
        int len = n / 2;
        int maxNum = pow(10, n) - 1;
        for (int i = 0; i < sqrt(maxNum); i++) {
            int target = i * i;
            int split = pow(10, len);
            int targetLeft = target / split;
            int targetRight = target % split;

            if (pow(targetLeft + targetRight, 2) == target) {
                string leftOutput = to_string(targetLeft);
                string rightOutput = to_string(targetRight);
                while (leftOutput.size() < len) {
                    leftOutput = "0" + leftOutput;
                }

                while (rightOutput.size() < len) {
                    rightOutput = "0" + rightOutput;
                }

                cout << leftOutput << rightOutput << "\n";
            }
        }
    }

    return 0;
}
