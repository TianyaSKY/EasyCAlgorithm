#include <vector>
#include <iostream>
#include <cmath>
int maxProfitOnce(const std::vector<int> prices){
    // 动态规划解法 只能买入一次
    std::vector<std::vector<int> > dp(prices.size(),std::vector<int>(2));
    // 0代表持有的最大收益， 1代表不持有的最大收益
    dp[0][0] = -prices[0];
    dp[0][1] = 0;  // 第0天不持有的最大收益为0
    for (int i =1;i<prices.size();i++){
        
        dp[i][0] = std::max(dp[i-1][0],-prices[i]);  // 因为只能买入一次
        dp[i][1] = std::max(dp[i-1][0]+prices[i],dp[i-1][1]); // 第i天不持有的最大收益
    }
    return dp[prices.size()-1][1];
}
int maxProfitOnceStatic(const std::vector<int> prices){
    // 遍历解法
    int maxprofit = 0;
        int minBuy = prices[0];  // 最小买入价格
        for (int i=1;i<prices.size();i++){
            if (minBuy>prices[i-1]) {
                minBuy = prices[i-1];
            }
            if (prices[i]-minBuy > maxprofit)
                maxprofit = prices[i]-minBuy;
        }
        return maxprofit;
}

int maxProfitMut(const std::vector<int> prices){
    // 动态规划解法求解无限次数买入卖出
    std::vector<std::vector<int>> dp(prices.size(),std::vector<int>(2));
    // 0代表没有的最大收益， 1代表持有的最大收益
    dp[0][1] = -prices[0];
    dp[0][0] = 0;  // 第0天卖出的最大收益为0
    for (int i =1;i<prices.size();i++){
        dp[i][1] = std::max(dp[i-1][1],dp[i-1][0]-prices[i]);
        dp[i][0] = std::max(dp[i-1][0],dp[i-1][1]+prices[i]);
    }
    return dp[prices.size()-1][0];
}
int main(int argc, char const *argv[])
{
    std::cout<<maxProfitOnce({7,1,5,3,6,4})<<std::endl;
    std::cout<<maxProfitMut({7,1,5,3,6,4})<<std::endl;
    return 0;
}
