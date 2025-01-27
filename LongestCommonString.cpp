#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>

int Find(const std::string s1,const std::string s2){
    int dp[s1.length()][s2.length()];
    int length =0 ;
    if (s1[0]==s2[0]) dp[0][0] = 1;
    else dp[0][0] = 0;
    for (int i =1;i<s1.length();i++)  dp[i][0] = dp[0][0];
    for (int i =1;i<s2.length();i++)  dp[0][i] = dp[0][0];
    int max_len = 0;
    for (int i = 1;i<s1.length();i++)
        for (int j = 1;j<s2.length();j++){
            if (s1[i] == s2[j]) dp[i][j] = dp[i-1][j-1]+1;
            else dp[i][j] = std::max(dp[i-1][j],dp[i][j-1]);
            if (dp[i][j]>max_len) max_len = dp[i][j];
        }
    return max_len;
};

int main(int argc, char const *argv[])
{
    std::cout<<Find("ABCDDAB","BDCABC")<<std::endl;
    return 0;
}
