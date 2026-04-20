#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>dx{-1, 0, 0, 1};
vector<int>dy{0, -1, 1, 0};
void dfs(vector<vector<int>>& fangzhen, int x, int y) {
    //把所有界外的0标记为3
    if(x == 0 || x == n+1 || y == 0 || y == n+1) {
        return;
    }
    if(fangzhen[x][y] == 1 || fangzhen[x][y] == 3) return;
    if(fangzhen[x][y] == 0) {
        fangzhen[x][y] = 3;
        for(int i = 0;i < 4;i++) {
            dfs(fangzhen, x+dx[i], y+dy[i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //先扫描界外的0，标记成3，除了界外的0，剩余的就是界内的
    cin >> n;
    vector<vector<int>>fangzhen(n+2, vector<int>(n+2));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> fangzhen[i][j];
        }
    }
    //沿着边界扫描，如果是0开始dfs
    for(int i = 1;i <= n;i++) {
        if(fangzhen[1][i] == 0) {
            dfs(fangzhen, 1, i);
        }
        if(fangzhen[n][i] == 0) {
            dfs(fangzhen, n, i);
        }
        if(fangzhen[i][1] == 0) {
            dfs(fangzhen, i, 1);
        }
        if(fangzhen[i][n] == 0) {
            dfs(fangzhen, i, n);
        }
    }
    for(int i = 1;i <= n;i++) { 
        for(int j = 1;j <= n;j++) {
            if(fangzhen[i][j] == 3) {
                cout << 0 << ' ';
            } else if(fangzhen[i][j] == 0) {
                cout << 2 << ' ';
            } else if(fangzhen[i][j] == 1) {
                cout << 1 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}