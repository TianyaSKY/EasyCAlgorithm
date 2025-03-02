// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            int result = 0 ;
            // 定义dp[i][j] 为i,j位置的最大正方形边长 
            vector<vector<int>> dp(m+1,vector<int>(n+1,0));
            for (int  i = 1;i<=m;i++){
                for (int j = 1;j<=n;j++){
                    dp[i][j] = min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                    if (matrix[i-1][j-1]=='1'){
                        dp[i][j]++;
                    }
                    result = max(result,dp[i][j]);
                }
            }
            return result * result;
            
        }
    };

void algor(){
    Solution s;
    vector<vector<char>> VV({{'1','0','1','1','0','1'},{'1','1','1','1','1','1'},{'0','1','1','0','1','1'},{'1','1','1','0','1','0'},{'0','1','1','1','1','1'},{'1','1','0','1','1','1'}});
    auto result = s.maximalSquare(VV);
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
    std::cout << '操作的时间是：' << tt << ' 毫秒.' << std::endl;
    return 0;
}
