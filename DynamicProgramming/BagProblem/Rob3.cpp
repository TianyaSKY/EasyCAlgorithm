// 动态规划算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
    public:
        int rob(TreeNode* root) {
            auto result = robTree(root);
            return max(result[0],result[1]);
        }
        vector<int> robTree(TreeNode * node){
            if (node==nullptr) return vector<int>{0,0};
            // 后序遍历
            vector<int> leftNode  = robTree(node->left);
            vector<int> rightNode = robTree(node->right);
    
            int robTrue = leftNode[1] + rightNode[1] + node->val;
            int robFalse = max(leftNode[0],leftNode[1]) +  max(rightNode[0],rightNode[1]);
            return vector  <int> {robTrue,robFalse};
        }
    };

void algor(){
    Solution s;
    auto result = s;
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
