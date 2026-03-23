#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m, pos = 0;
    cin >> n >> m;
    vector<pair<int, string>>circle;
    for(int i = 0;i < n;i++) {
        int dir; string job;
        cin >> dir >> job;
        circle.push_back({dir, job});
    }
    for(int i = 0;i < m;i++) {
        int a, s;
        cin >> a >> s;
        if((a == 0 && circle[pos].first == 0) ||
            (a == 1 && circle[pos].first == 1)) {
            //顺时针方向
            pos -= s;
            pos = (pos + n) % n;
        } else {
            //逆时针方向
            pos += s;
            pos = pos % n;
        }
    }
    cout << circle[pos].second;
    return 0;
}