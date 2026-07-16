#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //使用官方库中的next_permutation来获取下一个字典序的数组
    int n, m;
    cin >> n >> m;
    vector<int>input(n);
    for(int i = 0;i < n;i++) cin >> input[i];
    for(int i = 0;i < m;i++) {
        next_permutation(input.begin(), input.end());
    }
    for(auto it : input) cout << it << ' ';
    return 0;
}