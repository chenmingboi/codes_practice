#include<bits/stdc++.h>
using namespace std;

void input(vector<int>& a, int s, int& sum) {
    for(int i = 0;i < s;i++) {
        cin >> a[i];
        sum += a[i];
    }
}

int fuxi(const vector<int>& a, int sum, int s) {
    //0/1背包问题
    //dp[i]表示在时间i内可以完成的最多的作业时间
    //比如说作业消耗为2, 3, 4 那么dp[4] = 4 占满时间
    vector<int>dp(sum/2+1, 0);
    for(int i = 0;i < s;i++) {
        //这里要逆序遍历，因为如果正序遍历的话dp[j-a[i]]可能已经使用a[i]更新了
        //此时如果在使用a[i]更新的话，那么a[i]就被使用了两次
        for(int j = sum/2;j >= a[i];j--){
            dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        }
    }
    return sum - dp[sum/2];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int s1, s2, s3, s4;
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    cin >> s1 >> s2 >> s3 >> s4;
    vector<int>a(s1), b(s2), c(s3), d(s4);
    input(a, s1, sum1);
    input(b, s2, sum2);
    input(c, s3, sum3);
    input(d, s4, sum4);
    //运用动态规划
    int ans = 0;
    ans += fuxi(a, sum1, s1);
    ans += fuxi(b, sum2, s2);
    ans += fuxi(c, sum3, s3);
    ans += fuxi(d, sum4, s4);
    cout << ans;
    return 0;
}