#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int age;
    int score;
};

Student peixun(Student s) {
    s.score = (s.score * 1.2) > 600 ? 600 : (s.score * 1.2);
    s.age += 1;
    return s;
}
int main() {
    int n;
    cin >> n;
    for(int i = 0;i < n;i++) {
        Student s;
        cin >> s.name >> s.age >> s.score;
        s = peixun(s);
        cout << s.name << ' ' << s.age << ' ' << s.score << endl;
    }
    return 0;
}