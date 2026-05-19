#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    //差值
    vector<vector<int>>ditan(n+2, vector<int>(n+2, 0));
    for(int i = 0;i < m;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ditan[x1][y1] += 1;
        ditan[x1][y2+1] -= 1;
        ditan[x2+1][y1] -= 1;
        ditan[x2+1][y2+1] += 1;
    }
    vector<vector<int>>ans(n+1, vector<int>(n+1, 0));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            //后三项表示除了a[i][j]之外的不规则四边形 ditan[i][j]为之间的差值
            ans[i][j] = ditan[i][j] + ans[i-1][j] + ans[i][j-1] - ans[i-1][j-1];
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
}