// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        // 判断s是否为t的子序列
        bool isSubsequence(string s, string t) {
            vector<vector<int>> dp(s.length()+1,vector<int>(t.length()+1,0));
            for (int i = 1;i<=s.length();i++){
                for (int j = 1;j<=t.length();j++){
                    if (s.substr(i-1,1)==t.substr(j-1,1)) dp[i][j] = dp[i-1][j-1] + 1;
                    else {
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                    }
                    if (dp[i][j] == s.length()) return true;
                }
            }
            return false;
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
