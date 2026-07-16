#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>ans(n, vector<int>(n, 0));
    int x = 0, y = 0, ran = 1, dir = 1;
    //dir = 1向右，dir = 2向下，dir = 3向左，dir = 4向上
    while(ran <= n*n) {
        ans[x][y] = ran;
        ran++;
        if(dir == 1) {
            if(y+1 >= n || ans[x][y+1] != 0) {
                dir = 2;
                x++;
            } else {
                y++;
            }
        } else if(dir == 2) {
            if(x+1 >= n || ans[x+1][y] != 0) {
                dir = 3;
                y--;
            } else {
                x++;
            }
        } else if(dir == 3) {
            if(y-1 < 0 || ans[x][y-1] != 0) {
                dir = 4;
                x--;
            } else {
                y--;
            }
        } else if(dir == 4) {
            if(x-1 < 0 || ans[x-1][y] != 0) {
                dir = 1;
                y++;
            } else {
                x--;
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << setw(3) << ans[i][j];
        }
        cout << '\n';
    }
    return 0;
}