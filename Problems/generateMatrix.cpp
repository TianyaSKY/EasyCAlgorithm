using namespace std;
#include <vector>
class Solution {
    public:
        vector<vector<int>> generateMatrix(int n) {
            vector<vector<int>> board(n,vector<int>(n,0));
            board[0][0] = 1;
            int row=0;
            int col = 0;
            int direct =0;
            int value = 2;
            while (board[col][row]<n*n){
                int init_dir = direct;
                int init_row = row;
                int init_col = col;
                switch(direct){
                    case 0:
                        row ++;
                        break;
                    case 1:
                        col ++;
                        break;
                    case 2:
                        row --;
                        break;
                    case 3:
                        col--;
                        break;
                }
                if (row <0 or row >=n or col <0 or col >= n or board[col][row]){
                    // 回退
                    col = init_col;
                    row = init_row;
                    direct = (init_dir + 1) % 4;
                    switch(direct){
                        case 0:
                            row ++;
                            break;
                        case 1:
                            col ++;
                            break;
                        case 2:
                            row --;
                            break;
                        case 3:
                            col--;
                            break;
                    }
                }
                board[col][row] = value++;
                 
            }
            return board;
        }
    };


int main(int argc, char const *argv[])
{
    Solution s;
    s.generateMatrix(3);
    return 0;
}
