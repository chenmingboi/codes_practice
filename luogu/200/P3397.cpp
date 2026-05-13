#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>a(n+1, vector<int>(n+1, 0));
    vector<vector<int>>d(n+2, vector<int>(n+2, 0));
    for(int i = 0;i < m;i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1] += 1;
        d[x1][y2+1] -= 1;
        d[x2+1][y1] -= 1;
        d[x2+1][y2+1] += 1;
    }
    //利用前缀和求出ditu[i][j]
    //假设原矩阵 A[i][j]，二维差分矩阵 D[i][j] 定义为：
    // D[i][j]=A[i][j]−A[i−1][j]−A[i][j−1]+A[i−1][j−1]
    //则A[i][j] = D[i][j] + A[i-1][j] + A[i][j-1] - A[i-1][j-1]
    //想象成矩形面积
    for(int i = 1; i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            a[i][j] = d[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
            cout << a[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}