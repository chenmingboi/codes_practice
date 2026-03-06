#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n = 0, res = 0;
    cin >> n;
    if(((n % 4 == 0) && (n % 100 != 0)) || ((n % 100 == 0) && (n % 400 == 0))){
        res = 1;
    }
    cout << res;
    return 0;
}