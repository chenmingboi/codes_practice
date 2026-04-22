#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int num = 0, index = 1, tempn = n;
    vector<bool>active(n+1,true);
    while(tempn) {
        if(active[index]) {
            num++;
        }
        if(num == m) {
            active[index] = false;
            cout << index << ' ';
            num = 0;
            tempn--;
        }
        index++;
        if(index > n) {
            index = 1;
        }
    }
    return 0;
}