#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, c;
    cin >> n >> m >> c;
    vector<vector<int>>vals(n+1, vector<int>(m+1, 0));
    //利用前缀和，简化搜索复杂度
    vector<vector<int>>a(n+1, vector<int>(m+1, 0));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> vals[i][j];
            a[i][j] = vals[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int maxVal = INT_MIN, pos_x, pos_y;
    for(int i = 1;i <= n-c+1;i++) {
        for(int j = 1;j <= m-c+1;j++) {
            //矩形面积
            int val = a[i+c-1][j+c-1] - a[i-1][j+c-1] - a[i+c-1][j-1] + a[i-1][j-1];
            if(val > maxVal) {
                maxVal = val;
                pos_x = i, pos_y = j;
            }
        }
    }
    cout << pos_x << ' ' << pos_y;
    return 0;
}
