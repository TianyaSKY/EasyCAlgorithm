// 回溯算法求解各类问题
#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <chrono>
using namespace std;
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        backtracking(board);
    }
    bool isValid(int col,int row,int val,vector<vector<char>>& board){
        for (int i =0;i<9;i++)
            if (board[col][i]==val or board[i][row]==val) return false;
        int gc = col/3;
        int gr = row/3;
        for (int i = 0;i<3;i++)
            for (int j = 0;j<3;j++)
                if (board[gc*3+i][gr*3+j]==val) return false;
        return true;
    }
    bool backtracking(vector<vector<char>>& board){
        for (int i =0;i<9;i++)
            for (int j = 0;j<9;j++){
                if (board[i][j] != '.') continue;
                for (char v = '1';v<='9';v++){
                    if (!isValid(i,j,v,board)) continue;
                    board[i][j] = v;
                    auto result = backtracking(board);
                    if (result) return true;
                    board[i][j] = '.';
                }
                 return false;
            }
           
        return true;
    }
    
    
};

void algor(){
    auto s = Solution();
    vector<vector<char>> v = {
        {'.','.','.','.','.','.','.','.','.'},
        {'5','.','.','.','.','9','.','6','2'},
        {'8','7','.','.','5','.','.','3','.'},
        {'1','.','.','.','4','.','5','2','.'},
        {'3','.','.','9','.','6','.','.','1'},
        {'.','8','4','.','2','.','.','.','3'},
        {'.','1','.','.','6','.','.','4','7'},
        {'7','4','.','8','.','.','.','.','9'},
        {'.','.','.','.','.','.','.','.','.'}};
    s.solveSudoku(v);
    for (int i = 0;i<9;i++){
        for (int j = 0;j<9;j++){
            cout<<v[i][j]<<' ';
        }
        cout<<endl;
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
