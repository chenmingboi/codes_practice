// #include<bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a, b, c;
//     cin >> a >> b >> c;
    
//     // 排序：a ≤ b ≤ c
//     if(a > b) swap(a, b);
//     if(b > c) swap(b, c);
//     if(a > b) swap(a, b);
//     int a_2 = a * a;
//     int b_2 = b * b;
//     int c_2 = c * c;
//     if(a + b <= c) {
//         cout << "Not triangle";
//         return 0;
//     }
    
//     // 判断三角形类型
//     if(a_2 + b_2 == c_2) {
//         cout << "Right triangle";
//     } else if(a_2 + b_2 > c_2) {
//         cout << "Acute triangle";
//     } else {
//         cout << "Obtuse triangle";
//     }
    
//     if(a == b || b == c || a == c) {  
//         cout << endl << "Isosceles triangle";
//     }
//     if(a == b && b == c) {
//         cout << endl << "Equilateral triangle";
//     }
//     return 0;
// }
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    if(a > b) swap(a ,b);
    int a_2 = pow(a, 2), b_2 = pow(b, 2), c_2 = pow(c, 2);
    if(a + b <= c) {
        cout << "Not triangle";
    } else if(a_2 + b_2 == c_2) {
        cout << "Right triangle";
        if(a == b) {
            cout << endl << "Isosceles triangle";
        }
    } else if(a_2 + b_2 > c_2) {
        cout << "Acute triangle";
        if(a == b || b == c) {
            cout << endl << "Isosceles triangle";
        }
        if(a == b && b == c) {
            cout << endl << "Equilateral triangle";
        }
    } else if(a_2 + b_2 < c_2) {
        cout << "Obtuse triangle";
        if(a == b) {
            cout << endl << "Isosceles triangle";
        }
    }
    return 0;
}