#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int MOD = 1e9+7;
int pow(int a,int b,int m){
    // 将b拆成二进制位
    int result = 1;
    int mut = a;
    while ( b)
    {
        if (b%2) 
            result = result % m * mut;
        mut *= mut;
        mut %= MOD;
        b /= 2;
    }
    return result;
}
vector<vector<int>> MatrixMutpile(vector<vector<int>> a,vector<vector<int>> b){
    int m= a.size(),n = b.size(),s = b[0].size();
    vector<vector<int>> c = vector<vector<int>>(m,vector<int>(s,0));
    for (int i = 0;i<m;i++){
        for (int j = 0;j<s;j++){
            for (int k = 0;k<n;k++){
                c[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return c;
}
int pow(vector<vector<int>> a,int b,int m){
    vector<vector<int>> I(2,vector<int>(2,0));
    I[0][0] = 1;
    I[1][1] = 1;
    vector<vector<int>> mut = a;
    while (b){
        if (b%2)
        I  = MatrixMutpile(I,mut);
        mut = MatrixMutpile(mut,mut);
        b /= 2;
    }

    vector<vector<int>> B(2,vector<int>(1,1));
    B[1][0] = 0;

    I = MatrixMutpile(I,B);
    return I[1][0];
    
}
int main(int argc, char const *argv[])
{
    vector<vector<int>> A(2,vector<int>(2,1));
    A[1][1] = 0;
    cout<<pow(A,6,1);
    return 0;
}

