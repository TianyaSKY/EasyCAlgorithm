// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
public:
    bool canPartition(const vector<int>& nums) {
        int sum = 0;
        for (int s:nums)
            sum += s;
        for (int s:nums)
            if (s>sum/2) return false;
        vector<vector<int>> bag(nums.size(),vector<int>(1+sum/2,0));
        for (int i = nums[0];i<1+sum/2;i++){
            bag[0][i] = nums[0];
        }
        for (int i = 1;i<nums.size();i++){
            for (int j = 1;j<1+sum/2;j++){
                if (j-nums[i] > 0)
                    bag[i][j] = max(bag[i-1][j],bag[i-1][j-nums[i]]+nums[i]);
                else
                    bag[i][j] = bag[i-1][j];
            }
        }
        return bag[nums.size()-1][sum/2] == sum/2;
    }
};

void algor(){
    Solution s;
    s.canPartition({1,1,1,1,1});
    
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
