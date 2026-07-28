#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k, r;
    cin >> n >> m >> k >> r;
    vector<int>titime(n);
    vector<int>hwtime(m);
    vector<int>hwfen(m);
    for(int i = 0;i < n;i++) cin >> titime[i];
    for(int i = 0;i < m;i++) cin >> hwtime[i];
    for(int i = 0;i < m;i++) cin >> hwfen[i];
    //dp1[i]表示的是在时间i内最多获得的分数
    vector<int>dp1(r+1, 0);
    for(int i = 0;i < m;i++) {
        for(int j = r;j >= hwtime[i];j--) {
            dp1[j] = max(dp1[j], dp1[j-hwtime[i]] + hwfen[i]);
        }
    }
    //k分以上不包含k分算及格
    int lefttime = r;
    for(int i = 0;i <= r;i++) {
        if(dp1[i] > k) {
            lefttime -= i;
            break;
        }
    }
    //dp2[i]表示的是在时间i内最多刷几道题
    vector<int>dp2(lefttime+1, 0);
    for(int i = 0;i < n;i++) {
        for(int j = lefttime;j >= titime[i];j--) {
            dp2[j] = max(dp2[j], dp2[j-titime[i]] + 1);
        }
    }
    cout << dp2[lefttime];
    return 0;
}