#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    double sum = 0;
    int result = 0;
    while(sum <= k) {
        result++;
        sum += 1.0/result;
    }
    cout << result;
    return 0;
}