#include<bits/stdc++.h>
using namespace std;

int main()
{
    int day = 0, max = 0;
    bool happy = true;
    for(int i = 1;i < 8;i++) {
        int a , b;
        cin >> a >> b;
        if(a + b > 8 && a + b > max) {
            happy = false;
            day = i;
            max = a + b;
        }
    }
    if(happy) {
        cout << 0;
    } else {
        cout << day;
    }
    return 0;
}