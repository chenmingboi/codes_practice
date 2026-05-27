#include<bits/stdc++.h>
using namespace std;

struct student {
    int id;
    int ch;
    int math;
    int en;
    int total;
};

bool comp(const student& a, const student& b) {
    if(a.total != b.total) {
        return a.total > b.total;
    } else {
        if(a.ch != b.ch) {
            return a.ch > b.ch;
        } else {
            return a.id < b.id;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<student> stu(n);
    for(int i = 0;i < n;i++) {
        int ch, ma, en, total;
        cin >> ch >> ma >> en;
        total = ch + ma + en;
        stu[i].ch = ch, stu[i].en = en, stu[i].math = ma;
        stu[i].total = total, stu[i].id = i+1;
    }
    sort(stu.begin(), stu.end(), comp);
    for(int i = 0;i < 5;i++){
        cout << stu[i].id << ' ' << stu[i].total << endl;
    }
    return 0;
}