#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>ans(n+2, vector<int>(n+2, 0));
    int num = 1;
    int dir = 1;//1是向右，2向下，3向左，4向上
    int i = 1, j = 1;
    while(true) {
        ans[i][j] = num;
        if(num == n*n) break;
        num++;
        if(dir == 1) {
            j++;
            if(j > n || ans[i][j] != 0) {
                dir = 2;
                j--;
                i++;
            }
        } else if(dir == 2) {
            i++;
            if(i > n || ans[i][j] != 0) {
                dir = 3;
                i--;
                j--;
            }
        } else if(dir == 3) {
            j--;
            if(j == 0 || ans[i][j] != 0) {
                dir = 4;
                j++;
                i--;
            }
        } else if(dir == 4) {
            i--;
            if(i == 0 || ans[i][j] != 0) {
                dir = 1;
                i++;
                j++;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(ans[i][j] >= 10) {
                cout << ' ' << ans[i][j];
            } else {
                cout << "  " << ans[i][j];
            }
        }
        cout << endl;
    }
    return 0;
}