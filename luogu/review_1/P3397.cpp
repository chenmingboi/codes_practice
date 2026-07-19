#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>chazhi(n+2, vector<int>(n+2, 0));
    vector<vector<int>>ditan(n+2, vector<int>(n+2, 0));
    for(int i = 0;i < m;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        chazhi[x1][y1] += 1;
        chazhi[x2+1][y1] -= 1;
        chazhi[x1][y2+1] -= 1;
        chazhi[x2+1][y2+1] += 1;//上面重复减了，这里要加上
    }
    //ditan[i][j]表示的是从(1, 1)到(i, j)的累计和，可以理解为面积
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            //ditan[i-1][j] + ditan[i][j-1]重复加了从(1,1)到(i-1,j-1)的面积，所以要减去
            //最后加上差值
            ditan[i][j] += ditan[i-1][j] + ditan[i][j-1] - ditan[i-1][j-1] + chazhi[i][j];
            cout << ditan[i][j] << ' ';
        }
        cout << '\n';
    }
    return 0;
}