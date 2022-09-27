////1.��ת�ַ���
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


////2.��ת�ַ�����
//#include <iostream>
//#include <string>
//using namespace std;
//string reverseString(string str, int k) {
//    for (int i = 0; i < str.size(); i += 2 * k) {
//        // 1. ÿ�� 2k ���ַ���ǰ k ���ַ����з�ת
//        // 2. ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ�
//        if (i + k <= str.size()) {
//            reverse(str.begin() + i, str.begin() + i + k);
//        }
//        else {
//            // 3. ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��
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


////3.��ת�ַ�����ĵ��ʣ���ʹ�ö���ռ䣩
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
//        //ȥ���ַ����ײ��ո�
//        while (str.size() > 0 && fastIndex < str.size() && str[fastIndex] == ' ') {
//            fastIndex++;
//        }
//        //ȥ���ַ����м�����ո�
//        for (; fastIndex < str.size(); fastIndex++) {
//            if (fastIndex - 1 > 0 && str[fastIndex - 1] == str[fastIndex] && str[fastIndex] == ' ') {
//                continue;
//            }
//            else {
//                str[slowIndex++] = str[fastIndex];
//            }
//        }
//        if (slowIndex - 1 > 0 && str[slowIndex - 1] == ' ') {
//            str.resize(slowIndex - 1);//ȥ���ַ���ĩβ�ո�
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
//                    str[slow++] = ' '; //���ʼ�ӿո�
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


////5.����ת�ַ�������ʹ�ö���ռ䣩
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    void reverse(string& s, int start, int end) { //�������������ұ�
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


////5.ʵ��strStr() //!KMP�㷨:�ַ���ƥ�� O(n+m)��Knuth��Morris��Pratt
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    //ǰ׺��:��¼�±�i֮ǰ������i�����ַ����У��ж�󳤶ȵ���ͬǰ׺��׺
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
//                j = next[j - 1];//ģʽ���±�j�����±�next[j - 1]����ƥ��
//            }
//            if (haystack[i] == needle[j]) {
//                j++;
//            }
//            if (j == needle.size()) {
//                return (i - needle.size() + 1); //�����ı���ƥ�䵽����λ�ã�λ�ô�0����
//            }
//        }
//        return -1;
//    }
//};
//int main()
//{
//    string str1 = "abcdefg"; //�ı���
//    string str2 = "de"; //ģʽ��
//    Solution solution;
//    cout << solution.strStr(str1, str2); //3
//    return 0;
//}


////6.�ظ������ַ���
//#include <iostream>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    //�ƶ�ƥ��
//    bool repetedSubstring1(string& s) {
//        string ss = s + s;
//        ss.erase(ss.begin());//ȥ����ͷ
//        ss.erase(ss.end() - 1);//ȥ����β
//        if (ss.find(s) != string::npos) return true;
//        return false;
//    }
//    //ǰ׺��:��¼�±�i֮ǰ������i�����ַ����У��ж�󳤶ȵ���ͬǰ׺��׺
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
//    //!KMP�㷨
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