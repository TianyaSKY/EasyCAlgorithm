#include <string>
#include <algorithm>
using namespace std;
class Solution {
    public:
        bool isPalindrome(string s) {
            int ptr1 = s.size()-1;
            int ptr2 = 0;
            while (ptr2<=ptr1){
                if (!isValid(s[ptr1])){
                     ptr1--;
                     continue;
                }
                if (!isValid(s[ptr2])){
                    ptr2 ++;
                    continue;
                }
                int d = abs(s[ptr1]-s[ptr2]);
                if (d!=0){
                    if (!isA(s[ptr1]) or !isA(s[ptr2]) or d!=32)
                        return false;
                };
                ptr1--;
                ptr2++;
            }
            return true;
        }
        bool isValid(char c){
            if (c<='9' and c >= '0') return true;
            if (c<='Z' and c >='A') return true;
            if (c<='z' and c >='a') return true;
            return false;
        }
        bool isA(char c){
            if (c<='Z' and c >='A') return true;
            if (c<='z' and c >='a') return true;
            return false;
        }
    };


int main(int argc, char const *argv[])
{
    
    Solution s;
    int result = s.isPalindrome("0p");
    return 0;
}
