////1.反转字符串
//#include <iostream>
//#include <string>
//using namespace std;
//void reverseString(string& str) {
//    int i = 0;
//    int j = str.size() - 1;
//    for (; i < str.size() / 2; ++i, --j) {
//        swap(str[i], str[j]);
//    }
//}
//int main()
//{
//    string str;
//    while (cin >> str) {
//        reverseString(str);
//        cout << str << endl;
//    }
//    return 0;
//}


////2.反转字符串Ⅱ
//#include <iostream>
//#include <string>
//using namespace std;
//string reverseString(string str, int k) {
//    for (int i = 0; i < str.size(); i += 2 * k) {
//        // 1. 每隔 2k 个字符的前 k 个字符进行反转
//        // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
//        if (i + k <= str.size()) {
//            reverse(str.begin() + i, str.begin() + i + k);
//        }
//        else {
//            // 3. 剩余字符少于 k 个，则将剩余字符全部反转。
//            reverse(str.begin() + i, str.end());
//        }
//    }
//    return str;
//}
//int main()
//{
//    string str;
//    int k = 2;
//    while (cin >> str) {
//        cout << reverseString(str, k) << endl;
//    }
//    return 0;
//}


////3.翻转字符串里的单词（不使用额外空间）
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    void reverse(string& s, int start, int end) {
//        for (int i = start, j = end; i < j; i++, j--) {
//            swap(s[i], s[j]);
//        }
//    }
//    void removeExtraSpaces1(string& str) {
//        int slowIndex = 0, fastIndex = 0;
//        //去掉字符串首部空格
//        while (str.size() > 0 && fastIndex < str.size() && str[fastIndex] == ' ') {
//            fastIndex++;
//        }
//        //去掉字符串中间冗余空格
//        for (; fastIndex < str.size(); fastIndex++) {
//            if (fastIndex - 1 > 0 && str[fastIndex - 1] == str[fastIndex] && str[fastIndex] == ' ') {
//                continue;
//            }
//            else {
//                str[slowIndex++] = str[fastIndex];
//            }
//        }
//        if (slowIndex - 1 > 0 && str[slowIndex - 1] == ' ') {
//            str.resize(slowIndex - 1);//去掉字符串末尾空格
//        }
//        else {
//            str.resize(slowIndex);
//        }
//    }
//    void removeExtraSpaces2(string& str) {
//        int slow = 0;
//        for (int i = 0; i < str.size(); ++i) {
//            if (str[i] != ' ') {
//                if (slow != 0)
//                    str[slow++] = ' '; //单词间加空格
//                while (i < str.size() && str[i] != ' ') {
//                    str[slow++] = str[i++];
//                }
//            }
//        }
//        str.resize(slow);
//    }
//    string reverseWords(string s) {
//        removeExtraSpaces2(s);
//        reverse(s, 0, s.size() - 1);
//        int start = 0;
//        for (int i = 0; i <= s.size(); ++i) {
//            if (i == s.size() || s[i] == ' ') {
//                reverse(s, start, i - 1);
//                start = i + 1;
//            }
//        }
//        return s;
//    }
//};
//int main()
//{
//    string str = "the sky is blue";
//    Solution solution;
//    cout << solution.reverseWords(str);
//    return 0;
//}


////5.左旋转字符串（不使用额外空间）
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    void reverse(string& s, int start, int end) { //这个函数是左闭右闭
//        for (int i = start, j = end; i < j; i++, j--) {
//            swap(s[i], s[j]);
//        }
//    }
//    string reverseLeftWords(string s, int n) {
//        reverse(s, 0, n - 1);
//        reverse(s, n, s.size() - 1);
//        reverse(s, 0, s.size() - 1);
//        return s;
//    }
//};
//int main()
//{
//    string str = "abcdefg";
//    Solution solution;
//    cout << solution.reverseLeftWords(str, 3);
//    return 0;
//}


////5.实现strStr() //!KMP算法:字符串匹配 O(n+m)、Knuth，Morris和Pratt
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    //前缀表:记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀
//    void getNext(int* next, const string& s) {
//        int j = 0;
//        next[0] = 0;
//        for (int i = 1; i < s.size(); ++i) {
//            while (j > 0 && s[i] != s[j]) {
//                j = next[j - 1];
//            }
//            if (s[i] == s[j]) {
//                j++;
//            }
//            next[i] = j;
//        }
//    }
//    int strStr(string haystack, string needle) {
//        if (needle.size() == 0) return 0;
//        int* next = new int[needle.size()];
//        getNext(next, needle);
//        int j = 0;//
//        for (int i = 0; i < haystack.size(); ++i) {
//            while (j > 0 && haystack[i] != needle[j]) {
//                j = next[j - 1];//模式串下标j跳到下标next[j - 1]重新匹配
//            }
//            if (haystack[i] == needle[j]) {
//                j++;
//            }
//            if (j == needle.size()) {
//                return (i - needle.size() + 1); //返回文本串匹配到的首位置（位置从0算起）
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string str1 = "abcdefg"; //文本串
//    string str2 = "de"; //模式串
//    Solution solution;
//    cout << solution.strStr(str1, str2); //3
//    return 0;
//}


////6.重复的子字符串
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    //移动匹配
//    bool repetedSubstring1(string& s) {
//        string ss = s + s;
//        ss.erase(ss.begin());//去掉开头
//        ss.erase(ss.end() - 1);//去掉结尾
//        if (ss.find(s) != string::npos) return true;
//        return false;
//    }
//    //前缀表:记录下标i之前（包括i）的字符串中，有多大长度的相同前缀后缀
//    void getNext(int* next, const string& s) {
//        int j = 0;
//        next[0] = 0;
//        for (int i = 1; i < s.size(); ++i) {
//            while (j > 0 && s[i] != s[j]) {
//                j = next[j - 1];
//            }
//            if (s[i] == s[j]) {
//                j++;
//            }
//            next[i] = j;
//        }
//    }
//    //!KMP算法
//    bool repetedSubstring2(string s) {
//        if (s.size() == 0) return false;
//        int* next = new int[s.size()];
//        getNext(next, s);
//        int len = s.size();
//        if (next[len - 1] != 0 && len % (len - (next[len - 1])) == 0) {
//            return true;
//        }
//        return false;
//    }
//};
//int main()
//{
//    string str = "dede"; 
//    Solution solution;
//    cout << solution.repetedSubstring1(str); //3
//    return 0;
//}