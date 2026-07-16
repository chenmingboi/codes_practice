#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(int i = 0;i < n-1;i++) {
        if(s[i] == 'V' && s[i+1] == 'K') {
            ans++; s[i] = 'X', s[i+1] = 'X';
        }
    }
    for(int i = 0;i < n-1;i++) {
        if((s[i] == 'V' && s[i+1] != 'X') || 
            (s[i+1] == 'K' && s[i] != 'X')) {
            ans++;
            break;
        }
    }
    cout << ans;
    return 0;
}