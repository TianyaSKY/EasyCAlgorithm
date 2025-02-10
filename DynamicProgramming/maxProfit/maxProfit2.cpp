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
           vector<vector<int>> dp(prices.size(),vector<int>(2,0)); 
           // 0持有 1 未持有
           dp[0][0] = -prices[0];
           for (int i = 1;i<prices.size();i++){
            dp[i][0] = max(dp[i-1][0],dp[i-1][1]-prices[i]);
            dp[i][1] = max(dp[i-1][1],dp[i-1][0]+prices[i]);
           }
           return dp[prices.size()-1][1];
        }
    };

void algor(){
    Solution s;
    auto result = s.maxProfit({7,1,5,3,6,4});
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
