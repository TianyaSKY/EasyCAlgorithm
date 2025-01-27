// 回溯算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;

// 求出所有子集 即所有节点
class Solution {
public:
    
    std::vector<std::vector<int>> result;   // 组合的所有结果
    std::vector<int> path;  // 单个组合

    vector<vector<int>> subsets(const vector<int>& nums) {
        backtracking(nums,0);
        return result;
    }
    void backtracking(const vector<int> nums,int StartIndex){
        result.push_back(path);
        if (StartIndex>=nums.size()) return;
        for (int i = StartIndex;i<nums.size();i++){
            path.push_back(nums[i]);
            backtracking(nums,i+1);
            path.pop_back();
        }
    }
};
void algor(){
    auto s = Solution();
    s.subsets({1,2,3});

    for (std::vector<int> s: s.result){
        for (int i :s)
            std::cout<<i<<" ";
        std::cout<<std::endl;
    }
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
