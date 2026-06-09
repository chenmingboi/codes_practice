#include<bits/stdc++.h>
using namespace std;

void pop_zero(vector<int>& a) {
    if(a.size() <= 1) return;
    while(a.back() == 0 && a.size() != 1) a.pop_back();
}
/*
    比较两个反着的数字a和b的大小
    返回1表示 a > b
    返回0表示 a == b
    返回-1表示a < b
*/
int comp(vector<int>a, vector<int>b) {
    pop_zero(a);
    pop_zero(b);
    if(a.size() > b.size()) {
        return 1;
    } else if(a.size() < b.size()) {
        return -1;
    }
    int len = a.size();
    for(int i = len-1;i >= 0;i--) {
        if(a[i] > b[i]) {
            return 1;
        } else if(a[i] == b[i]){
            continue;
        } else if(a[i] < b[i]) {
            return -1;
        }
    }
    return 0;
}

//b < 10 && b >= 1
vector<int> mul_small(const vector<int>& a, const int& b) {
    int len = a.size();
    vector<int>result(len+1,0);
    for(int i = 0;i < len;i++) {
        result[i] = a[i] * b;
    }
    int jinwei = 0;
    for(int i = 0;i < len+1;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    pop_zero(result);
    return result;
}

vector<int> sub_large(const vector<int>& a, const vector<int>& b) {
    //默认a > b;
    int len1 = a.size(), len2 = b.size();
    vector<int>result(len1, 0);
    for(int i = 0;i < len1;i++) {
        if(i < len2) {
            result[i] = a[i] - b[i];
        } else {
            result[i] = a[i];
        }
    }
    int jiewei = 0;
    for(int i = 0;i < len1;i++) {
        result[i] -= jiewei;
        if(result[i] < 0) {
            jiewei = 1;
            result[i] += 10;
        } else {
            jiewei = 0;
        }
    }
    pop_zero(result);
    return result;
}

//这里默认 a 和 b 也是反着的
pair<vector<int>, vector<int>> div_large(const vector<int>& a, const vector<int>& b) {
    vector<int>shang, yushu;
    int len1 = a.size(), len2 = b.size();
    for(int i = len1-1;i >= 0;i--) {
        yushu.push_back(a[i]);
        reverse(yushu.begin(), yushu.end());
        if(comp(yushu, b) == -1) {
            reverse(yushu.begin(), yushu.end());
            shang.push_back(0);
            continue;
        } else {
            int num = 0;
            vector<int>temp;
            for(int j = 1;j <= 10;j++) {
                temp = mul_small(b, j);
                //这里要特殊注意num = 9是否能取到
                if(comp(temp, yushu) <= 0) {
                    num = j;
                } else {
                    break;
                }
            }
            shang.push_back(num);
            temp = mul_small(b, num);
            yushu = sub_large(yushu, temp);
        }
        reverse(yushu.begin(), yushu.end());
    }
    //最终余数和shang均为正着排列, 需要反过来去0
    reverse(shang.begin(), shang.end());
    pop_zero(shang);
    reverse(yushu.begin(), yushu.end());
    pop_zero(yushu);
    return {yushu, shang};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    vector<int>a1, b1, shang;
    int len1 = a.length(), len2 = b.length();
    for(int i = len1-1;i >= 0;i--) a1.push_back(a[i]-'0');
    for(int i = len2-1;i >= 0;i--) b1.push_back(b[i]-'0');
    auto ans = div_large(a1, b1);
    shang = ans.second;
    int len4 = shang.size();
    for(int i = len4-1;i >= 0;i--) cout << shang[i];
    return 0;
}























// #include<bits/stdc++.h>
// using namespace std;

// /*
// 比较两个高精度反写的非负整数的大小
// 默认a和b都是反着的
// 1表示a > b
// 0表示a = b
// -1表示a < b
// */
// int cmp(vector<int> a, vector<int> b) {
//     while(a.size() > 1 && a.back() == 0) a.pop_back();
//     while(b.size() > 1 && b.back() == 0) b.pop_back();
//     int len1 = a.size(), len2 = b.size();
//     if(len1 > len2) return 1;
//     if(len1 < len2) return -1;
//     for(int i = len1-1;i >= 0;i--) {
//         if(a[i] == b[i]) {
//             continue;
//         } else if(a[i] > b[i]) {
//             return 1;
//         } else {
//             return -1;
//         }
//     }
//     return 0;
// }

// /*
// 这里b是一个小精度整数，此题中只需要用到10以内，所以默认b小于10
// 返回的是反着的值
// */
// vector<int> mul_digit(const vector<int>& a, const int& b) {
//     int len = a.size();
//     vector<int>ans(len+1);
//     for(int i = 0;i < len;i++) {
//         ans[i] = a[i] * b;
//     }
//     int jinwei = 0;
//     for(int i = 0;i < len+1;i++) {
//         ans[i] += jinwei;
//         jinwei = ans[i] / 10;
//         ans[i] %= 10;
//     }
//     while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
//     return ans;
// }

// vector<int> sub_large(const vector<int>& a, const vector<int>& b) {
//     //a - b ,这里要求 a > b
//     int len1 = a.size(), len2 = b.size();
//     vector<int>ans(len1);
//     for(int i = 0;i < len2;i++) {
//         ans[i] = a[i] - b[i];
//     }
//     for(int i = len2;i < len1;i++) {
//         ans[i] = a[i];
//     }
//     int jiewei = 0;
//     for(int i = 0;i < len1;i++) {
//         ans[i] -= jiewei;
//         if(ans[i] < 0) {
//             jiewei = 1;
//             ans[i] += 10;
//         } else {
//             jiewei = 0;
//         }
//     }
//     while(ans.size() > 1 && ans.back() == 0) ans.pop_back();
//     return ans;
// }

// /*
// ans.first = 商
// ans.second = 余数
// */
// pair<vector<int>, vector<int>> div_large(const vector<int>& a, const vector<int>& b) {
//     //这里默认a和b是反着写的
//     int len1 = a.size(), len2 = b.size();
//     vector<int>shang, yushu;
//     for(int i = len1-1;i >= 0;i--) {
//         //注意这里yushu是正着表示的
//         yushu.push_back(a[i]);
//         reverse(yushu.begin(), yushu.end());
//         if(cmp(yushu, b) >= 0) {
//             //yushu >= b
//             //找到最大的 q ,使得q * b < 余数
//             int temp = 1;
//             for(int q = 1;q <= 9;q++) {
//                 //b * q > yushu
//                 if(cmp(mul_digit(b, q), yushu) == 1) {
//                     break;
//                 } else {
//                     //b * q <= yushu
//                     temp = q;
//                 }
//             }
//             //注意这里sub_large会至少保留最后的一位0
//             //然后在下个循环如果yushu push进了0就会变成00
//             //所以要在cmp函数中先进行去除0
//             yushu = sub_large(yushu, mul_digit(b, temp));
//             shang.push_back(temp);
//         } else {
//             shang.push_back(0);
//         }
//         //最终余数是正着表示的
//         reverse(yushu.begin(), yushu.end());
//     }
//     reverse(shang.begin(), shang.end());
//     reverse(yushu.begin(), yushu.end());
//     while(shang.size() > 1 && shang.back() == 0) shang.pop_back();
//     while(yushu.size() > 1 && yushu.back() == 0) yushu.pop_back();
//     reverse(shang.begin(), shang.end());
//     reverse(yushu.begin(), yushu.end());
//     return {shang, yushu};
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string a, b;
//     cin >> a >> b;
//     int len1 = a.length(), len2 = b.length();
//     vector<int>num1(len1), num2(len2);
//     for(int i = 0;i < len1;i++) {
//         num1[i] = a[len1-1-i]-'0';
//     }
//     for(int i = 0;i < len2;i++) {
//         num2[i] = b[len2-1-i]-'0';
//     }
//     auto [shang, yushu] = div_large(num1, num2);
//     for(auto it : shang) {
//         cout << it;
//     }
//     return 0;
// }