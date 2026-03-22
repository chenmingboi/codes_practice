#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, count = 0;
    //子集之和等于集合中所有元素之和乘以2^(元素数量-1)
    while(cin >> n) {
        sum += n;
        count++;
    }
    //这里pow返回的是double, 可能有精度损失
    //还可以用位移 cout << sum * (1LL << (count-1)) //1LL是 longlong
    //也可以用循环乘
    /*
        long long p = 1;
    for(int i = 0;i < count-1;i++) {
        p *= 2;
    }
    */
    cout << sum*(long long)pow(2, count-1);
    return 0;
}