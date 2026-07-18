#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>f(20, vector<int>(20, 0));
    //x表示操作数序列中剩余数字个数，y表示在栈中的剩余数字个数
    for(int x = 0;x <= n;x++) {
        for(int y = 0;y <= n;y++) {
            if(x == 0) {
                f[x][y] = 1;
            } else if(y == 0) {
                f[x][y] = f[x-1][y+1];
            } else {
                //push: f[x-1][y+1]  pop:f[x][y-1]
                f[x][y] = f[x-1][y+1] + f[x][y-1];
            }
        }
    }
    cout << f[n][0];
    return 0;
}