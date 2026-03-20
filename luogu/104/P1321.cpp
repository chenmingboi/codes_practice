#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;
    int len = str.length(), num_b = 0, num_g = 0;
    str += "xx";
    for(int i = 0;i < len;i++) {
        //关键在于是||，这样的话判断连续的这三个或四个字符中有没有有一个字符是boy或者girl的一部分，如果的话只加一
        if(str[i] == 'b' || str[i+1] == 'o' || str[i+2] == 'y') num_b++;
        if(str[i] == 'g' || str[i+1] == 'i' || str[i+2] == 'r' || str[i+3] == 'l') num_g++;
    }
    cout << num_b << endl << num_g;
    return 0;
}
// int main() {
//     string str;
//     cin >> str;
//     int len = str.length(), num_b = 0, num_g = 0;
//     for(int i = 0;i < len;i++) {
//         if(str[i] == 'b') {
//             if(i+2 < len && str[i+1] == 'o' && str[i+2] == 'y') {
//                 num_b++;str[i] = str[i+1] = str[i+2] = 'x';
//             }
//         } else if(str[i] == 'g') {
//             //这样会漏掉gir gi 这两种情况，这种情况应该计数为1，但是当前算法加上下面的for循环技术为2
//             if(i+3 < len && str[i+1] == 'i' && str[i+2] == 'r' && str[i+3] == 'l') {
//                 num_g++;str[i] = str[i+1] = str[i+2] = str[i+3] = 'x';
//             }

//         } 
//     }
//     for(int i = 0;i < len;i++) {
//         char ch = str[i];
//         if(ch == 'b'|| ch == 'o' || ch == 'y') {
//             num_b++;
//         } else if (ch == 'g' || ch == 'i' || ch == 'r' || ch == 'l') {
//             num_g++;
//         }
//     }
//     cout << num_b << endl << num_g;
//     return 0;
// }