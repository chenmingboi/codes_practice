#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a ,b);
    if(b > c) swap(b ,c);
    if(a > b) swap(a, b);
    for(int i = 0; i < 3;i++){
        char res;
        cin >> res;
        if(res == 'A'){
            cout << a << ' ';
        } else if(res == 'B') {
            cout << b << ' ';
        } else if(res == 'C') {
            cout << c << ' ';
        }
    }
    return 0;
}