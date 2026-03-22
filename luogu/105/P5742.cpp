#include<bits/stdc++.h>
using namespace std;

struct Student {
    int ID;
    double xueye;
    double suzhi;
    double zonghe; //zonghe = 7 * xueye + 3 * suzhi
    double sum() {
        return this->xueye + this->suzhi;
    }
};

bool good(Student student) {
    if(student.sum() > 140 && student.zonghe >= 800) {
        return true;
    }
    return false;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        Student s;
        cin >> s.ID >> s.xueye >> s.suzhi;
        s.zonghe = s.xueye * 7 + s.suzhi * 3;
        if(good(s)) {
            cout << "Excellent" << endl;
        } else {
            cout << "Not excellent" << endl;
        }
    }
    return 0;
}