#include <bits/stdc++.h>
using namespace std;

int main() {
    // steps :
    //  y + 1
    // x-- unitl hit (-i, i) (i-th round)
    // y-- until hit (-i, 0)
    // x++, y-- until hit (0, -i)
    // x++ until hit (i, -i)
    // y++, unitl hit (i, 0)
    // x--, y++ unitl hit (0, i)
    // finish a round

    const int MAX_SIZE = 200000;
    int bee[MAX_SIZE][2] = {0};
    int round = 1;
    int idx = 2;
    int x = 0, y = 1;
    bee[idx][0] = x, bee[idx][1] = y;
    while (idx < MAX_SIZE / 2) {
        while (x > -round) {
            x--;
            idx++;
            bee[idx][0] = x, bee[idx][1] = y;
        }

        while (y > 0) {
            y--;
            idx++;
            bee[idx][0] = x, bee[idx][1] = y;
        }

        while (x < 0) {
            x++;
            y--;
            idx++;
            bee[idx][0] = x, bee[idx][1] = y;
        }

        while (x < round) {
            x++;
            idx++;
            bee[idx][0] = x, bee[idx][1] = y;
        }

         while (y != 1) {
             y++;
             idx++;
             bee[idx][0] = x, bee[idx][1] = y;
         }

         round++;

         while (x > 0) {
             x--;
             y++;
             idx++;
             bee[idx][0] = x, bee[idx][1] = y;
         }

    }

    int n = 0;
    while (cin >> n) {
        cout << bee[n][0] << " " << bee[n][1] << "\n";
    }

    return 0;
}
