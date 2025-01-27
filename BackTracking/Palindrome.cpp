// 回溯算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>

std::vector<std::vector<std::string>> result;
std::vector<std::string> path;


bool isP(const std::string S){
    int ptr1 = 0;
    int ptr2 = S.length()-1;
    while (ptr1<=ptr2)
    {
        if (S[ptr1]!=S[ptr2]) return false;
        ptr1++;
        ptr2--;
    }
    return true;
    
}

void backtracking(std::string S,int CutP){
    if (CutP==S.length()){
        result.push_back(path);
        return;
    }
    for (int i = CutP;i<S.length();i++){
        std::string str = S.substr(CutP,i-CutP+1);
        if (!isP(str)) continue;
        path.push_back(str);
        backtracking(S,i+1);
        path.pop_back();
    }
}
void algor(){
    // 要求返回所有回文切割方案
    std::string words = "aab";
    backtracking(words,0);

    for (std::vector<std::string> s: result){
        for (std::string i :s)
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
