#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<bool>> &grid, int i, int j) {
    if (i >= grid.size() || j >= grid[0].size() || i < 0 || j < 0 ||
        grid[i][j] == 0)
        return;

    if (grid[i][j] == 1)
        grid[i][j] = 0;

    int directions[3] = {-1, 0, 1};
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (r == 1 && c == 1)
                continue;
            dfs(grid, i + directions[r], j + directions[c]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m = 0, n = 0;
    while (cin >> m >> n) {
        if (m == 0 && n == 0)
            break;

        vector<vector<bool>> grid(m, vector<bool>(n, 0));
        string line = "";
        for (int i = 0; i < m; i++) {
            cin >> line;
            for (int j = 0; j < n; j++) {
                grid[i][j] = (line[j] == '*') ? 0 : 1;
            }
        }

        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]) {
                    ans++;
                    dfs(grid, i, j);
                }
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
