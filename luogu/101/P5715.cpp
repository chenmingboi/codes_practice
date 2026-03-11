#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    /*简便方法1，可以使用排序
    int a[4];
    cin >> a[1] >> a[2] >> a[3];
    sort(a+1, a+4); //begin, end
    */
    /*简便方法2
    if(a > b) swap(a, b);
    if(b > c) swap(b, c); //到这一步最大的数字已经为c
    if(a > b) swap(a, b); //排mid和min的序就可以了
    */
    int min = 0, mid = 0, max = 0;
    if(a <= b && a <= c) {
        min = a;
        if(b <= c) {
            mid = b;
            max = c;
        } else if(c <= b) {
            mid = c;
            max = b;
        }
    } else if(b <= a && b <= c) {
        min = b;
        if(a <= c) {
            mid = a;
            max = c;
        } else if(c <= a) {
            mid = c;
            max = a;
        }
    } else if (c <= a && c <= b) {
        min = c;
        if(a <= b) {
            mid = a;
            max = b;
        } else if(b <= a) {
            mid = b;
            max = a;
        }
    }
    cout << min << ' ' << mid << ' ' << max;
    return 0;
}