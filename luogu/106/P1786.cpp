#include<bits/stdc++.h>
using namespace std;

struct Person {
    string name;
    string zhiwei;
    int banggong;
    int dengji;
    int id; //添加了id来记录输入的顺序，在排序的时候使用
};

bool comp1(Person& a, Person& b) {
    if(a.banggong != b.banggong) return a.banggong > b.banggong;
    return a.id < b.id;
}
bool comp2(Person& a, Person& b) {
    if(a.dengji != b.dengji) return a.dengji > b.dengji;
    return a.id < b.id;
}
int main() {
    int n;
    cin >> n;
    vector<Person> shuru, fubangzhu;
    Person bangzhu;
    for(int i = 0;i < n;i++) {
        Person person;
        person.id = i;
        cin >> person.name >> person.zhiwei >> person.banggong >> person.dengji;
        if(person.zhiwei == "BangZhu") {
            bangzhu = person;
        } else if (person.zhiwei == "FuBangZhu") {
            fubangzhu.push_back(person);
        } else {
            shuru.push_back(person);
        }
    }
    sort(shuru.begin(), shuru.end(), comp1); //可以通过调整迭代器来指定区间排序
    for(int i = 0;i < n-3;i++) {
        if(i <= 1) {
            shuru[i].zhiwei = "HuFa";
        } else if(i <= 5) {
            shuru[i].zhiwei = "ZhangLao";
        } else if(i <= 12) {
            shuru[i].zhiwei = "TangZhu";
        } else if(i <= 37) {
            shuru[i].zhiwei = "JingYing";
        } else {
            shuru[i].zhiwei = "BangZhong";
        }
    }
    for(int i = 0;i < n-3;) {
        int j = i;
        while(j < n-3 && shuru[i].zhiwei == shuru[j].zhiwei) {
            j++;
        }
        sort(shuru.begin()+i, shuru.begin()+j, comp2);
        i = j;
    }
    sort(fubangzhu.begin(), fubangzhu.end(),comp2);
    cout << bangzhu.name << ' ' << bangzhu.zhiwei << ' ' << bangzhu.dengji << endl;
    for(int i = 0;i < 2;i++) {
        cout << fubangzhu[i].name << ' ' << fubangzhu[i].zhiwei << ' ' << fubangzhu[i].dengji << endl;
    }
    for(int i = 0;i < n-3;i++) {
        cout << shuru[i].name << ' ' << shuru[i].zhiwei << ' ' << shuru[i].dengji << endl;
    }
    return 0;
}