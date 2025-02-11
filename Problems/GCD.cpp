#include <iostream>
int gcd(int a,int b){
    if (b==0) return a;
    return gcd(b,a%b);
}
int lcd(int a, int b){
    return a/gcd(a,b) *b;
}
int main(int argc, char const *argv[])
{
    std::cout<< gcd(12,16)<<std::endl;
    std::cout<<lcd(36,24)<<std::endl;
    return 0;
}
