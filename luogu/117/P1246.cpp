#include<bits/stdc++.h>
using namespace std;

int c_math(int a, int b) {
    // C_a ^ (b)
    int ans = 0, fenmu = 1, fenzi = 1;
    for(int i = 1;i <= b;i++) {
        fenmu *= i;
    }
    for(int i = a;i >= a-b+1;i--) {
        fenzi *= i;
    }
    ans = fenzi / fenmu;
    return ans;
}
int main() {
    //利用组合数求解
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string word;
    cin >> word;
    int len = word.length(), ans = 0;
    //判断是否是合法字符（递增）
    for(int i = 0;i < len-1;i++) {
        if(word[i + 1] <= word[i]) {
            cout << 0;
            return 0;
        }
    }
    if(len > 6) {
        cout << 0;
        return 0;
    }
    //先加长度比word小的单词数量
    for(int i = 1;i < len;i++) {
        ans += c_math(26, i);
    }
    //相同长度的
    char prev_ch = 'a';
    for(int i = 0;i < len;i++) {
        char cur = word[i];
        for(char ch = prev_ch;ch < cur;ch++) {
            ans += c_math('z'-ch, len-i-1);
        }
        prev_ch = cur+1;
    }
    cout << ans+1;
    return 0;
}