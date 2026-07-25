#include<bits/stdc++.h>
using namespace std;

// a >= b return true, a < b return false;
bool judge(const string& a, const string& b) {
    int lena = a.length(), lenb = b.length();
    if(lena > lenb) return true;
    if(lena < lenb) return false;
    for(int i = 0;i < lena;i++) {
        if(a[i] != b[i]) {
            return a[i] > b[i];
        } else {
            continue;
        }
    }
    //a = b
    return true;
}
vector<int>large_sub(const vector<int>& a, const vector<int>& b) {
    int lena = a.size(), lenb = b.size();
    vector<int>result(lena, 0);
    for(int i = 0;i < lenb;i++) result[i] = a[i] - b[i];
    for(int i = lenb;i < lena;i++) result[i] = a[i];
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
    while(result.back() == 0 && result.size() > 1) result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    //flag = true为正值，flag = false为负值
    bool flag = true;
    if(!judge(a, b)) {
        swap(a, b);
        flag = false;
    }
    vector<int>numa, numb, result;
    for(auto it : a) numa.push_back(it-'0');
    for(auto it : b) numb.push_back(it-'0');
    reverse(numa.begin(), numa.end());
    reverse(numb.begin(), numb.end());
    result = large_sub(numa, numb);
    if(!flag) { cout << '-'; }
    for(auto it : result) {cout << it;}
    return 0;
}