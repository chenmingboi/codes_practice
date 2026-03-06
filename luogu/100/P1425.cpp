#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0, b = 0, c = 0, d = 0;
    cin >> a >> b >> c >> d;
    int time = (c - a) * 60 + (d - b);
    int hour = time / 60, minute = time % 60;
    cout << hour << ' ' << minute;
    return 0;
}