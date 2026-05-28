#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, start;
    cin >> n >> start;
    vector<int>input(n);
    for(int i = 0;i < n;i++) cin >> input[i];
    for(int i = 0;i < start;i++) {
        next_permutation(input.begin(), input.end());
    }
    for(int i = 0;i < n;i++) {
        cout << input[i] << ' ';
    }
    return 0;
}