// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp({0,1});
        for (int i =2;i<=n;i++){
            int maxval = 0;
            for (int j = 1;j<i;j++)
            if (i-j<dp[i-j])
                maxval = max(maxval,j*dp[i-j]);
            else
                maxval = max(maxval,j*(i-j));
            dp.push_back(maxval);
        }
        return dp[n];
    }
};
void algor(){
    Solution s;
    cout<<s.integerBreak(10)<<endl;
    
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
