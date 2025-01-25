
#include <vector>
#include <iostream>
#include <cmath>
int maxSum(const std::vector<int> num){
    // 找出连续子序列的最大和
    std::vector<int> S(num.size(),0);
    for (int i = 0;i<num.size();i++){
        S[i] = num[i];
    }
    int max_val = -num[0];
    for (int i = num.size()-2;i>=0;i--){
        if (S[i+1] >0) S[i] = num[i]+S[i+1];
        if (S[i] > max_val) max_val = S[i];}
    return max_val;
}

int LongestLength(const std::vector<int> num){
    // 找出最长递增序列长度
    std::vector<int> S(num.size(),1);
    int max_len_val = 0;
    for (int i = num.size()-1;i>=0;i--){
        for (int j = i+1;j<num.size();j++){
            if (num[j]>num[i]){
                S[i] = std::max(S[i],S[j]+1);
            }
        }
        if (S[i] > max_len_val) max_len_val = S[i];
    }
    return max_len_val;
    
}

int main(int argc, char const *argv[])
{
    std::cout<<maxSum({3,-4,2,-1,2,6,-5,4})<<std::endl;
    std::cout<<LongestLength({1,5,2,4,3})<<std::endl;
    return 0;
}
