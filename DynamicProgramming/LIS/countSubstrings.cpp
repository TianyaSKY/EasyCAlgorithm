// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
    public:
        // 统计回文子串数目
        int countSubstrings(string s) {
            int result = 0;
            vector<vector<int>> dp(s.size(),vector<int>(s.size(),false));  // i~j 是否为回文子串 
            for (int i = s.size()-1;i>=0;i--){
                for (int j = i;j<s.size();j++){
                    if (s[i]==s[j]){
                        if (j-i<=1){
                            dp[i][j] = true;
                            result++;
                        }
                        else if(dp[i+1][j-1]){
                            dp[i][j] = true;
                            result++;
                        }
                    }
                }
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
