#include<bits/stdc++.h>
using namespace std;

struct Node{
    int x;
    int y;
    int h;
};

bool cmp(const Node& a, const Node& b) {
    return a.h < b.h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<vector<int>>mp(r+2, vector<int>(c+2));
    vector<Node>nodes;
    int x = 1, y = 1, temp = INT_MIN;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            cin >> mp[i][j];
            nodes.push_back({i, j, mp[i][j]});
        }
    }
    vector<vector<int>>dp(r+2, vector<int>(c+2, 1));
    sort(nodes.begin(), nodes.end(), cmp);
    vector<int>dx = {-1, 0, 0, 1};
    vector<int>dy = {0, -1, 1, 0};
    for(auto [x, y, h] : nodes) {
        for(int i = 0;i < 4;i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if(nx >= 1 && nx <= r && ny >= 1 && ny <= c
                && mp[nx][ny] > h) {
                    dp[nx][ny] = max(dp[nx][ny], dp[x][y] + 1);
                }
        }
    }
    int ans = INT_MIN;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}