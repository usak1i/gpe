#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int len = 0;
        cin >> len;

        vector<long long> x(len), y(len);
        for (int i = 0; i < len; i++) {
            cin >> x[i] >> y[i];
        }

        // Ax + By = C
        // straight line : A(x2 - x1) + B(y2 -y1) = 0, A = dy, B = -dx
        set<tuple<long long, long long, long long>> lines;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                long long A = y[j] - y[i];
                long long B = x[i] - x[j];
                long long C = -(A * x[i] + B * y[i]);

                long long g = gcd(gcd(llabs(A), llabs(B)), llabs(C));
                A /= g;
                B /= g;
                C /= g;

                if (A < 0 || (A == 0 && B < 0)) {
                    A = -A;
                    B = -B;
                    C = -C;
                }

                lines.insert({A, B, C});
            }
        }
        cout << lines.size() << "\n";
    }

    return 0;
}
