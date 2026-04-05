#include<bits/stdc++.h>
using namespace std;

bool judge(int a1, int a2, int a3, int a4) {
    vector<int>mugun{a1, a2, a3, a4};
    sort(mugun.begin(), mugun.end());
    a1 = mugun[0], a2 = mugun[1], a3 = mugun[2], a4 = mugun[3];
    if(a3 != a4) return false;
    if(a1 + a2 != a3) return false;
    return true;
}
int main() {
    int n, result = 0;
    cin >> n;
    vector<int>a(n, 0);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    //复杂度太高（n^4)
    unordered_map<string, bool> unik;
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            for(int k = 0;k < n;k++) {
                for(int h = 0;h < n;h++) {
                    if(i == j || i == k || i == h || j == k || j == h || k == h) continue;
                    vector<int>xulie{i, j, k, h};
                    sort(xulie.begin(), xulie.end());
                    int ie = xulie[0], je = xulie[1], ke = xulie[2], he = xulie[3];
                    string str = to_string(ie) + "#" + to_string(je) + "#" +
                    to_string(ke) + "#" + to_string(he);
                    if(unik[str]) continue;
                    unik[str] = true;
                    if(judge(a[i], a[j], a[k], a[h])) result++;
                }
            }
        }
    }
    cout << result;
}