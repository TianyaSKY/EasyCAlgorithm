#include <iostream>
#include <vector>
int rank(const std::vector<int> nums,int key){
    int low =0;
    int high = nums.size()-1;
    while (low<=high)
    {
        /* code */
        int mid = (low+high) /2;
        if (key>nums[mid]) low = mid+1;
        else if (key<nums[mid]) high = mid-1;
        else return mid;

    }
    return -1;   
}
int main(int argc, char const *argv[])
{   
    std::cout<<rank({2,3,4,5,6,12},12);
    return 0;
}
