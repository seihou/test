//������ϣ�ṹ�����顢set��map
// ��Ҫ��ѯһ��Ԫ���Ƿ���ֹ�������һ��Ԫ���Ƿ��ڼ������ʱ�򣬾�Ҫ��һʱ���뵽��ϣ��
////1.��Ч����λ��
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


////2.��������Ľ���
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
//        return vector<int>(result.begin(), result.end()); //��unordered_set<int>���͸�ֵ��vector<int>
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


////3.������
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
//            if (set.find(sum) != set.end()) { //sum�ظ����֣����ǿ�����
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

////4.����֮��
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
//                return { iter->second, i }; //�����ҵ���ֵ��λ��
//            }
//            // ���û�ҵ�ƥ��ԣ��Ͱѷ��ʹ���Ԫ�غ��±���뵽map��
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


////5.������Ӣ�
//#include <iostream>
//#include <unordered_map>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
//        unordered_map<int, int> map;
//        for (int i : A) {
//            for (int j : B) {
//                map[i + j]++;
//            }
//        }
//        int count = 0;
//        for (int i : C) {
//            for (int j : D) {
//                if (map.find(0 - (i + j)) != map.end()) {
//                    count += map[0 - (i + j)];
//                }
//            }
//        }
//        return count;
//    }
//};
//int main()
//{
//    int a[] = { 1,2 };
//    vector<int> A(a, a + sizeof(a) / sizeof(*a));
//    int b[] = { -2,-1 };
//    vector<int> B(b, b + sizeof(b) / sizeof(*b));
//    int c[] = { -1,2 };
//    vector<int> C(c, c + sizeof(c) / sizeof(*c));
//    int d[] = { 0,2 };
//    vector<int> D(d, d + sizeof(d) / sizeof(*d));
//    Solution solution;
//    cout << solution.fourSumCount(A, B, C, D) << endl;
//    return 0;
//}


////6.�����
//#include <iostream>
//#include <unordered_map>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    //force brute
//    bool canRansom1(string ransomtxt, string magazine) {
//        for (int i = 0; i < magazine.size(); i++) {
//            for (int j = 0; j < ransomtxt.size(); j++) {
//                if (magazine[i] == ransomtxt[j]) {
//                    ransomtxt.erase(ransomtxt.begin() + j);//
//                    break;
//                }
//            }
//        }
//        if (ransomtxt.size() == 0)
//            return true;
//        return false;
//    }
//    //��ϣ��
//    bool canRansom2(string ransomtxt, string magazine) {
//        int record[26] = { 0 };
//        if (magazine.size() < ransomtxt.size()) return false;
//        for (int i = 0; i < magazine.size(); ++i) {
//            record[magazine[i] - 'a']++;
//        }
//        for (int j = 0; j < ransomtxt.size(); ++j) {
//            record[ransomtxt[j] - 'a']--;
//            if (record[ransomtxt[j] - 'a'] < 0)
//                return false;
//        }
//        return true;
//    }
//};
//int main()
//{
//    string a = "aa";
//    string b = "aa";
//    Solution solution;
//    cout << solution.canRansom2(a, b) << endl;
//    return 0;
//}


////7.����֮�� // �ҳ�a + b + c = 0
//#include <iostream>
//#include <unordered_set>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	//��ϣ��
//	vector<vector<int>> threeSum1(vector<int>& nums) {
//		vector<vector<int>> result;
//		unordered_set<int> set;
//		// a = nums[i], b = nums[j], c = -(a + b)
//		sort(nums.begin(), nums.end());
//		for (int i = 0; i < nums.size(); ++i) {
//			if (nums[i] > 0) break;
//			//��Ԫ��Ԫ��aȥ��
//			if (i > 0 && nums[i] == nums[i - 1]) {
//				continue;
//			}
//			//��Ԫ��Ԫ��bȥ��
//			for (int j = i + 1; j < nums.size(); ++j) {
//				if (j > i + 2 && nums[j] == nums[j - 1] && nums[j - 1] == nums[j - 2]) {
//					continue;
//				}
//				int c = 0 - (nums[i] + nums[j]);
//				if (set.find(c) != set.end()) {
//					result.push_back({ nums[i], nums[j], c });
//					set.erase(c);//��Ԫ��Ԫ��cȥ��
//				}
//				else {
//					set.insert(nums[j]);
//				}
//			}
//		}
//		return result;
//	}
//	//˫ָ�뷨
//	vector<vector<int>> threeSum2(vector<int>& nums) {
//		vector<vector<int>> result;
//		sort(nums.begin(), nums.end());
//		// a = nums[i], b = nums[left], c = nums[right]
//		for (int i = 0; i < nums.size(); ++i) {
//			if (nums[i] > 0) break;
//			if (i > 0 && nums[i] == nums[i - 1]) {
//				continue;
//			}
//			int left = i + 1;
//			int right = nums.size() - 1;
//			while (left < right) {
//				if (nums[i] + nums[left] + nums[right] > 0) right--;
//				else if (nums[i] + nums[left] + nums[right] < 0) left++;
//				else {
//					result.push_back({ nums[i], nums[left], nums[right] });
//					while (right > left && nums[right] == nums[right - 1]) right--;
//					while (right > left && nums[left] == nums[left + 1]) left++;
//					// �ҵ���ʱ��˫ָ��ͬʱ����
//					right--;
//					left++;
//				}
//			}
//		}
//		return result;
//	}
//};
//int main()
//{
//	int a[] = { -1, 0, 1, 2, -1, -4 };
//	vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//	Solution solution;
//	vector<vector<int>> result = solution.threeSum2(nums);
//	for (auto i : result) {
//		for (auto j : i) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}


////8.����֮��
//#include <iostream>
//#include <unordered_set>
//#include <vector>
//#include <algorithm>
//using namespace std;
//class Solution {
//public:
//	//˫ָ�뷨
//	vector<vector<int>> fourSum(vector<int>& nums, int target) {
//		vector<vector<int>> result;
//		sort(nums.begin(), nums.end());
//		// a = nums[i], b = nums[left], c = nums[right]
//		for (int i = 0; i < nums.size(); ++i) {
//			// ��֦����
//			if (nums[i] >= 0 && nums[i] > target) break;
//			// ��nums[i]ȥ��
//			if (i > 0 && nums[i] == nums[i - 1]) continue;
//			for (int j = i + 1; j < nums.size(); ++i)
//			{
//				// 2����֦����
//				if (nums[j] + nums[i] > target && nums[j] + nums[i] >= 0) break;
//				// ��nums[i]ȥ��
//				if (i > j + 1 && nums[i] == nums[i - 1]) continue;
//				int left = i + 1;
//				int right = nums.size() - 1;
//				while (left < right) {
//					if ((long)(nums[i] + nums[j] + nums[left] + nums[right]) > 0) right--;
//					else if ((long)(nums[i] + nums[j] + nums[left] + nums[right]) < 0) left++;
//					else {
//						result.push_back({ nums[i], nums[left], nums[right] });
//						while (right > left && nums[right] == nums[right - 1]) right--;
//						while (right > left && nums[left] == nums[left + 1]) left++;
//						// �ҵ���ʱ��˫ָ��ͬʱ����
//						right--;
//						left++;
//					}
//				}
//			}
//		}
//		return result;
//	}
//};
//int main()
//{
//	int a[] = { 1, 0, -1, 0, -2, 2 };
//	int target = 0;
//	vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//	Solution solution;
//	vector<vector<int>> result = solution.fourSum(nums, target);
//	for (auto i : result) {
//		for (auto j : i) {
//			cout << j << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}