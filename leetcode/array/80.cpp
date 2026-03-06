#include <bits/stdc++.h>  // 一次性拉齐所有常用头文件
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 2) return len;
        int slow = 2, fast = 2;
        while(fast < len) {
            if(nums[slow-2] != nums[fast]) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};

int main() {
    int n = 0;
    std::cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }
    Solution sol;
    int new_len = sol.removeDuplicates(nums);
    std::cout << new_len << std::endl;
}