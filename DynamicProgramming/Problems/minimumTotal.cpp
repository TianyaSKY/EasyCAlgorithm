// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int minimumTotal(const vector<vector<int>>& triangle) {
            int n =triangle.size();
            vector<vector<int>> dp(n,vector<int>(n,0));
            dp[0][0] = triangle[0][0];
            int result = INT32_MAX;
            for (int i = 1;i<n;i++){
                for (int j =0;j<=i;j++){
                    if (j==i)
                        dp[i][j] = dp[i-1][j-1];
                    else if (j>=1)
                    dp[i][j] = min(dp[i-1][j],dp[i-1][j-1]);
                    else 
                    dp[i][j] = dp[i-1][j];
                    dp[i][j] += triangle[i][j];
                }
            }
            for (int i = 0;i<n;i++)
                result = min(dp[n-1][i],result);
            return result;
        }
    };

void algor(){
    Solution s;
    auto result = s.minimumTotal({{2},{3,4},{6,5,7},{4,1,8,3}});
    // cout<<result<<endl;
};

int main(int argc, char const *argv[])
{
    // 使用 chrono 来记录高精度时间
    using namespace std::chrono;
    steady_clock::time_point t1, t2;
    double tt = 0.0;
    t1 = steady_clock::now();  // 记录开始时间
    algor();
    t2 = steady_clock::now();  // 记录结束时间
    tt = duration_cast<milliseconds>(t2 - t1).count();  // 计算时间差，转化为毫秒
    std::cout << "操作的时间是：" << tt << " 毫秒." << std::endl;
    return 0;
}
