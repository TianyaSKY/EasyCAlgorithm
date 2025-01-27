// 回溯算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>


std::vector<std::vector<int>> result;   // 组合的所有结果
std::vector<int> path;  // 单个组合


void backtracking(int n,int k,int StartIndex){
    // if (path.size()+n-StartIndex<k) return;
    if (path.size()==k){
        int sum = 0;
        for (int s:path)
            sum += s;
        if (sum==n)
        result.push_back(path);
        return;
    }
    for (int i = StartIndex;i<=n;i++){
        path.push_back(i);
        backtracking(n,k,i+1);
        path.pop_back();
    }
        
    };


void algor(){
    backtracking(45,3,1);
};
int main(int argc, char const *argv[])
{   
    // 使用 chrono 来记录高精度时间
    using namespace std::chrono;
    steady_clock::time_point t1, t2;
    double tt = 0.0;
    t1 = steady_clock::now();  // 记录开始时间
    std::cout<<"Start"<<std::endl;
    
    algor();

    t2 = steady_clock::now();  // 记录结束时间
    tt = duration_cast<milliseconds>(t2 - t1).count();  // 计算时间差，转化为毫秒
    std::cout << "操作的时间是：" << tt << " 毫秒." << std::endl;
    // for (std::vector<int> s: result){
    //     for (int i :s)
    //         std::cout<<i<<" ";
    //     std::cout<<std::endl;
    // }
    return 0;
}
