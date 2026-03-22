#include<bits/stdc++.h>
using namespace std;

//闰年的规则：能被四整除但是不能被100整除或者可以被400整除
bool isRun(int year) {
    if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        return true;
    }
    return false;
}
int main() {
    int x, y;
    cin >> x >> y;
    vector<int>result;
    for(int i = x;i <= y;i++) {
        if(isRun(i)) {
            result.push_back(i);
        }
    }
    cout << result.size() << endl;
    for(auto it : result) {
        cout << it << ' ';
    }
    return 0;
}