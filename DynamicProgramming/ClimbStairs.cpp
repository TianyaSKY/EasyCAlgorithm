// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(const vector<int>& cost) {
        vector<int> dp({0,0});
        for (int i =2;i<=cost.size();i++){
            dp.push_back(min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]));
        }
        return dp[dp.size()-1];
    }
};

void algor(){
    Solution s;
    s.minCostClimbingStairs({10,15,20});
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
