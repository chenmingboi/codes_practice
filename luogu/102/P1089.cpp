#include<bits/stdc++.h>
using namespace std;

int main(){
    int cun = 0;
    int remain = 0;
    for(int i = 1;i <= 12;i++) {
        int cost = 0;
        cin >> cost;
        remain += 300;
        if(remain < cost) {
            cout << -i;
            return 0;
        } else {
            remain = remain - cost;
            if(remain >= 100) {
                cun += (remain / 100) * 100;
                remain %= 100;
            }
        }
    }
    int result = remain + 1.2 * cun;
    cout << result;
    return 0;
}