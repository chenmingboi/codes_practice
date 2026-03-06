#include<bits/stdc++.h>
using namespace std;

int main()
{
    //c++中字符串可以进行拼接
    //但是两个char不可以进行拼接
    string in;
    cin >> in;
    cout << "  " << in << "\n" << " " << in + in + in << "\n" << in + in + in + in +in;
}