#include<bits/stdc++.h>
using namespace std;

int n, m, t;
int sx, sy, fx, fy;
int result = 0;
void dfs(vector<vector<int>>& migong, int x, int y) {
    //先判断这个节点是否合法然后再判断是否到达了终点
    if(x == 0 || x == n+1 || y == 0 || y == m+1) {
        return;
    }
    if(migong[x][y] != 0) return;
    if(x == fx && y == fy) {
        result++;
        return;
    }


    migong[x][y] = 1;
    //向上
    dfs(migong, x-1, y);

    //向下
    dfs(migong, x+1, y);

    //向左
    dfs(migong, x, y-1);

    //向右
    dfs(migong, x, y+1);
    //回溯的是当前节点，恢复本此尝试之前的状态，本此尝试即以x,y为root然后向
    //四个方向进行探索的路径
    migong[x][y] = 0;

}
int main() {
    cin >> n >> m >> t;
    vector<vector<int>>migong(n+2, vector<int>(m+2, 0));
    cin >> sx >> sy >> fx >> fy;
    for(int i = 0;i < t;i++) {
        int x, y;
        cin >> x >> y;
        migong[x][y] = -1;//-1表示障碍
    }
    dfs(migong, sx, sy);
    cout << result;
}