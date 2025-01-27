// 利用动态规划求解背包问题
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>


std::unordered_map<std::string,std::pair<int,int>> item;
std::vector<std::string> names({"guitar","radio","laptop","iphone"});

void initVal(){
    
    item["guitar"] = {1,1500};
    item["radio"] = {4,3000};
    item["laptop"] = {3,2000};
    item["iphone"] = {1,2000};
} 


int BagProblem(int maxsize){
    std::vector<std::vector<int>> bag(item.size(),std::vector<int>(maxsize+1));
    for (int i = 0;i<maxsize+1;i++){  // 填充只能放置吉他下情况
        bag[0][i] = item[names[0]].second;
    }
    bag[0][0] = 0;
    for (int i = 1;i<item.size();i++){
        for (int j = 0;j<maxsize+1;j++){
            if (j>=item[names[i]].first)
                bag[i][j] = std::max(bag[i-1][j],item[names[i]].second+bag[i-1][j-item[names[i]].first]);
            else bag[i][j] = bag[i-1][j];
        }
    }
    
    return bag[item.size()-1][maxsize];

};

int main(int argc, char const *argv[])
{
    initVal();
    std::cout<<BagProblem(0)<<std::endl;
    return 0;
}
