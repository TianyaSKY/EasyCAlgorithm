// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        // 最长公共子数组
        int findLength(const vector<int>& nums1,const vector<int>& nums2) {
            vector<vector<int>> dp(nums1.size()+1,vector<int>(nums2.size()+1,0));  // n1以i-1结尾 n2以j-1结尾 
            int result = 0;
            for (int i = 1;i<=nums1.size();i++){
                for (int j = 1;j<=nums2.size();j++){
                    if (nums1[i-1]==nums2[j-1]) dp[i][j] = dp[i-1][j-1] +1;
                    result = max(result,dp[i][j]);
                }
            }
            return result;
        }
    };

void algor(){
    Solution s;
    auto result = s.findLength({1,2,3,2,1},{3,2,1,4,7});
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
