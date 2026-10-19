#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    int fs = 0;
    while (cin >> m >> n && m != 0) {
        if (fs != 0)
            cout << "\n";

        fs++;
        cout << "Field #" << fs << ":\n";

        vector<vector<char>> grid(m, vector<char>(n, '.'));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char c;
                cin >> c;
                grid[i][j] = c;
            }
        }

        vector<vector<char>> field(m, vector<char>(n, '.'));
        int directions[3] = {-1, 0, 1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '*')
                    field[i][j] = '*';
                else {
                    char cnt = '0';
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            if (x == 1 && y == 1)
                                continue;

                            int next_i = i + directions[x],
                                next_j = j + directions[y];
                            if (next_i >= m || next_j >= n || next_i < 0 ||
                                next_j < 0)
                                continue;

                            if (grid[next_i][next_j] == '*')
                                cnt++;
                        }
                    }

                    field[i][j] = cnt;
                }
                cout << field[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}
