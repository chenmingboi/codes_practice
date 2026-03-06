#include<bits/stdc++.h>
using namespace std;
int main()
{
    char in;
    cin >> in;
    // 'A' - 'a' = -32
    cout << char(in - 32); // 这里注意要转化为char，不然输出的是对应的ascall码数值
    return 0;
}