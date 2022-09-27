//常见哈希结构：数组、set、map
////1.有效的异位词
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool isAnagram(string s1, string s2) {
//        int record[26] = { 0 };
//        for (int i = 0; i < s1.size(); ++i) {
//            record[s1[i] - 'a']++;
//        }
//        for (int i = 0; i < s2.size(); ++i) {
//            record[s2[i] - 'a']--;
//        }
//        for (int i = 0; i < 26; ++i) {
//            if (record[i] != 0) {
//                return false;
//            }
//        }
//        return true;
//    }
//};
//int main()
//{
//    string s1 = "anagram";
//    string s2 = "nagaram";
//    Solution solution;
//    cout << solution.isAnagram(s1, s2) << endl;
//    return 0;
//}


////2.两个数组的交集
//#include <iostream>
//#include <vector>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    vector<int> intersection(vector<int> n1, vector<int> n2) {
//        unordered_set<int> result;
//        unordered_set<int> nums(n1.begin(), n1.end());
//        for (int i : n2) {
//            if (nums.find(i) != nums.end()) {
//                result.insert(i);
//            }
//        }
//        return vector<int>(result.begin(), result.end());
//    }
//};
//int main()
//{
//    int a[] = { 4,9,5 };
//    int b[] = { 9,4,9,8,4 };
//    vector<int> nums1(a, a + sizeof(a) / sizeof(*a));
//    vector<int> nums2(b, b + sizeof(b) / sizeof(*b));
//    Solution solution;
//    vector<int> result = solution.intersection(nums1, nums2);
//    for (auto i : result)
//        cout << i << " ";
//    return 0;
//}


////3.快乐数
//#include <iostream>
//#include <unordered_set>
//using namespace std;
//class Solution {
//public:
//    int getSum(int n) {
//        int sum = 0;
//        while (n) {
//            sum += (n % 10) * (n % 10);
//            n /= 10;
//        }
//        return sum;
//    }
//    bool isHappy(int n) {
//        unordered_set<int> set;
//        while (1) {
//            int sum = getSum(n);
//            if (sum == 1) {
//                return true;
//            }
//            if (set.find(sum) != set.end()) { //sum重复出现，不是快乐数
//                return false;
//            }
//            else {
//                set.insert(sum);
//            }
//            n = sum;
//        }
//    }
//};
//int main()
//{
//    int a;
//    cin >> a;
//    Solution solution;
//    cout << solution.isHappy(a) << endl;
//    return 0;
//}

////4.两数之和
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    vector<int> twoNumSum(vector<int> nums, int target) {
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); ++i) {
//            auto iter = map.find(target - nums[i]);
//            if (iter != map.end()) {
//                return { iter->second, i }; //返回找到的值的位置
//            }
//            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
//            map.insert(pair<int, int>(nums[i], i));
//        }
//        return {};
//    }
//};
//int main()
//{
//    int target = 9;
//    int a[] = { 2,7,11,15 };
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution solution;
//    vector<int> result = solution.twoNumSum(nums, target);
//    for (auto i : result)
//        cout << i << " ";
//    return 0;
//}


//5.
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoNumSum(vector<int> nums, int target) {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); ++i) {
            auto iter = map.find(target - nums[i]);
            if (iter != map.end()) {
                return { iter->second, i }; //返回找到的值的位置
            }
            // 如果没找到匹配对，就把访问过的元素和下标加入到map中
            map.insert(pair<int, int>(nums[i], i));
        }
        return {};
    }
};
int main()
{
    int target = 9;
    int a[] = { 2,7,11,15 };
    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
    Solution solution;
    vector<int> result = solution.twoNumSum(nums, target);
    for (auto i : result)
        cout << i << " ";
    return 0;
}