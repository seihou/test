//1.二分查找
#include <iostream>
#include <vector>
using namespace std;
class Solution1 {
public:
    //[left, right]
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle - 1;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};
class Solution2 {
public:
    //[left, right)
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        while (left < right) {
            int middle = left + ((right - left) / 2);
            if (nums[middle] > target) {
                right = middle;
            }
            else if (nums[middle] < target) {
                left = middle + 1;
            }
            else {
                return middle;
            }
        }
        return -1;
    }
};
int main()
{
    int a[] = { -1,0,3,5,9,12 };
    int target = 9;
    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
    Solution2 solution2;
    cout << solution2.search(nums, target) << endl;
    return 0;
}