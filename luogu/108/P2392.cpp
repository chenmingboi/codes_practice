#include<bits/stdc++.h>
using namespace std;

void input(int s, vector<int>& shuzu, int& sum) {
    for(int i = 0;i < s;i++) {
        cin >> shuzu[i];
        sum += shuzu[i];
    }
    return;
}

void fuxi(int s, const vector<int>& time, int& result, int sum) {
    //这里的sum/2就相当于背包大小
    vector<int>dp(1202, 0);
    //这里dp计算的是比较小的一部分，总时间应该是加另一个大脑中比较长的部分（略大于sum/2）
    for(int i = 0;i < s;i++) {
        for(int j = sum/2;j >= time[i];j--) {
            //这里的time[i]既对应了weight，也对应了value
            dp[j] = max(dp[j], dp[j-time[i]] + time[i]);
        }
    }
    result += sum - dp[sum/2];
    return ;
}

int main() {
    int s1, s2, s3, s4, result = 0,
        sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
    cin >> s1 >> s2 >> s3 >> s4;
    vector<int>a(s1, 0), b(s2, 0), c(s3, 0), d(s4, 0);
    //在当前这一科目里，从若干题中选一些题，使得总耗时不超过k,所能达到的最大耗时
    // 0/1背包问题

    input(s1, a, sum1);
    input(s2, b, sum2);
    input(s3, c, sum3);
    input(s4, d, sum4);

    fuxi(s1, a, result, sum1);
    fuxi(s2, b, result, sum2);
    fuxi(s3, c, result, sum3);
    fuxi(s4, d, result, sum4);
    cout << result;
    return 0;
}