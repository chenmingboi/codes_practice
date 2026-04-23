#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, result = 0;
    cin >> m >> n;
    list<int>mem;
    for(int i = 0;i < n;i++) {
        int word;
        cin >> word;
        if(find(mem.begin(), mem.end(), word) == mem.end()) {
            //没找到
            result++;
            if(mem.size() >= m) {
                mem.pop_front();
            }
            mem.push_back(word);
        }
    }
    cout << result;
    return 0;
}