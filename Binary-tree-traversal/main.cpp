#include <bits/stdc++.h>

using namespace std;

char pre[26], in[26];
int pos[26];
vector<char> post;

void build(int pl, int il, int len) {
    if (len <= 0) return;

    char root = pre[pl];
    int k = pos[root - 'A'] - il;                   // size of left subtree
    build(pl + 1, il, k);                           // left
    build(pl + 1 + k, il + k + 1, len - k - 1);     // right
    post.push_back(root);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n = 0;
    cin >> n;
    while (n-- > 0) {
        int len = 0;
        cin >> len;
        for (int i = 0; i < len; i++) {
            cin >> pre[i];
        }
        for (int i = 0; i < len; i++) {
            cin >> in[i];
            pos[in[i] - 'A'] = i;
        }

        post.clear();
        build(0, 0, len);

        for (int i = 0; i < len; i++) {
            if (i == len - 1) cout << post[i];
            else cout << post[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
