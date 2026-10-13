#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int len = 0;
        cin >> len;
        vector<int> ins(len);
        int pos = 0;
        for (int i = 0; i < len; i++) {
            string in = "";
            cin >> in;
            if (in == "LEFT")
                ins[i] = -1;
            else if (in == "RIGHT")
                ins[i] = 1;
            else {
                string consume = "";
                cin >> consume; // AS
                int idx = 0;
                cin >> idx;

                ins[i] = ins[idx - 1];
            }
            pos += ins[i];
        }

        cout << pos << "\n";
    }

    return 0;
}
