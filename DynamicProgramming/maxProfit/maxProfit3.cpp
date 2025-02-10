// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int maxProfit(const vector<int>& prices) {
           vector<vector<int>> dp(prices.size(),vector<int>(5,0)); 
           // 0不操作 1第一次持有 2第一次不持有 3第二次持有 4 第二次不持有 
            dp[0][1] = -prices[0];
            dp[0][3] = -prices[0];
            for (int i = 1;i<prices.size();i++){
            dp[i][0] = dp[i-1][0];
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2],dp[i-1][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3],dp[i-1][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4],dp[i-1][3]+prices[i]);
           }
           return dp[prices.size()-1][4];
        }
    };

void algor(){
    Solution s;
    auto result = s.maxProfit({3,3,5,0,0,3,1,4});
    cout<<result<<endl;
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
