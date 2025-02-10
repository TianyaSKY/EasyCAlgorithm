// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int findTargetSumWays(const vector<int>& nums, int target) {
            int total_nums = 0;
            for (int s:nums)
                total_nums += s;
            if (abs(target) >total_nums) return 0;
            if ((total_nums + target)%2) return 0;
            int target_sum = (total_nums + target) /2;
            vector<int> dp(target_sum+1,0);
            dp[0] = 1;
            for (int i=0;i<nums.size();i++){
                for (int j=target_sum;j>=0;j--){
                    if (j-nums[i]>=0){
                        dp[j] += dp[j-nums[i]];
                    }
                }
            }
            return dp[target_sum];
        }
    };

void algor(){
    Solution s;
    auto result = s.findTargetSumWays({1,1,1,1,1},3);
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
