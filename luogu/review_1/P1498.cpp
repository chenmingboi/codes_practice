#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<char>>tu;
void draw(int x, int y, int s) {
    //从左上角坐标为(x, y)的点开始画
    if(s == 1) {
        tu[x][y+1] = '/', tu[x][y+2] = '\\';
        tu[x+1][y] = '/', tu[x+1][y+1] = '_';
        tu[x+1][y+2] = '_', tu[x+1][y+3] = '\\';
        return;
    }
    //最上面的
    draw(x, y+pow(2, s-1), s-1);
    //左下
    draw(x+pow(2, s-1), y, s-1);
    //右下
    draw(x+pow(2, s-1), y+pow(2, s), s-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    tu.resize(pow(2, n), vector<char>(pow(2, n+1), ' '));
    draw(0, 0, n);
    for(int i = 0;i < pow(2, n);i++) {
        for(int j = 0;j < pow(2, n+1);j++) {
            cout << tu[i][j];
        }
        cout << '\n';
    }
    return 0;
}