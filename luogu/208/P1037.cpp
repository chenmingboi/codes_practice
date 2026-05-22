#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

vector<int> large_mul(const vector<int>& a, const int& b) {
    int len1 = a.size();
    vector<int>result(len1+1, 0);
    for(int i = 0;i < len1;i++) {
        result[i] = a[i] * b;
    }
    int jinwei = 0;
    for(int i = 0;i < len1+1;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    while(result.back() == 0 && !result.empty()) result.pop_back();
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n;
    int k;
    cin >> n >> k;
    //dist[i][j] == 1 表示i可以变成j,INF表示不能变成
    vector<vector<int>>dist(11, vector<int>(11, INF));
    for(int i = 0;i <= 9;i++) {
        dist[i][i] = 1;
    }
    for(int i = 0;i < k;i++) {
        int x, y;
        cin >> x >> y;
        dist[x][y] = 1;
    }
    for(int m = 0;m <= 9;m++) {
        for(int i = 0;i <= 9;i++) {
            for(int j = 0;j <= 9;j++) {
                if(dist[i][m] != INF && dist[m][j] != INF) {
                    dist[i][j] = 1; //表示i可以变成j
                }
            }
        }
    }
    vector<int>cnt(11, 0);
    for(int i = 0;i <= 9;i++) {
        for(int j = 0;j <= 9;j++) {
            if(dist[i][j] == 1) cnt[i]++;
        }
    }
    vector<int>ans(1, 1);
    for(auto it : n) {
        ans = large_mul(ans, cnt[it-'0']);
    }
    int len = ans.size();
    for(int i = len-1;i >= 0;i--) cout << ans[i];
    return 0;
}