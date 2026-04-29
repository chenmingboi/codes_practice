#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //此题考查XOR异或
    // x ^ x = 0, x ^ 0 = x 且 x ^ y ^ x = x ^ x ^ y
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans;
    return 0;
    //MLE
    // map<int, int>mp;
    // int n;
    // cin >> n;
    // for(int i = 0;i < n;i++) {
    //     int len;
    //     cin >> len;
    //     mp[len]++;
    //     mp[len] %= 2;
    // }
    // for(auto it : mp) {
    //     if(it.second == 1) {
    //         cout << it.first;
    //     }
    // }
    return 0;
}