#include<bits/stdc++.h>
using namespace std;

struct Node {
    int i;
    int j;
    int h;
};
bool comp(const Node& a, const Node& b) {
    return a.h < b.h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r, c;
    cin >> r >> c;
    vector<vector<int>>area(r+1, vector<int>(c+1));
    vector<vector<int>>dp(r+1, vector<int>(c+1, 1));
    vector<Node>nodes;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            cin >> area[i][j];
            nodes.push_back({i, j, area[i][j]});
        }
    }
    //从小到大排序保证遍历到比较大的节点的时候是用的其周围的节点的dp已经更新成正确的值
    sort(nodes.begin(), nodes.end(), comp);
    vector<int>dx = {-1, 0, 0, 1};
    vector<int>dy = {0, -1, 1, 0};
    for(auto [i, j, h] : nodes) {
        for(int k = 0;k < 4;k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni >= 1 && ni <= r && nj >= 1 && nj <= c
                && h < area[ni][nj]) {
                    dp[ni][nj] = max(dp[ni][nj], dp[i][j] + 1);
                }
        }
    }
    int ans = 0;
    for(int i = 1;i <= r;i++) {
        for(int j = 1;j <= c;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}
// struct Node {
//     int i;
//     int j;
//     int hight;
//     bool operator>(const Node& other) const { return hight > other.hight; }
// };

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int r, c;
//     cin >> r >> c;
//     vector<vector<int>>area(r+1, vector<int>(c+1));
//     vector<vector<int>>dp(r+1, vector<int>(c+1, 1));
//     int min_i = 1, min_j = 1;
//     for(int i = 1;i <= r;i++) {
//         for(int j = 1;j <= c;j++) {
//             cin >> area[i][j];
//             if(area[i][j] < area[min_i][min_j]) min_i = i, min_j = j;
//         }
//     }
//     vector<int>dx = {-1, 0, 0, 1};
//     vector<int>dy = {0, -1, 1, 0};
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({min_i, min_j, area[min_i][min_j]});
//     while(!q.empty()) {
//         auto [i, j, h] = q.top();
//         q.pop();
//         for(int k = 0;k < 4;k++) {
//             int ni = i + dx[k], nj = j + dy[k];
//             if(ni >= 1 && ni <= r && nj >= 1 && nj <= c
//                 && area[ni][nj] > area[i][j]) {
//                     if(dp[i][j] + 1 > dp[ni][nj]) {
//                         q.push({ni, nj, area[ni][nj]});
//                         dp[ni][nj] = dp[i][j] + 1;
//                     }
//                 }
//         }
//     }
//     int ans = 0;
//     for(int i = 1;i <= r;i++) {
//         for(int j = 1;j <= c;j++) {
//             ans = max(ans, dp[i][j]);
//         }
//     }
//     cout << ans;
//     return 0;
// }