// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int findMaxForm(vector<string>& strs, int m, int n) {
            vector<vector<int>> dp(m+1,vector<int>(n+1,0));
            
            for (string str:strs){
                int ZeroNum = 0,OneNum = 0;
                for (char c:str){
                    if (c=='0') ZeroNum++;
                    else OneNum++;
                }
                for (int i = m;i>=ZeroNum;i--){
                    for (int j = n;j>=OneNum;j--){
                        dp[i][j] = max(dp[i][j],dp[i-ZeroNum][j-OneNum]+1);
                    }
                }
            }
        return dp[m][n];
        }
};

void algor(){
    Solution s;
    
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
