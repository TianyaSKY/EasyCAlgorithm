// 回溯算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>


std::vector<std::string> result;
std::vector<std::string> path;

bool isLegal(std::string str){
    int p =0;
    int sum = 0;
    if (str[0]=='0' and str.length()>=2) return false;
    while (p<str.length())
    {   
        
        if (str[p] > '9' or str[p] <'0' ) return false;
        sum = 10*sum +str[p]-'0';
        if (sum>255) return false;
        p++;
    }
    return true;

}

void backtracking(const std::string S,int StartIndex){
    if (path.size()>4) return;
    if (StartIndex>=S.length()){
        if (path.size()<4) return;
        std::string ss;
        for (std::string l:path){
            ss += l;
            ss += ".";
        }
        result.push_back(ss.substr(0,ss.length()-1));
        return;
    }
    for (int i = StartIndex;i<S.length();i++){
        std::string str = S.substr(StartIndex,i-StartIndex+1);
        if (!isLegal(str)) continue;
        path.push_back(str);
        backtracking(S,i+1);
        path.pop_back();
    }
}

void algor(){
    backtracking("25525511135",0);
    for (std::string s: result)
        std::cout<<s<<std::endl;
    
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
