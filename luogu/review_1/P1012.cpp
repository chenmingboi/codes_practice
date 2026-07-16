#include<bits/stdc++.h>
using namespace std;

bool comp(const int& num1, const int& num2) {
    //利用字符串拼接比大小来进行排序
    string s1 = to_string(num1), s2 = to_string(num2);
    if(s1 + s2 >= s2 + s1) {
        return true;
    } else {
        return false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        a[i] = num;
    }
    sort(a.begin(), a.end(), comp);
    for(int i = 0;i < n;i++) {
        cout << a[i];
    }
    return 0;
}