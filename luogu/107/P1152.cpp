#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> input(n);
    vector<bool> ans(n, false);
    for(int i = 0;i < n;i++) {
        cin >> input[i];
    }
    for(int i = 0;i < n-1;i++) {
        int cha = abs(input[i+1] - input[i]);
        if(cha <= n-1) {
            ans[abs(input[i+1] - input[i])] = true;
        }
    }
    for(int i = 1;i < n;i++) {
        if(!ans[i]) {
            cout << "Not jolly";
            return 0;
        }
    }
    cout << "Jolly";
}