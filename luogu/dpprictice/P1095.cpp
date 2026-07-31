#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, s, t;
    cin >> m >> s >> t;
    //因为就算初始m为0,通过休息->闪现->休息这样的循环的
    //平均速度是快于跑步的所以优先通过上面的循环进行
    //然后再通过跑步进行更新,其实只需更新一次闪现过后且休息时间恢复的
    //魔法不够进行一次闪现的这段时间进行跑步即可
    //dp[i]表示时间i内能走的最远距离
    vector<int>dp(t+1, 0);
    for(int i = 1;i <= t;i++) {
        if(m < 10) {
            m += 4;
            dp[i] = dp[i-1];
        } else {
            dp[i] = dp[i-1] + 60;
            m -= 10;
        }
    }
    //跑步更新,虽然是从1到t遍历,其实只有从最后一次闪现的时间到t这段时间内的更新有效
    //其他时间段的更新都不如闪现的平均快
    for(int i = 1;i <= t;i++) {
        dp[i] = max(dp[i], dp[i-1] + 17);
    }
    int ans = t+1;
    for(int i = 1;i <= t;i++) {
        if(dp[i] >= s) {
            ans = i;
            break;
        }
    }
    if(ans == t+1) {
        cout << "No" << endl << dp[t];
    } else {
        cout << "Yes" << endl << ans;
    }
    return 0;
}