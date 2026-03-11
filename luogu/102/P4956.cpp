#include<bits/stdc++.h>
using namespace std;

int main(){
    // (7x + 21k) * 52;   1092k
    int n;
    cin >> n;
    int k = 0, x = 0;
    for(int i = 1; ;i++){
        if((n - 1092 * i) % 364 == 0 && (n - 1092 * i) >= 0) {
            k = i;
            x = (n - 1092 * i) / 364;
            if(x > 100) {
                continue;
            } else {
                break;
            }
        }
    }
    cout << x << endl << k;
    return 0;
}