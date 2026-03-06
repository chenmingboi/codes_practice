#include<bits/stdc++.h>
using namespace std;

int main()
{
    int id = -1;
    cin >> id;
    if(id == 1) {
        cout << "I love Luogu!";
    } else if (id == 2) {
        cout << 6 << ' ' << 4;
    } else if (id == 3) {
        cout << 3 << endl << 12 << endl << 2;
    } else if (id == 4) {
        cout<<166.667;
    } else if (id == 5) {
        cout << 480 / 32;
    } else if (id == 6) {
        cout << sqrt(36 + 81);
    } else if (id == 7) {
        cout << 110 << endl << 90 << endl << 0;
    } else if (id == 8) {
        double pi = 3.141593;
        cout << 2 * pi * 5 << endl << pi * 25 << endl << 4 * pi * 125 / (3 * 1.0);
    } else if (id == 9) {
        cout << (((1 + 1) * 2 + 1) * 2 + 1) * 2;
    } else if (id == 10) {
        cout << 9;
    } else if (id == 11) {
        cout << 100.0/3;
    } else if (id == 12) {
        cout << 'M' - 'A' + 1 << endl << char('A' + 17);
    } else if (id == 13) {
        int r1=4,r2=10;
        double pi=3.141593;
        double v=4.0/3*pi*r1*r1*r1+4.0/3*pi*r2*r2*r2;
        v=pow(v,1.0/3);
        printf("%.0lf\n",v);// %.0表示0位小数（不显示小数部分）
    } else if (id == 14) {
        cout << 50;
    }
    return 0;
}