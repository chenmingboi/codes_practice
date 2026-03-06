#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int res = 0;
        for(int i = 1;i < len;i++) {
            res += max(prices[i] - prices[i-1], 0);
        }
        return res;
    }
};

int main() 
{
    int n = 0;
    cin >> n;
    vector<int>prices(n);
    for(int i = 0;i < n;i++) {
        cin >> prices[i];
    }
    Solution sol;
    cout << sol.maxProfit(prices) << endl;
}