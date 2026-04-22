#include<bits/stdc++.h>
using namespace std;

string toString(int i, int j) {
    string result;
    result = to_string(i) + "#" + to_string(j);
    return result;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    unordered_map<string, int>kuizi;
    for(int ci = 0;ci < q;ci++) {
        int op;
        cin >> op;
        if(op == 1) {
            int i, j, k;
            cin >> i >> j >> k;
            kuizi[toString(i,j)] = k;
        } else if(op == 2) {
            int i, j;
            cin >> i >> j;
            cout << kuizi[toString(i, j)] << endl;
        }
    }
    return 0;
}