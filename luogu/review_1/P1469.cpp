#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 0;i < n;i++) {
        int x;
        cin >> x;
        ans ^= x;
    }
    cout << ans;
    //MLE
    // unordered_map<int, int>a;
    // for(int i = 0;i < n;i++) {
    //     int len = 0;
    //     cin >> len;
    //     a[len]++;
    //     a[len] %= 2;
    // }
    // for(auto it : a) {
    //     if(it.second == 1) {
    //         cout << it.first;
    //         break;
    //     }
    // }
    return 0;
}