#include <string>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            int n = nums.size();
            vector<vector<vector<int>>> checked(n,vector<vector<int>>(n,vector<int>(n,0)));
            vector<vector<int>> result;
            sort(nums.begin(),nums.end());
            for (int i = 0;i<nums.size();i++){
                int ptr1 = i+1;
                int ptr2 = nums.size()-1;
                while (ptr1<ptr2 and ptr1 <nums.size() and ptr2 > i){
                    if (nums[i]+nums[ptr1]+nums[ptr2] < 0){
                        ptr1 ++;
                    }
                    else if (nums[i]+nums[ptr1]+nums[ptr2] > 0){
                        ptr2 --;
                    }
                    else {
                        
                        result.push_back({nums[i],nums[ptr1],nums[ptr2]});
                        while (ptr2 > ptr1 && nums[ptr2] == nums[ptr2 - 1]) ptr2--;
                        while (ptr2 > ptr1 && nums[ptr1] == nums[ptr1 + 1]) ptr1++;
    
                        // 找到答案时，双指针同时收缩
                        ptr2--;
                        ptr1++;
                    }
                }
            }
            return result;
        }
    };

    int main(int argc, char const *argv[])
    {
        Solution s;
        vector<int> v = {-1,0,1,2,-1,-4};
        s.threeSum(v);
        return 0;
    }
    