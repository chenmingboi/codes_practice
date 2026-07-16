#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<bool>chazhi(n, false);
    int left = 0, right = 0;
    bool flag = false;
    cin >> left;
    for(int i = 1;i < n;i++) {
        cin >> right;
        int index = abs(right-left);
        if(chazhi[index]) {
            flag = true;
            break;
        }
        left = right;
        chazhi[index] = true;
    }
    if(flag) {
        cout << "Not jolly";
    } else {
        cout << "Jolly";
    }
    return 0;
}