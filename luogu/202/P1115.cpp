#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = INT_MIN, cur_max = 0;//按理来说cur_max应该初始化为第一个数字
    cin >> n;
    cin >> cur_max;
    for(int i = 1;i < n;i++) {
        int num;
        cin >> num;
        //选择加上这个num还是另起一个合法序列
        cur_max = max(num, cur_max+num);
        ans = max(ans, cur_max);
    }
    cout << ans;
    return 0;
}