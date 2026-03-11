#include<bits/stdc++.h>
using namespace std;

int main()
{
    int total = 0;
    cin >> total;
    double sum = 0.0;
    double p1 = 0.4463, p2 = 0.4663, p3 = 0.5663;
    if(total > 400) {
        sum = 150 * p1 + 250 * p2 + (total - 400) * p3;
    } else if(total > 150) {
        sum = 150 * p1 + (total - 150) * p2;
    } else if(total <= 150) {
        sum = total * p1;
    }
    // cout << fixed << setprecision(1) << sum; // 这种写法会使得后面输出也是小数点后一位
    // printf("%.1f", sum);//同样也是小数点后一位
    /*
    方法三
    使用ostringstream
    ostringstream oss;
    oss << fixed << setprecision(1) << sum;
    cout << oss.str();
    */
    ostringstream oss;
    oss << fixed << setprecision(1) << sum;
    cout << oss.str();
    return 0;
}