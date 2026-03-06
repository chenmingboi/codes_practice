#include<bits/stdc++.h>
using namespace std;

int main()
{
    float m = 0.0, h = 0.0;
    cin >> m >> h;
    float result = m / pow(h, 2);
    if(result < 18.5) {
        cout << "Underweight";
    } else if(result >= 18.5 && result < 24) {
        cout << "Normal";
    } else if (result >= 24) {
        cout << result << endl << "Overweight";
    }
    return 0;
}