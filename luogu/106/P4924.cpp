#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> xuanzhuan(const vector<vector<int>>& chushi, int x, int y, int r, int z) {
    vector<vector<int>>result = chushi;
    if(z == 0) {
        //顺时针
        for(int i = x - r - 1;i <= x + r - 1;i++) {
            for(int j = y - r - 1;j <= y + r - 1;j++) {
                result[i][j] = chushi[x+y-j-2][i-x+y];
            }
        }
    } else if(z == 1) {
        //逆时针
        for(int i = x - r - 1;i <= x + r - 1;i++) {
            for(int j = y - r - 1;j <= y + r - 1;j++) {
                result[i][j] = chushi[j-y+x][x+y-i-2];
            }
        }
    }
    return result;
}
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>>chushi(n, vector<int>(n, 0));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            chushi[i][j] = i * n + j + 1;
        }
    }
    //这里的x ,y 是1-based矩阵的坐标转换到0-base的坐标都要减去1
    for(int i = 0;i < m;i++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        chushi = xuanzhuan(chushi, x, y, r, z);
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << chushi[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}