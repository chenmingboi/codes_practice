#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long ans = 1LL;
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.length();
    for(int i = 0;i < len-1;i++) {
        for(int j = len-1;j > 0;j--){
            //s1[i]对应的字母不一定是在s2的len-1-i出现，所以要对s2进行遍历
            if(s1[i] == s2[j] && s1[i+1] == s2[j-1]) ans *= 2LL;
        }
    }
    cout << ans;
    return 0;
}