// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int coinChange(const vector<int>& coins, int amount) {
            vector<int> dp(amount+1,30000);
            dp[0] = 0;
            for (int i  =0;i<coins.size();i++){
                for (int j = coins[i];j<=amount;j++){
                    dp[j] = min(dp[j-coins[i]] +1,dp[j]);
                }
            }
            if (dp[amount] == 30000) return -1;
            return dp[amount];
        }
};

void algor(){
    Solution s;
    auto result = s.coinChange({1,2,5},11);
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
