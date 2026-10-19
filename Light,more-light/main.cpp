#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n = 0;
    while (cin >> n && n != 0) {
        long long r = (long long)sqrt((double)n);

        // fix the presicion
        while (r * r > n)
            r--;
        while ((r + 1) * (r + 1) <= n)
            r++;
        cout << ((r * r == n) ? "yes" : "no") << "\n";
    }

    return 0;
}
