#include<bits/stdc++.h>
using namespace std;

struct Student {
    string name;
    int y;
    int m;
    int d;
    int id;
};

bool comp(const Student& a, const Student& b) {
    if(a.y != b.y) return a.y < b.y;
    if(a.m != b.m) return a.m < b.m;
    if(a.d != b.d) return a.d < b.d;
    return a.id > b.id;
}
int main() {
    int n;
    cin >> n;
    vector<Student> input(n);
    for(int i = 0;i < n;i++) {
        cin >> input[i].name >> input[i].y >> input[i].m >> input[i].d;
        input[i].id = i;
    }
    sort(input.begin(), input.end(), comp);
    for(int i = 0;i < n;i++) {
        cout << input[i].name << endl;
    }
    return 0;
}