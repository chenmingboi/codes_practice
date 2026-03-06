#include <bits/stdc++.h>  // 一次性拉齐所有常用头文件
using std::cin;
using std::cout;
using std::vector;

class Solution {
public:
    // 计算三角形面积，使用向量叉积公式
    static double triangleArea(int x1, int y1, int x2, int y2, int x3, int y3) {
        // 用 64 位整数防止中间乘积溢出，再转 double
        long long area2 = static_cast<long long>(x1) * (y2 - y3)
                        + static_cast<long long>(x2) * (y3 - y1)
                        + static_cast<long long>(x3) * (y1 - y2);
        return std::fabs(static_cast<double>(area2)) * 0.5;
    }

    // 暴力枚举最大三角形面积，O(n³)
    double largestTriangleArea(vector<vector<int>>& points) {
        const int n = static_cast<int>(points.size());
        double best = 0.0;
        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                for (int k = j + 1; k < n; ++k)
                    best = std::max(best,
                                   triangleArea(points[i][0], points[i][1],
                                                points[j][0], points[j][1],
                                                points[k][0], points[k][1]));
        return best;
    }
};

/* ------------- 以下为简单测试，提交时可直接删掉 ------------- */
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<vector<int>> pts(n, vector<int>(2));
    for (int i = 0; i < n; ++i) cin >> pts[i][0] >> pts[i][1];

    Solution sol;
    cout << std::fixed << std::setprecision(6)
         << sol.largestTriangleArea(pts) << '\n';
    return 0;
}