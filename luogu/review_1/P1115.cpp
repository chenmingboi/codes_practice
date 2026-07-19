#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = INT_MIN;
    cin >> n;
    //每个数字有两个选择，一个是加入之前构成的子串
    //另一个是自己构成一个子串的起点
    //关键是比较加入之前的和自己新成立一个子串哪个的值更大
    int tempans = 0;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        tempans = max(num, tempans + num);
        ans = max(ans, tempans);
    }
    cout << ans;
    return 0;
}