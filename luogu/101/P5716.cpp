#include<bits/stdc++.h>
using namespace std;

int main()
{
    int y = 0, m = 0;
    cin >> y >> m;
    bool isRun = false;
    if((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0)) {
        isRun = true;
    }

    /*简便方法：将月份的天数写入数组，这样就不用一个一个判断了
    int m[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};//每个月的天数
    if(rn(n))//如果是闰年，则二月有29天
		m[2]=29;
	cout<<m[y];//输出第y月，这里不需要特判，因为如果是闰年前面已经修改过天数了。
    */
    switch (m)
    {
    case 1:
        /* code */
        cout << "31";
        break;
    case 2:
        if(isRun) {
            cout << "29";
        } else {
            cout << "28";
        }
        break;
    case 3:
        cout << 31;
        break;
    case 4:
        cout << 30;
        break;
    case 5:
        cout << 31;
        break;
    case 6:
        cout << 30;
        break;
    case 7:
        cout << 31;
        break;
    case 8:
        cout << 31;
        break;
    case 9:
        cout << 30;
        break;
    case 10:
        cout << 31;
        break;
    case 11:
        cout << 30;
        break;
    case 12:
        cout << 31;
        break;
    default:
        break;
    }
    return 0;
}