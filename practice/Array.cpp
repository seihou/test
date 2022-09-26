////1.二分查找
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution1 {
//public:
//    //[left, right]
//    int search(vector<int>& nums, int target) {
//        int left = 0;
//        int right = nums.size() - 1;//
//        while (left <= right) {
//            int middle = left + ((right - left) / 2);
//            if (nums[middle] > target) {
//                right = middle - 1;
//            }
//            else if (nums[middle] < target) {
//                left = middle + 1;
//            }
//            else {
//                return middle;
//            }
//        }
//        return -1;
//    }
//};
//class Solution2 {
//public:
//    //[left, right)
//    int search(vector<int>& nums, int target) {
//        int left = 0;
//        int right = nums.size();//
//        while (left < right) {
//            int middle = left + ((right - left) / 2);
//            if (nums[middle] > target) {
//                right = middle;
//            }
//            else if (nums[middle] < target) {
//                left = middle + 1;
//            }
//            else {
//                return middle;
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    int a[] = { -1,0,3,5,9,12 };
//    int target = 9;
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution2 solution2;
//    cout << solution2.search(nums, target) << endl;
//    return 0;
//}


////2.移除数组元素
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution1 {
//public:
//    //force brute
//    int removeElement(vector<int>& nums, int val) {
//        int size = nums.size();
//        for (int i = 0; i <= size - 1; ++i) {
//            if (nums[i] == val) {
//                for (int j = i + 1; j < size; ++j) {
//                    nums[j - 1] = nums[j];
//                }
//                i--;//
//                size--;//
//            }
//        }
//        return size;
//    }
//};
//class Solution2 {
//public:
//    //!双指针法(快慢指针法):不改变元素相对位置
//    int removeElement(vector<int>& nums, int val) {
//        int slowIndex = 0;
//        for (int fastIndex = 0; fastIndex < nums.size(); ++fastIndex) {
//            if (val != nums[fastIndex]) {
//                nums[slowIndex++] = nums[fastIndex];
//            }
//        }
//        return slowIndex;
//    }
//};
//class Solution3 {
//public:
//    //相向双指针方法:改变了元素相对位置，确保了移动最少元素
//    int removeElement(vector<int>& nums, int val) {
//        int leftIndex = 0;
//        int rightIndex = nums.size() - 1;
//        while (leftIndex <= rightIndex) {
//            //左边找等于val的元素
//            while (leftIndex <= rightIndex && nums[leftIndex] != val) {
//                ++leftIndex;
//            }
//            //右边找不等于val的元素
//            while (leftIndex <= rightIndex && nums[rightIndex] == val) {
//                --rightIndex;
//            }
//            if (leftIndex < rightIndex) {
//                nums[leftIndex++] = nums[rightIndex--];
//            }
//        }
//        return leftIndex;
//    }
//};
//int main()
//{
//    int a[] = { 0,1,2,2,3,0,4,2 };
//    int val = 2;
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution2 solution2;
//    cout << solution2.removeElement(nums, val) << endl;
//    return 0;
//}


////3.有序数组的平方
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution1 {
//public:
//    //force brute
//    vector<int> sortedSquares(vector<int>& nums) {
//        for (int i = 0; i < nums.size(); ++i) { //O(n)
//            nums[i] *= nums[i];
//        }
//        sort(nums.begin(), nums.end());//O(nlogn)
//        return nums;
//    }
//};
//class Solution2 {
//public:
//    //!双指针法
//    vector<int> sortedSquares(vector<int>& nums) {
//        int i = 0;
//        int j = nums.size() - 1;
//        int k = j;
//        vector<int> result(nums.size(), 0);
//        for (; i <= j;) {
//            if (nums[i] * nums[i] < nums[j] * nums[j]) {
//                result[k--] = nums[j] * nums[j];
//                j--;
//            }
//            else {
//                result[k--] = nums[i] * nums[i];
//                i++;
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    int a[] = { -7,-3,2,3,11 };
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution2 solution2;
//    vector<int> result(nums.size());
//    result = solution2.sortedSquares(nums);
//    for (auto i : result) {
//        cout << i << ",";
//    }
//    return 0;
//}

////4.长度最小的子数组
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution1 {
//public:
//    //force brute
//    int minSubArrayLen(int s, vector<int>& nums) {
//        int result = INT32_MAX;//
//        int sum = 0;
//        int subLength = 0;
//        for (int i = 0; i < nums.size(); ++i) {
//            sum = 0;//
//            for (int j = i; j < nums.size(); ++j) {
//                sum += nums[j];
//                if (sum >= s) {
//                    subLength = j - i + 1;
//                    result = min(result, subLength);
//                }
//            }
//       }
//        return result;
//    }
//};
//class Solution2 {
//public:
//    //!滑动窗口(双指针法的一种
//    int minSubArrayLen(int s, vector<int>& nums) {
//        int result = INT32_MAX;
//        int sum = 0;
//        int subLength = 0;
//        int i = 0;
//        for (int j = 0; j < nums.size(); ++j) {
//            sum += nums[j];
//            // 注意这里使用while，每次更新 i（起始位置），并不断比较子序列是否符合条件
//            while (sum >= s) { 
//                subLength = j - i + 1;
//                result = min(result, subLength);
//                sum -= nums[i++];//关键
//            }
//        }
//        return result == INT32_MAX ? 0 : result;//
//    }
//};
//int main()
//{
//    int a[] = { 2,3,1,2,4,3 };
//    int s = 7;
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution2 solution2;
//    cout << solution2.minSubArrayLen(s, nums) << endl;
//    return 0;
//}


////5.螺旋矩阵Ⅱ
//#include <iostream>
//#include <vector>
//using namespace std;
//class Solution1 {
//public:
//    vector<vector<int>> genetateMatrix(int num) {
//        vector<vector<int>> result(num, vector<int>(num, 0));
//        int startx = 0, starty = 0;
//        int loop = num / 2;//循环次数
//        int mid = num / 2; //矩阵中间的位置
//        int count = 1;
//        int offset = 1;//控制每一条边遍历的长度
//        int i, j;
//        while (loop--) {
//            i = startx;
//            j = starty;
//            for (j = starty; j < num - offset; ++j) {
//                result[startx][j] = count++;
//            }
//            for (i = startx; i < num - offset; ++i) {
//                result[i][j] = count++;
//            }
//            for (; j > starty; --j) {
//                result[i][j] = count++;
//            }
//            for (; i > startx; --i) {
//                result[i][j] = count++;
//            }
//            startx++;
//            starty++;
//            offset++;//每次循环右边界收缩一位
//            //为奇数时，需要在中间位置单独赋值
//            if (num % 2 == 1) {
//                result[mid][mid] = count;
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    int num = 4;
//    Solution1 solution1;
//    vector<vector<int>> res = solution1.genetateMatrix(num);
//    for (auto i : res) {
//        for (auto j : i) {
//            cout << j << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

