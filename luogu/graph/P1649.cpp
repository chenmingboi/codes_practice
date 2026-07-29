#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>>mp(n+1, vector<char>(n+1));
    int xa, ya, xb, yb;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            cin >> mp[i][j];
            if(mp[i][j] == 'A') {
                xa = i, ya = j;
            }
            if(mp[i][j] == 'B') {
                xb = i, yb = j;
            }
        }
    }
    vector<vector<int>>dp(n+1, vector<int>(n+1, INF));
    dp[xa][ya] = 0;
    bool flag = false;
    for(int i = 0;i < 2*n;i++) {
        flag = false;
        for(int x = 1;x <= n;x++) {
            for(int y = 1;y <= n;y++) {
                if(dp[x][y] != INF) {
                    for(int x1 = x;x1 <= n;x1++) {
                        if(mp[x1][y] == 'x') {
                            break;
                        } else {
                            int temp = dp[x1][y];
                            dp[x1][y] = min({dp[x][y], (y-1 >= 1) ? dp[x1][y-1]+1 : INF, (y+1 <= n) ? dp[x1][y+1]+1 : INF});
                            if(temp != dp[x1][y]) flag = true;
                        }
                    }
                    for(int y1 = y;y1 <= n;y1++) {
                        if(mp[x][y1] == 'x') {
                            break;
                        } else {
                            int temp = dp[x][y1];
                            dp[x][y1] = min({dp[x][y], (x-1 >= 1) ? dp[x-1][y1]+1 : INF, (x+1 <= n) ? dp[x+1][y1]+1 : INF});
                            if(temp != dp[x][y1]) flag = true;
                        }
                    }
                    for(int x1 = x;x1 >= 1;x1--) {
                        if(mp[x1][y] == 'x') {
                            break;
                        } else {
                            int temp = dp[x1][y];
                            dp[x1][y] = min({dp[x][y], (y-1 >= 1) ? dp[x1][y-1]+1 : INF, (y+1 <= n) ? dp[x1][y+1]+1 : INF});
                            if(temp != dp[x1][y]) flag = true;
                        }
                    }
                    for(int y1 = y;y1 >= 1;y1--) {
                        if(mp[x][y1] == 'x') {
                            break;
                        } else {
                            int temp = dp[x][y1];
                            dp[x][y1] = min({dp[x][y], (x-1 >= 1) ? dp[x-1][y1]+1 : INF, (x+1 <= n) ? dp[x+1][y1]+1 : INF});
                            if(temp != dp[x][y1]) flag = true;
                        }
                    }
                }
            }
        }
        if(!flag) break;
    }
    if(dp[xb][yb] == INF) {
        cout << -1;
    } else {
        cout << dp[xb][yb];
    }
    return 0;
}