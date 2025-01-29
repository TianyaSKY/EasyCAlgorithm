
#include <iostream>
// 要分为最小的正方形
int min(int a,int b){
    return a<b?a:b;
}
int max(int a,int b){
    return a>b?a:b;
}
int mini(int width, int height){
    if (height==width) return height;

    int min_block = min(width,height);
    int max_block = max(width,height);

    int ma = max_block;
    while (ma>min_block)
    {
        ma -= min_block;
    }
    return mini(ma,min_block);
    
}
int main(int argc, char const *argv[])
{
    std::cout<<mini(1680,640)<<std::endl;
    return 0;
}
