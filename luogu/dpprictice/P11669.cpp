#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n+1), b(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) cin >> b[i];
    vector<int>pre(n+1,0);
    for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + (a[i] == b[i]);
    int ini = pre[n];
    vector<int>ans(n+1, 0);
    //枚举中心点
    //奇数个区间
    for(int i = 1;i <= n;i++) {
        //反转过后区间的匹配数
        int s = (a[i] == b[i]);
        //delta记录反转过后区间中的匹配数和原来区间匹配数的差值
        int delta = 0;
        ans[ini]++;
        //左右各扩展一个，只需要考虑新添加的一对元素然后再加上上一个短区间内的s即可
        for(int j = 1;i+j <= n && i-j >= 1;j++) {
            int left = i-j, right = i+j;
            //反转left和right区间后left和right区间的匹配数
            s += (a[i+j] == b[i-j]) + (a[i-j] == b[i+j]);
            delta = (s - (pre[i+j] - pre[i-j-1]));
            ans[ini + delta]++;
        }
    }
    //偶数区间
    for(int i = 1;i < n;i++) {
        //以[i,i+1]为初始区间
        int s = 0, delta = 0;
        for(int j = 0;i+1+j <= n && i-j >= 1;j++) {
            int left = i-j, right = i+1+j;
            s += (a[left] == b[right]) + (a[right] == b[left]);
            delta = s - (pre[right] - pre[left-1]);
            ans[ini + delta]++;
        }
    }
    for(int i = 0;i <= n;i++) cout << ans[i] << '\n';
    return 0;
}