#include<bits/stdc++.h>
using namespace std;

double a, b, c, d;
double f(const double& x) {
    double result = 0;
    result = a * x * x * x + b * x * x + c * x + d;
    return result;
}

double jie(const double& l, const double& r) {
    double mid = l + (r - l) / 2;
    if((r - l) / 2 <= 1e-4) {
        return mid;
    }
    if(fabs(f(mid)) < 1e-8) {
        return mid;
    }
    if(f(mid) * f(r) < 0 || f(mid) * f(l) > 0) {
        return jie(mid, r);
    }
    if(f(mid) * f(l) < 0 || f(mid) * f(r) > 0) {
        return jie(l, mid);
    }
    return mid;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> a >> b >> c >> d;
    // double x1, x2, x3;
    // x1 = jie(-100, 100);//不能用这个方法，因为一个区间包含三个根的时候两个边界可能是同号的
    // x2 = jie(x1 + 1, 100);
    // x3 = jie(-100, x1-1);
    //问了下gpt，因为三个解绝对值大小差>= 1所以在长度为1的区间中必然只有一个解，所以可以遍历从-100到100
    //之间长度为1的每个区间来找解
    for(double l = -100, r = -99;l <= 99 && r <= 100;l++, r++) {
        if(f(l) * f(r) > 0) continue;
        if(f(l) * f(r) < 0) {
            cout << fixed << setprecision(2) << jie(l, r) << ' ';
        } else if(f(l) * f(r) == 0) {
            if(f(l) == 0) {
                cout << fixed << setprecision(2) << l << ' ';
            }
            //这里不判断右侧的端点，因为在下个区间会判断左侧，如果解是端点，将会被打印两次
        }
    }
    return 0;
}