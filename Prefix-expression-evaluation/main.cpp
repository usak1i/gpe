#include <bits/stdc++.h>
#include <sstream>

using namespace std;

bool isOp(string &s) {
    if (s == "+" || s == "-" || s == "*" || s == "/" || s == "%") {
        return true;
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line = "";
    while (getline(cin, line) && line != ".") {
        stringstream ss(line);

        vector<string> tokens;
        string token;
        while (ss >> token) tokens.push_back(token);

        stack<long long> st;
        bool ok = !tokens.empty();
        int n = tokens.size();
        for (int i = n - 1; i >= 0; i--) {
            string t = tokens[i];
            if (!isOp(t)) {
                st.push(stoll(t));
            } else {
                if (st.size() < 2) {
                    ok = false;
                    break;
                }

                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                long long res = 0;

                switch (t[0]) {
                    case '+':
                        res = a + b;
                        break;
                    case '-':
                        res = a - b;
                        break;
                    case '*':
                        res = a * b;
                        break;
                    case '/':
                        if (b == 0) ok = false;
                        else res = a / b;
                        break;
                    case '%':
                        if (b == 0) ok = false;
                        else res = a % b;
                        break;
                }
                st.push(res);
            }
        }
        if (ok && st.size() == 1) {
            cout << st.top() << "\n";
        } else {
            cout << "illegal\n";
        }
    }

    return 0;
}
