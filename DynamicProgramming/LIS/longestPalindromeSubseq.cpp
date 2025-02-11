// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        //  最长回文子序列
        int longestPalindromeSubseq(string s) {
            int result = 0;
            vector<vector<int>> dp(s.size(),vector<int>(s.size(),0));  // i~j 的回文子序列长度
            for (int i = 0;i<s.size();i++)
                dp[i][i] = 1;
            for (int i = s.size()-1;i>=0;i--){
                for (int j = i+1;j<s.size();j++){
                    if (s[i]==s[j]){
                        dp[i][j] = dp[i+1][j-1] + 2;
                    }
                    else {
                        dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
                    }
                    result = max(result,dp[i][j]);  
                }
            }
            return result;
        }
    };

void algor(){
    Solution s;
    auto result = s.longestPalindromeSubseq("a");
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
