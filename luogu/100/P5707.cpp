#include<bits/stdc++.h>
using namespace std;

int main()
{
    int s = 0, v = 0;
    cin >> s >> v;
    int time = (s % v == 0 ? s/v : s/v+1) + 10;
    //这里也可以用time = (s + v - 1) / v + 10;所得结果和以上式子相同
    //或者也可以用ceil(s/v) + 10;
    int res_time = ((480 - time) >= 0) ? (480-time) : (1920 - time);
    int hour = res_time / 60, minute = res_time % 60;
    string hour_str, minute_str;
    if(hour < 10) {
        hour_str = '0' + to_string(hour); //运用to_string函数将其他类型转化为string类型
    } else {
        hour_str = to_string(hour);
    }
    if(minute < 10) {
        minute_str = '0' + to_string(minute);
    } else {
        minute_str = to_string(minute);
    }
    cout << hour_str << ':' << minute_str;
    return 0;
}