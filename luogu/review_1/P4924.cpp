#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> xuanzhuan(const vector<vector<int>>& a, int x, int y, int r, int z) {
    //旋转中心对应坐标为(x-1, y-1)
    vector<vector<int>>temp = a;
    for(int i = x-1-r;i <= x-1+r;i++) {
        for(int j = y-1-r;j <= y-1+r;j++) {
            if(z == 0) {
                temp[i][j] = a[x+y-2-j][i-x+y];
            } else if(z == 1) {
                temp[i][j] = a[j+x-y][x+y-2-i];
            }
        }
    }
    return temp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>juzhen(n, vector<int>(n, 0));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            juzhen[i][j] = i * n + j + 1;
        }
    }
    for(int i = 0;i < m;i++) {
        int x, y, r, z;
        cin >> x >> y >> r >> z;
        juzhen = xuanzhuan(juzhen, x, y, r, z);
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++){
            cout << juzhen[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}