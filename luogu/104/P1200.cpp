#include<bits/stdc++.h>
using namespace std;

int main() {
    string huixing, duiwu;
    cin >> huixing >> duiwu;
    int num1 = 1, num2 = 1;
    for(auto it : huixing) {
        num1 *= (it - 'A' + 1);
    }
    for(auto it : duiwu) {
        num2 *= (it - 'A' + 1);
    }
    num1 %= 47, num2 %= 47;
    if(num1 == num2) {
        cout << "GO";
    } else {
        cout << "STAY";
    }
    return 0;
}