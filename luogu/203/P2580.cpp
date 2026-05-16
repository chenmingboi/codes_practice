#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, int>cnt;
    for(int i = 0;i < n;i++) {
        string name;
        cin >> name;
        cnt[name] = 2; //表示存在
    }
    int m;
    cin >> m;
    for(int i = 0;i < m;i++) {
        string name;
        cin >> name;
        if(cnt[name] == 2) {
            //正确且第一次出现
            cout << "OK" << endl;
            cnt[name] = 1;
        } else if (cnt[name] == 1) {
            cout << "REPEAT" << endl; 
        } else if (cnt[name] == 0) {
            cout << "WRONG" << endl;
        }
    }
    return 0;
}