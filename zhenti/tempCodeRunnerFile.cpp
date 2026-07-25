#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string preorder, postorder;
    cin >> preorder >> postorder;
    int len = preorder.length();
    long long ans = 1LL;
    for(int i = 0;i < len-1;i++) {
        for(int j = len-1;j >= 1;j--) {
            if(preorder[i] == postorder[j] && preorder[i+1] == postorder[j-1]) {
                ans *= 2LL;
            }
        }
    }
    cout << ans;
    return 0;
}