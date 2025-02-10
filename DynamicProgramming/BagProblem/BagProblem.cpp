// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <unordered_map>
using namespace std;
class Solution{
    unordered_map<string,pair<int,int>> items;
    vector<string> items_name;
    unordered_map<string,int> value;
    unordered_map<string,int> weight;

    public:
        Solution(){
            items_name = {"guitar","radio","laptop","iphone"};
            items["guitar"] = {1,1500};
            items["radio"]  = {4,3000};
            items["laptop"] = {3,2000};
            items["iphone"] = {1,2000};
        };
        
        int Bag01(const int &maxweight){
            vector<int> maxvalue(maxweight+1,0);
            for (int i = 0;i<items.size();i++)
                for (int j = maxweight;j>=0;j--){
                    if (j-items[items_name[i]].first >= 0)
                    maxvalue[j] = max(maxvalue[j],maxvalue[j-items[items_name[i]].first]+items[items_name[i]].second);
                    
                }
            return maxvalue[maxweight];
        }
};

void algor(){
    Solution s;
    cout<<s.Bag01(4)<<endl;
    
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
