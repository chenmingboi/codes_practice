#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

bool findelement(const vector<int>& a, int b, int c, int d) {
    bool flag1 = false, flag2 = false, flag3 = false;
    if(find(a.begin(), a.end(), b) != a.end()) flag1 = true;
    if(find(a.begin(), a.end(), c) != a.end()) flag2 = true;
    if(find(a.begin(), a.end(), d) != a.end()) flag3 = true;
    return flag1 || flag2 || flag3;
}

bool findsingle(const vector<int>& a, int b) {
    return find(a.begin(), a.end(), b) != a.end();
}

void addelement(vector<int>&a, const vector<int>& b) {
    for(auto it : b) {
        if(find(a.begin(), a.end(), it) == a.end()) a.push_back(it);
    }
}

int main() {
    //自己写的方法差一个样例，主要是由于一个位置可能有多个最优解，此时到达的方向可能是不同的
    //我写的只记录了最后一个更新，但是正确的做法应该是都进行记录
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
    vector<vector<int>>dp(n+2, vector<int>(n+2, INF));
    //1代表向下，2代表向上，3代表向左，4代表向右
    vector<vector<vector<int>>>dir(n+2, vector<vector<int>>(n+2));
    dp[xa][ya] = 0;
    if(xa+1 <= n) {
        if(mp[xa+1][ya] != 'x') dp[xa+1][ya] = 0, dir[xa+1][ya].push_back(1);
    }
    if(xa-1 >= 1) {
        if(mp[xa-1][ya] != 'x') dp[xa-1][ya] = 0, dir[xa-1][ya].push_back(2);
    }
    if(ya-1 >= 1) {
        if(mp[xa][ya-1] != 'x') dp[xa][ya-1] = 0, dir[xa][ya-1].push_back(3);
    }
    if(ya+1 <= n) {
        if(mp[xa][ya+1] != 'x') dp[xa][ya+1] = 0, dir[xa][ya+1].push_back(4);
    }
    bool flag = false;
    for(int i = 0;i < 2*n;i++) {
        flag = false;
        for(int x = 1;x <= n;x++) {
            for(int y = 1;y <= n;y++) {
                if(mp[x][y] == 'x') continue;
                if(x-1 >= 1 && findelement(dir[x-1][y], 1, 3, 4)) {
                    int cost = 1;
                    if(findsingle(dir[x-1][y], 1)) cost = 0;
                    if(dp[x-1][y] + cost < dp[x][y]) {
                        dp[x][y] = dp[x-1][y] + cost;
                        dir[x][y].clear();
                        dir[x][y].push_back(1);
                        flag = true;
                    } else if(dp[x-1][y] + cost == dp[x][y]) {
                        dir[x][y].push_back(1);
                    }
                } 
                if(x+1 <= n && findelement(dir[x+1][y], 2, 3, 4)) {
                    int cost = 1;
                    if(findsingle(dir[x+1][y], 2)) cost = 0;
                    if(dp[x+1][y] + cost < dp[x][y]) {
                        dp[x][y] = dp[x+1][y] + cost;
                        dir[x][y].clear();
                        dir[x][y].push_back(2);
                        flag = true;
                    } else if(dp[x+1][y] + cost == dp[x][y]) {
                        dir[x][y].push_back(2);
                    }
                }
                if(y-1 >= 1 && findelement(dir[x][y-1], 1, 2, 4)) {
                    int cost = 1;
                    if(findsingle(dir[x][y-1], 4)) cost = 0;
                    if(dp[x][y-1] + cost < dp[x][y]) {
                        dp[x][y] = dp[x][y-1] + cost;
                        dir[x][y].clear();
                        dir[x][y].push_back(4);
                        flag = true;
                    } else if (dp[x][y-1] + cost == dp[x][y]) {
                        dir[x][y].push_back(4);
                    }
                }
                if(y+1 <= n && findelement(dir[x][y+1], 1, 2, 3)) {
                    int cost = 1;
                    if(findsingle(dir[x][y+1], 3)) cost = 0;
                    if(dp[x][y+1] + cost < dp[x][y]) {
                        dp[x][y] = dp[x][y+1] + cost;
                        dir[x][y].clear();
                        dir[x][y].push_back(3);
                        flag = true;
                    } else if(dp[x][y+1] + cost == dp[x][y]) {
                        dir[x][y].push_back(3);
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