#include<bits/stdc++.h>
using namespace std;

void pop_zero(vector<int>& a) {
    if(a.empty()) return;
    while(a.back() == 0 && a.size() > 1) a.pop_back();
}

void popfront_zero(vector<int>& a) {
    if(a.empty()) return;
    reverse(a.begin(), a.end());
    pop_zero(a);
    reverse(a.begin(), a.end());
}

bool dayudengyu(const vector<int>& tempa, const vector<int>& tempb) {
    vector<int>a = tempa, b = tempb;
    popfront_zero(a), popfront_zero(b);
    int lena = a.size(), lenb = b.size();
    if(lena > lenb) return true;
    if(lena < lenb) return false;
    for(int i = 0;i < lena;i++) {
        if(a[i] != b[i]) {
            return a[i] > b[i];
        }
    }
    return true;
}

bool xiaoyudengyu(const vector<int>& tempa, const vector<int>& tempb) {
    vector<int>a = tempa, b = tempb;
    popfront_zero(a), popfront_zero(b);
    int lena = a.size(), lenb = b.size();
    if(lena > lenb) return false;
    if(lena < lenb) return true;
    for(int i = 0;i < lena;i++) {
        if(a[i] != b[i]) return a[i] < b[i];
    }
    return true;
}

//这里面a是正序的，返回的result是正序的
vector<int> large_mul(const vector<int> a, const int& b) {
    vector<int>tempa = a;
    reverse(tempa.begin(), tempa.end());
    pop_zero(tempa);
    int len = tempa.size();
    vector<int>result(len+1);
    for(int i = 0;i < len;i++) result[i] = tempa[i] * b;
    int jinwei = 0;
    for(int i = 0;i < len+1;i++) {
        result[i] += jinwei;
        jinwei = result[i] / 10;
        result[i] %= 10;
    }
    pop_zero(result);
    reverse(result.begin(), result.end());
    return result;
}

//默认a>b, 且传入的a和b为正序, 返回的result为正序
vector<int> large_sub(const vector<int>& a, const vector<int>& b) {
    int lena = a.size(), lenb = b.size();
    vector<int>result(lena);
    vector<int>tempa = a, tempb = b;
    reverse(tempa.begin(), tempa.end());
    reverse(tempb.begin(), tempb.end());
    for(int i = 0;i < lenb;i++) result[i] = tempa[i] - tempb[i];
    for(int i = lenb;i < lena;i++) result[i] = tempa[i];
    int jiewei = 0;
    for(int i = 0;i < lena;i++) {
        result[i] -= jiewei;
        if(result[i] < 0) {
            jiewei = 1;
            result[i] += 10;
        } else {
            jiewei = 0;
        }
    }
    pop_zero(result);
    reverse(result.begin(), result.end());
    return result;
}

//这里a和b均为正序排列
vector<int> large_div(const vector<int>& a, const vector<int>& b) {
    int len = a.size();
    vector<int>shang, yushu;
    for(int i = 0;i < len;i++) {
        yushu.push_back(a[i]);
        if(dayudengyu(yushu, b)) {
            vector<int>temp;
            int sh = 0;
            for(int i = 1;i <= 9;i++) {
                temp = large_mul(b, i);
                if(xiaoyudengyu(temp, yushu)) {
                    sh = i;
                } else {
                    break;
                }
            }
            temp = large_mul(b, sh);
            yushu = large_sub(yushu, temp);
            shang.push_back(sh);
        } else {
            shang.push_back(0);
        }
    }
    popfront_zero(shang);
    return shang;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    vector<int>numa, numb, result;
    for(auto it : a) numa.push_back(it-'0');
    for(auto it : b) numb.push_back(it-'0');
    result = large_div(numa, numb);
    for(auto it : result) cout << it;
    return 0;
}