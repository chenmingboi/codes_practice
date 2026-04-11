#include<bits/stdc++.h>
using namespace std;

//使用栈来进行模拟
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str;
    cin >> str;
    stack<string>st;
    stack<int>num;
    string cur = "";
    int len = str.size();
    for(int i = 0;i < len;i++) {
        if(str[i] >= 'A' && str[i] <= 'Z') {
            cur += str[i];
        } else if(str[i] == '[') {
            //进入新的一层先保存外层的已经拼好的字符
            st.push(cur);
            cur = "";
            i++;
            int k = 0;
            while(isdigit(str[i])) {
                k = k * 10 + (str[i] - '0');
                i++;
            }
            num.push(k);
            i--;
        } else if(str[i] = ']') {
            int repeat = num.top();
            num.pop();
            string prev = st.top();
            st.pop();
            string temp = "";//当前一层的重复拼接字符结果
            for(int i = 0;i < repeat;i++) {
                temp += cur;
            }
            cur = prev + temp;
        }
    }
    cout << cur;
    return 0;
}
// string str;
// int pos = 0;

// string solve() {
//     int len = str.length();
//     string res = "";
//     while(pos < len && str[pos] != ']') {
//         //只解析当前层级的内容，遇到]表示当前层级结束，返回当前层级的内容
//         //逐个解析每个字符
//         if(str[pos] >= 'A' && str[pos] <= 'Z') {
//             res += str[pos];
//             pos++;
//         } else if(str[pos] == '[') {
//             int num = 0;
//             pos++;//跳过当前的[
//             while(isdigit(str[pos])) {
//                 num = num * 10 + str[pos] - '0';
//                 pos++;
//             }
//             string inner = solve(); //递归解析括号里面的内容
//             for(int i = 0;i < num;i++) {
//                 res += inner;
//             }
//             pos++;//跳过]
//         }
//     }
//     return res;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> str;
//     cout << solve();
//     return 0;
// }


// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string str;
//     cin >> str;
//     int times = 1, len = str.length();
//     string rep;
//     //emmm 感觉可以用栈， 写下来感觉思路不是很清晰，看了下题解，可以使用递归
//     stack<int>num;
//     for (int i = 0;i < len;i++) {
//         string tempstr;
//         if(str[i] == '[') {
//             while(str[i] != ']') {
//                 if(str[i+1] >= '1' && str[i+1] <= '9') {
//                     int mul = 0;
//                     if(str[i+2] >= '1' && str[i+2] <= '9') {
//                         mul = (str[i+1] - '0') * 10 + (str[i+2] - '0');
//                     } else {
//                         mul = str[i+1] - '0';
//                     }
//                     num.push(mul);
//                 }
//                 if(str[i] >= 'A' && str[i] <= 'Z') {
//                     rep += str[i];
//                 }
//                 i++;
//             }
//         } else if(str[i] >= 'A' && str[i] <= 'Z') {
//             cout << str[i];
//         } 
//         if(str[i] == ']') {
//             for(int i = 0;i < num.top();i++) {
//                 tempstr += rep;
//             }
//             times /= num.top();
//             num.pop();
//         }
//         if(num.empty()) {
//             rep = "";
//             cout << tempstr;
//         } 
//     }
    
//     return 0;
// }