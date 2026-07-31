#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct book {
    int h;
    int w;
};

bool comp(const book& a, const book& b) {
    return a.h < b.h;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<book>books(n);
    for(int i = 0;i < n;i++) {
        int h, w;
        cin >> h >> w;
        books[i] = {h, w};
    }
    sort(books.begin(), books.end(), comp);
    //需要保留的书本数目
    int m = n-k;
    //dp[i][j]表示前i本书中留下j本书,其中第i本必须保留
    vector<vector<int>>dp(n+1, vector<int>(m+1, INF));
    for(int i = 0;i < n;i++) {
        //保留一本书的不整齐度为0
        dp[i][1] = 0;
    }
    for(int i = 1;i < n;i++) {
        //j是留下的书的数量
        for(int j = 1;j <= m;j++) {
            for(int p = i-1;p >= j-2 && p >= 0;p--) {
                dp[i][j] = min(dp[p][j-1] + abs(books[p].w - books[i].w), dp[i][j]);
            }
        }
    }
    int ans = INF;
    for(int i = m-1;i < n;i++) ans = min(ans, dp[i][m]);
    cout << ans;
    return 0;

}