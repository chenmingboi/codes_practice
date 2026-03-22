#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string student;
    int max_score = -1, max_ch, max_ma, max_en;
    for(int i = 0;i < n;i++) {
        string name;
        cin >> name;
        int chinese, math, english, total=0;
        cin >> chinese >> math >> english;
        total = chinese + math + english;
        if(total > max_score) {
            max_ch = chinese, max_ma = math, max_en = english;
            max_score = total;
            student = name;
        }
    }
    cout << student << ' ' << max_ch << ' ' << max_ma << ' ' << max_en;
    return 0;
}