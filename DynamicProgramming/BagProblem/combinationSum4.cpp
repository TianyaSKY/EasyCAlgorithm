// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int combinationSum4(const vector<int>& nums, int target) {
            vector<int> dp(target+1,0);
            dp[0] = 1;
            for (int j = 0;j<=target;j++){
                for (int i = 0;i<nums.size();i++){
                    if (j>=nums[i])
                        dp[j] += dp[j-nums[i]];
                }
            }
            return dp[target];
        }
        
    };

void algor(){
    Solution s;
    auto result = s.combinationSum4({1,2,3},4);
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
