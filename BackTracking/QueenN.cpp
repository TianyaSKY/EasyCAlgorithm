// 回溯算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;

class Solution {
public:

    vector<string> chessboard;
    vector<vector<string>> result;

    vector<vector<string>> solveNQueens(int n) {
        chessboard = vector<string>(n,string(n,'.'));
        for (int i = 0;i<n;i++)
        for (int j = 0;j<n;j++)
            chessboard[i][j] = '.';
        backtracking(n,0);
        return result;
    }


    void backtracking(int n,int row){
        if (row>=n){
            result.push_back(chessboard);
            return;
        }
        for (int i = 0;i<n;i++){
            if (!isValid(i,row,n)) continue;
            chessboard[row][i] = 'Q';
            backtracking(n,row+1);
            chessboard[row][i] = '.';
        }
    }

    bool isValid(int col ,int row,int n){
        // 判断当前位置是否合法
        // 只需检测当前位置的列和对角线
        for (int i = 0;i<n;i++)
            if (chessboard[i][col]=='Q') return false;
        // 检查 45度角是否有皇后
        for (int i = row - 1, j = col - 1; i >=0 && j >= 0; i--, j--) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        // 检查 135度角是否有皇后
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (chessboard[i][j] == 'Q') {
                return false;
            }
        }
        return true;
    }
};
void algor(){
    auto s =Solution();
    s.solveNQueens(5);
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
