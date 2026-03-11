#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x = 0, n = 0;
    cin >> x >> n;
    int result = 0, day_p = 250;
    if(x + n - 1 <= 7) {
        result = max(((x + n - 1 >= 5) ? (5 - x + 1) : n) * day_p, 0);
    } else {
        result = max((5 - x + 1) * day_p, 0) + ((n - 8 + x) / 7) * 250 * 5 + min(((n - 8 + x) % 7) * 250, 250 * 5);
    }
    cout << result;
    return 0;
}