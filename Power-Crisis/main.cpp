#include <bits/stdc++.h>

using namespace std;

int josephus(int n, int k) {
    int s = 0;
    for (int i = 2; i <= n - 1; i++) {
        s = (s + k) % i;
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    while (cin >> n && n) {
        for (int m = 1;; m++) {
            int last = josephus(n, m);

            if (last == 11) {
                cout << m << endl;
                break;
            }
        }
    }

    return 0;
}
