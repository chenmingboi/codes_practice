#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int max_num = INT_MIN, min_num = INT_MAX;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        max_num = max(max_num, num);
        min_num = min(min_num, num);
    }
    cout << max_num - min_num;
    return 0;
}