#include<bits/stdc++.h>
using namespace std;
int n, m, result = 0;

vector<int>dx{-1, -1, -1, 0, 0, 1, 1, 1};
vector<int>dy{-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(vector<vector<char>>& tiandi, vector<vector<int>>& num, int x, int y) {
    if(x == 0 || x == n+1 || y == 0 || y == m+1) {
        return;
    }
    if(tiandi[x][y] == '.') {
        return;
    }
    if(tiandi[x][y] == 'W' && num[x][y] == -1) {
        num[x][y] = result;
        for(int i = 0;i < 8;i++) {
            dfs(tiandi, num, x+dx[i], y+dy[i]);
        }
    }
}
int main() {
    cin >> n >> m;
    vector<vector<char>>tiandi(n+2, vector<char>(m+2, ' '));
    vector<vector<int>>num(n+2, vector<int>(m+2, -1));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> tiandi[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(tiandi[i][j] == 'W' && num[i][j] == -1) {
                //找到一个新的 “W 且没访问过”
                result++;
            }
            //从i,j画出一整个连通块
            dfs(tiandi, num, i, j);
        }
    }
    cout << result;
}