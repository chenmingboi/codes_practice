#include<bits/stdc++.h>
using namespace std;

struct Student{
    int num;
    int yuwen;
    int shuxue;
    int yingyu;
    int total;
};

bool comp(const Student& stu1, const Student& stu2) {
    if(stu1.total != stu2.total) {
        return stu1.total > stu2.total;
    } else {
        if(stu1.yuwen != stu2.yuwen) {
            return stu1.yuwen > stu2.yuwen;
        } else {
            return stu1.num < stu2.num;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Student>stus(n);
    for(int i = 0;i < n;i++) {
        int c, m, e, total, order = i+1;
        cin >> c >> m >> e;
        total = c + m + e;
        stus[i] = {order, c, m, e, total};
    }
    sort(stus.begin(), stus.end(), comp);
    for(int i = 0;i < 5;i++) {
        cout << stus[i].num << ' ' << stus[i].total << '\n';
    }
    return 0;
}