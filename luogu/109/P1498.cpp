#include<bits/stdc++.h>
using namespace std;

void draw(int x, int y, int k, vector<vector<char>>& mp) {
    if(k == 1) {
        mp[x][y+1] = '/';mp[x][y+2] = '\\';
        mp[x+1][y] = '/';mp[x+1][y+1] = '_';mp[x+1][y+2] = '_';mp[x+1][y+3] = '\\';
        return;
    }
    //以(x, y)为左上角画一个k级图腾
    //上
    draw(x, y + pow(2, k-1), k-1, mp);
    //左
    draw(x + pow(2, k-1), y, k-1,mp);
    //右
    draw(x + pow(2, k-1), y + pow(2, k), k-1, mp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //map的行数为2^n, map的列数为2^(n+1)
    //注意在c++中^不是幂运算
    vector<vector<char>>mp(pow(2, n), vector<char>(pow(2, (n+1)), ' '));
    draw(0, 0, n, mp);
    for(int i = 0;i < pow(2, n);i++) {
        for(int j = 0;j < pow(2, n+1);j++) {
            cout << mp[i][j];
        }
        cout << endl;
    }
    return 0;
}