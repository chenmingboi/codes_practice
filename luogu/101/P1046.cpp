#include<bits/stdc++.h>
using namespace std;

int main()
{
    int height[10];
    int maxheight = 0;
    for(int i = 0; i< 10;i++){
        cin >> height[i];
    }
    cin >> maxheight;
    maxheight += 30;
    int result = 0;
    for(int i = 0;i < 10;i++){
        if(height[i] <= maxheight) {
            result++;
        }
    }
    cout << result;
    return 0;
}