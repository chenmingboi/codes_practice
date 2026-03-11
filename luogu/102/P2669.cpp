#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int n = 1, i = 1;
    int result = 0;
    while(n <= k) {
        result += (i*i);
        i++;
        n += i;
    }
    if(n > k) {
        result += (k - n + i) * i;
    }
    cout << result;
}