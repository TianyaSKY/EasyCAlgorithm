// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <unordered_set>
using namespace std;
class Solution {
    public:
        bool wordBreak(string s, const vector<string>& wordDict) {
            unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
            vector<bool> dp(s.size() + 1, false);
            dp[0] = true;
            for (int i = 1; i <= s.size(); i++) {   // 遍历背包
                for (int j = 0; j < i; j++) {       // 遍历物品
                    string word = s.substr(j, i - j); //substr(起始位置，截取的个数)
                    if (wordSet.find(word) != wordSet.end() && dp[j]) {
                        dp[i] = true;
                    }
                }
            }
            return dp[s.size()];
        }
    };

void algor(){
    Solution s;
    auto result = s.wordBreak("leetcode",{"leet", "code"});
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
