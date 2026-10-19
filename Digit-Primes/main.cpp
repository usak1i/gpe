#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int len = 1000000;

    vector<bool> isPrimes(len + 1, 1);
    isPrimes[0] = 0, isPrimes[1] = 0;
    for (int i = 2; i * i < len + 1; i++) {
        for (int j = i * i; j < len + 1; j += i) {
            if (isPrimes[j]) {
                isPrimes[j] = 0;
            }
        }
    }

    vector<int> prefix(
        len + 1,
        0); // prefix[i] = total numbers that satisfiled the answer in 1..i
    for (int i = 1; i < len + 1; i++) {
        int satisfied = 0;
        if (isPrimes[i]) {
            int num = i;
            int digitSum = 0;
            while (num) {
                digitSum += num % 10;
                num /= 10;
            }
            if (isPrimes[digitSum])
                satisfied = 1;
        }

        prefix[i] = prefix[i - 1] + satisfied;
    }

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int start = 0, end = 0;
        cin >> start >> end;
        int ans = prefix[end] - prefix[start - 1];
        cout << ans << "\n";
    }

    return 0;
}
