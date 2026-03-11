#include<bits/stdc++.h>
using namespace std;

//判断素数方法，0,1不是素数，2,3是素数，只需检查到根号n
bool isPrime(int n) {
    if(n <= 1) return false;
    if(n <= 2) return true;
    if(n % 2 == 0) return false;
    for(int i = 3; i*i <= n;i++) {
        if(n % i == 0) return false;
    }
    /*
    更高效的方式
    bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    // 所有质数都在 6k±1 形式（k为整数）
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
    }*/
    return true;
}
int main()
{
    int L;
    cin >> L;
    int sum = 0, i = 2;
    vector<int>result;
    while(sum <= L) {
        if(isPrime(i)) {
            sum += i;
            if(sum > L){
                sum -= i;
                break;
            }
            result.push_back(i);
        } 
        i++;
    }
    for(auto it : result){
        cout << it << endl;
    }
    cout << result.size();
}