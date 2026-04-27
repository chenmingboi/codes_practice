#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    unordered_map<int, int>a;
    for(int i = 1;i <= n;i++) {
        int num;
        cin >> num;
        a[num] = i;
    }
    cin >> q;
    for(int i = 0;i < q;i++) {
        int m;
        cin >> m;
        cout << a[m] << endl;
    }
    return 0;
}