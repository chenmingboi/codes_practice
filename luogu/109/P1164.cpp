#include<bits/stdc++.h>
using namespace std;


//0/1背包问题
//价格看成容量

int n, m, result = 0;
vector<int>a;
//每个菜只有点或者不点
//TLE
// void digui(int sum, int i) {
//     if(sum == m) {
//         result++;
//         return;
//     }
//     if(i >= n) return;
//     //点该菜
//     digui(sum+a[i], i+1);
//     //不点
//     digui(sum, i+1);
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    for(int i = 0;i < n;i++) {
        int price;
        cin >> price;
        a.push_back(price);
    }
    // digui(0, 0);
    vector<int>dp(m+1, 0);
    dp[0] = 1;//口袋里为0元的时候只有一种点菜方案，就是不点菜
    for(int i = 0;i < n;i++) {
        //针对每个菜分析
        for(int j = m;j >= a[i];j--) {
            dp[j] += dp[j-a[i]];
        }
    }
    cout << dp[m];
    return 0;
}