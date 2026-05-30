#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if(n == 1) {
        cout << 0;
        return 0;
    }
    int ans = 0;
    //把原来已经有的VK组合设置为XX
    for(int i = 0;i < n-1;i++) {
        if(s[i] == 'V' && s[i+1] == 'K') {
            ans++;
            s[i] = 'X', s[i+1] = 'X';
        }
    }
    for(int i = 0;i < n-1;i++) {
        if((s[i] == 'V' && s[i+1] == 'V') || 
            (s[i] == 'K' && s[i+1] == 'K')) {
                ans++;
                break;
            }
    }
    cout << ans;
    return 0;
}