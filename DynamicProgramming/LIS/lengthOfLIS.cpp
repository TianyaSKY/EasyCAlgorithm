// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        // 最长递增子序列
        int lengthOfLIS(vector<int>& nums) {
            int result = 0;
            vector<int> dp(nums.size(),1);
            for (int i = 1;i<=nums.size();i++){
                for (int j = 0;j<i;j++){
                    if (nums[i] > nums[j])
                        dp[i] = max(dp[i],dp[j]+1);
                }
                if (dp[i] > result) result = dp[i];
            }
            return result;
        }
    };

void algor(){
    Solution s;
    auto result = s;
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
