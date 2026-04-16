#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    vector<pair<int, int>>apple;
    for(int i = 0;i < n;i++) {
        int x, y; //x为高度，y为力气
        cin >> x >> y;
        if(x <= a + b) {
            apple.push_back({x, y});
        }
    }
    sort(apple.begin(), apple.end(), cmp);
    int result = 0;
    for(auto it : apple) {
        if(s - it.second >= 0) {
            s -= it.second;
            result++;
        } else {
            break;
        }
    }
    cout << result;
    return 0;
}