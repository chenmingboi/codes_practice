#include<bits/stdc++.h>
using namespace std;

int yushuhe(int num) {
    int ans = 0;
    for(int i = 1;i < num;i++) {
        if(num % i == 0) ans += i;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s;
    cin >> s;
    vector<int>dp(s+1, 0);
    vector<int>a(s+1);
    for(int i = 1;i <= s;i++) a[i] = yushuhe(i);
    //dp[i]表示和为i的所有数的约数之和
    //a[i]表示选取某个数所得的价值
    //s为背包容量同时也为所选物体个数
    for(int i = 1;i <= s;i++) {
        //是0/1背包因为选取的是不同的正整数，每个数字只能选择一次
        for(int j = s;j >= i;j--) {
            //i同时也为所选物品的重量
            dp[j] = max(dp[j], dp[j-i] + a[i]);
        }
    }
    cout << dp[s];
    return 0;
}