﻿//https://zhaitianbao.blog.csdn.net/article/details/120820959

////1.字符串最后一个单词的长度：字符串
//#include <iostream>
//using namespace std;
//int main()
//{
//    char input[100];
//    cin.getline(input, 100);
//    int number = 0;
//    int input_number = strlen(input);
//    int i = input_number - 1;
//    while (input[i] != ' ') {
//        ++number;
//        if (i == 0) {
//            break;
//        }
//        --i;
//    }
//    cout << number << endl;
//    return 0;
//}


////2.计算某字母出现次数：字符串、ASCII码、哈希
//#include <iostream>
//#include <string>
//using namespace std;
//int main() {
//	//char i_line1[500];
//	//cin.getline(i_line1, 500);
//	string i_line1;
//	getline(cin, i_line1);
//	char i_line2;
//	cin >> i_line2;
//	cout << "search:" << i_line2 << endl;
//	int num1 = i_line1.length();
//	int count = 0;
//	for (int i = 0; i < num1; i++) {
//		if (i_line1[i] == toupper(i_line2) || i_line1[i] == tolower(i_line2)) {
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}

////3.明明的随机数：STL、map、数组、哈希
//#include <iostream>
//#include <unordered_map>
//#include <set>
//using namespace std;
//use map
//int main() 
//{
//	int number, n;
//	while (cin >> number) {
//		unordered_map<int, int> a;
//		while (number--) {
//			cin >> n;
//			a.insert({ n, 1 });
//		}
//		for (int i = 1; i < 1001; i++) {
//			if (a[i] == 1)
//				cout << i << endl;
//		}
//		cout << a[0] << endl;
//	}
//	return 0;
//}
// use set
//int main() {
//	int n(0);
//	while (cin >> n) {
//		set<int> data;
//		while (n--) {
//			int t;
//			cin >> t;
//			data.insert(t);
//		}
//		for (auto val : data)
//			cout << val << endl;
//	}
//	return 0;
//}

////4.字符串分隔
//#include <iostream>
//#include <string>
//using namespace std;
//int main() 
//{
//	string str;
//	while (cin >> str) {
//		cout << str.size() << endl;
//		int left = str.size() % 8;
//		while (str.size() >= 8) {
//			cout << str.substr(0, 8);
//			str = str.substr(8);
//		}
//		if (left) {
//			int number;
//			number = 8 - left;
//			str.append(number, '0');
//			cout << str << endl;
//		}
//	}
//	return 0;
//}

////5.进制转换：字符串、位运算、进制操作
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int input;
//	while (cin >> hex >> input) //16进制读取
//	{
//		cout << input << endl;
//	}
//	return 0;
//}
// 
//int main()
//{
//	string str;
//	while (cin >> str) //16进制读取
//	{
//		int bit = 0;
//		int ans = 0;
//		for (int i = str.length() - 1; i > 1; i--) {
//			if (str[i] >= '0' && str[i] <= '9') {
//				ans += pow(16, bit++) * str[i];
//			}
//			else if (str[i] >= 'A' && str[i] <= 'F') {
//				ans += pow(16, bit++) * (str[i] - 'A' + 10);
//			}
//		}
//		cout << ans << endl;
//	}
//	return 0;
//}

////6.质数因子：数学、排序
//#include <iostream>
//#include <string>
//using namespace std;
//int main() 
//{
//	long num;
//	while (cin >> num) {
//		for (long i = 2; i < sqrt(num) + 1; i++) { //最小因子1，最大因子sqrt(num)
//			while (num % i == 0) {
//				cout << i << ' ';
//				num /= i;
//			}
//		}
//		if (num > 1)
//			cout << num << ' '<< endl;
//	}
//	return 0;
//}

////7.取近似值
//#include <iostream>
//#include <cmath>
//using namespace std;
//int main()
//{
//	float num;
//	cin >> num;
//	cout << static_cast<int>(num + 0.5) << endl; //1 直接强制转换
//	cout << round(num + 0.5) << endl; //2 round函数
//	return 0;
//}

////8.合并表记录：STL、哈希
//#include <iostream>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//	int n;
//	int key, value;
//	int max = 0;
//	cin >> n;
//	unordered_map<int, int> map;
//	for (int i = 0; i < n; i++) {
//		cin >> key;
//		cin >> value;
//		map[key] += value;
//		if (key > max)
//			max = key;
//	}
//	for (int i = 0; i <= max; i++) {
//		if (map[i] != 0)
//			cout << i << ' ' << map[i] << endl;
//	}
//	return 0;
//}

////9.提取不重复的整数：数组、位运算、哈希
//#include <iostream>
//using namespace std;
//int main()
//{
//	int num;
//	cin >> num;
//	int arr[10] = { 0 };
//	for (; 0 < num; num /= 10) {
//		if (!arr[num % 10]) {
//			cout << num % 10;
//			arr[num % 10] = 1;
//		}
//	}
//	return 0;
//}

////10.提取不重复的整数：数组、位运算、哈希
//#include <iostream>
//#include <string>
//#include <map>
//#include <unordered_set>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	map<char, int> table;
//	int num = 0;
//	for (int i = 0; i < str.length(); i++) {
//		if (table[str[i]] == 0) {
//			table[str[i]] = 1;
//			num++;
//		}
//	}
//	cout << num << endl;
//	return 0;
//}
//int main()
//{
//	string str;
//	cin >> str;
//	unordered_set<char> set;
//	for (auto c : str) {
//		if (c >= 0 && c <= 127)
//			set.insert(c);
//	}
//	cout << set.size() << endl;
//	return 0;
//}

////11.数字颠倒：字符串
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	reverse(str.begin(), str.end());//需要头文件algorithm
//	cout << str << endl;
//	return 0;
//}

////12.字符串反转：字符串 不用reverse
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	getline(cin, str);
//	int n = str.size() - 1;
//	for(int i = n; i >= 0; i--) {
//		cout << str[i];
//	}
//	return 0;
//}

////13.句子逆序：数组、字符串
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//int main()
//{
//	string str;
//	stack<string> s;
//	while (cin >> str) {	// ctrl + z 或 ctrl + d 终止输入
//		s.push(str);
//	}
//	/*for (int i = s.size(); i > 0; i--) {
//		cout << s.top() << ' ';
//		s.pop();
//	}*/
//	while (!s.empty()) {
//		cout << s.top() << ' ';
//		s.pop();
//	}
//	cout << endl;
//	system("pause");//暂停程序看结果
//	return 0;
//}

////14.字符串排序：字符串、排序
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int num;
//	cin >> num;
//	vector<string> vec;
//	string str;
//	for (int i = 0; i < num; i++) { //可以用while(num--)
//		cin >> str;
//		vec.push_back(str);
//	}
//	sort(vec.begin(), vec.end());
//	for (auto i : vec) {
//		cout << i << ' ';
//	}
//	cout << endl;
//	return 0;
//}

////15.求int型正整数在内存中存储时1的个数：位运算
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//////使用位运算
////int main()
////{
////	int n;
////	cin >> n;
////	int cnt;
////	for (cnt = 0; n; n &= n - 1) //位运算
////		cnt++;
////	cout << cnt << endl;
////	return 0;
////}
////使用移位统计1的个数
//int main()
//{
//	int n, res = 0;
//	cin >> n;
//	while (n) {
//		if (n % 2) res++;
//		n >>= 1;
//	}
//	cout << res << endl;
//	return 0;
//}

////16.购物单：动态规划、数组
////#include <iostream>
//#include <vector>
//using namespace std;
//int max(int n,int m)
//{
//	return (n > m) ? n : m;
//}
//int dp[3200];//存放结果
//int main()
//{
//	int N, n, v, p, q; //N:money_num n:item_num v:value p:priority q:main or appendix
//	cin >> N >> n;
//	int* ZJ_Pri = new int[n + 1](); int* ZJ_Imp = new int[n + 1]();
//	int* FJ1_Pri = new int[n + 1](); int* FJ1_Imp = new int[n + 1]();
//	int* FJ2_Pri = new int[n + 1](); int* FJ2_Imp = new int[n + 1]();
//
//	for (int i = 1; i <= n; i++) 
//	{
//		cin >> v >> p >> q; //q为0是主件，q>0是附件且q是所属主件的编号
//		if (q == 0) {
//			ZJ_Pri[i] = v;
//			ZJ_Imp[i] = v * p;
//		}
//		else if (FJ1_Pri[q] == 0) { //附件1
//			FJ1_Pri[q] = v;
//			FJ1_Imp[q] = v * p;
//		}
//		else {			//附件2
//			FJ2_Pri[q] = v;
//			FJ2_Imp[q] = v * p;
//		}
//	}
//	for (int i = 1; i <= n; i++) {  //前i个物品
//		for (int j = N; j > 0; j--) {	//当前的钱数
//			if (j >= ZJ_Pri[i]) //主体
//				dp[j] = max(dp[j], dp[j - ZJ_Pri[i]] + ZJ_Imp[i]);
//			if (j >= ZJ_Pri[i] + FJ1_Pri[i]) //主体和附件1
//				dp[j] = max(dp[j], dp[j - ZJ_Pri[i] - FJ1_Pri[i]] + ZJ_Imp[i] + FJ1_Imp[i]);
//			if (j >= ZJ_Pri[i] + FJ2_Pri[i]) //主体和附件2
//				dp[j] = max(dp[j], dp[j - ZJ_Pri[i] - FJ2_Pri[i]] + ZJ_Imp[i] + FJ2_Imp[i]);
//			if (j >= ZJ_Pri[i] + FJ1_Pri[i] + FJ2_Pri[i]) //主体和附件1和附件2
//				dp[j] = max(dp[j], dp[j - ZJ_Pri[i] - FJ1_Pri[i] - FJ2_Pri[i]] + ZJ_Imp[i] + FJ1_Imp[i] + FJ2_Imp[i]);
//		}
//	}
//	cout << dp[N] << endl;	
//	delete[] ZJ_Imp;
//	delete[] ZJ_Pri;
//	delete[] FJ1_Imp;
//	delete[] FJ1_Pri;
//	delete[] FJ2_Imp;
//	delete[] FJ2_Pri;
//	return 0;
//}

////17.坐标移动：字符串、正则表达式
//#include <iostream>
//#include <string>
//#include <vector>
//#include <regex> //
//using namespace std;
//// 分割字符序列
//void SplitString(string &str, vector<string> &vec, string c) //形参得传引用才能修改参数的值
//{
//	string::size_type pos1, pos2;	//pos 
//	pos2 = str.find(c);
//	pos1 = 0;
//	while (string::npos != pos2) {
//		vec.push_back(str.substr(pos1,pos2 - pos1));
//		pos1 = pos2 + c.size();  //起始位置加上字符序列大小
//		pos2 = str.find(c,pos1);
//	}
//	if (pos1 != str.length()) {
//		vec.push_back(str.substr(pos1));
//	}
//}
//int main()
//{
//	string str;
//	getline(cin, str);
//	int x = 0, y = 0;
//	vector<string> vec;
//	SplitString(str,vec,";");//
//	for (auto i : vec) {
//		if (i.empty()) {
//			continue;
//		}
//		string tmp = i.substr(1);//
//		if (regex_match(tmp,regex("[0-9]*"))) {
//			switch (i[0]) 
//			{
//				case 'A':x -= stoi(tmp); break;
//				case 'D':x += stoi(tmp); break;
//				case 'W':y += stoi(tmp); break;
//				case 'S':y -= stoi(tmp); break;
//				default :break;
//			}
//		}
//	}
//	cout << x << "," << y << endl;
//	return 0;
//}

////18.识别有效的IP地址和掩码并进行分类统计
//#include <iostream>
//#include <string>
//#include <vector>
//#include <list>
//using namespace std;
//bool isValid(const string &s, vector<int> &data)
//{
//	for (int i = 0; i < s.size(); ++i)
//	{
//		int j = i;
//		for (; j <= s.size(); ++j)
//		{
//			if (s[j] == '.' || j == s.size())
//			{
//				string number(s.begin() + i, s.begin() + j);
//				if (number.empty())
//					return false;
//				int num = atoi(number.c_str());
//				data.push_back(num);
//				break;
//			}
//		}
//		i = j;
//	}
//	if (data.size() != 4)
//		return false;
//	for (auto i : data)
//		if (i < 0 || i > 255)
//			return false;
//	return true;
//}
//bool ipValidHandle(string ip, vector<int> &data)
//{
//	return isValid(ip, data);
//}
//void dec2binary(int num, list<char> &mask_binary)
//{
//	for (int i = 0; i < 8; ++i)
//	{
//		mask_binary.push_front((num & 1) + '0'); //取num的最低位，并转化为单字符
//		num >>= 1;
//	}
//}
//bool maskValidHandle(const string &mask)
//{
//	vector<int> res;
//	list<char> mask_binary;
//	if (!isValid(mask, res))
//		return false;
//	for (int i = res.size() - 1; i >= 0; i--)
//		dec2binary(res[i], mask_binary); //10进制转2进制
//	bool find1 = false, find0 = false;
//	for (list<char>::iterator it = mask_binary.begin(); it != mask_binary.end(); ++it) //迭代器遍历list
//	{
//		if (!find1 && *it == '1')
//			find1 = true;
//		else if (!find0 && *it == '0')
//			find0 = true;
//		else if (find0 && *it == '1')
//			return false;
//	}
//	if (find0 && find1) //子网掩码必须既有1又有0
//		return true;
//	return false;
//}
//int main()
//{	
//	string line;
//	int ip_A = 0, ip_B = 0, ip_C = 0, ip_D = 0, ip_E = 0;
//	int ip_Err = 0, ip_Private = 0;
//	while (getline(cin, line)) 
//	{
//		for (int i = 0; i < line.size(); ++i)
//		{
//			if (line[i] == '~')
//			{
//				string ip(line.begin(), line.begin() + i);
//				string mask(line.begin() + i + 1, line.end());
//				vector<int> data;
//				if (ipValidHandle(ip, data) && maskValidHandle(mask)) //先排除错误的
//				{
//					if (data[0] >= 1 && data[0] <= 126)
//					{
//						if (data[0] == 10)
//							ip_Private++;
//						ip_A++;
//					}
//					else if (data[0] >= 128 && data[0] <= 191)
//					{
//						if (data[0] == 172 && (data[1] >= 16 && data[1] <= 31))
//							ip_Private++;
//						ip_B++;
//					}
//					else if (data[0] >= 192 && data[0] <= 223)
//					{
//						if (data[0] == 192 && data[1] == 168)
//							ip_Private++;
//						ip_C++;
//					}
//					else if (data[0] >= 224 && data[0] <= 239)
//						ip_D++;
//					else if ((data[0] >= 240 && data[0] <= 255))
//						ip_E++;
//				}
//				else
//					ip_Err++;
//				break;			
//			}
//		}
//	}
//	cout << ip_A << ip_B << ip_C << ip_D << ip_E << ip_Err << ip_Private << endl;
//	return 0;
//}

////19.简单错误记录：字符串、STL
//#include <iostream>
//#include <string>
//#include <vector>
//#include <map>
//using namespace std;
//int main()
//{
//	char filepath[1000];
//	string col;
//	map<string, int> m;
//	vector<string> result;
//	while (cin >> filepath >> col) //char数组输入字符序列
//	{
//		char* c = strrchr(filepath, '\\'); //查找字符序列中最后出现给定字符\的位置
//		c++;
//		string s = c;
//		if (s.size() > 16)
//		{
//			s = s.substr(s.size() - 16, 16); //保留倒数16个字符
//		}
//		s = s + " " + col; //合并string
//		if (m.find(s) == m.end())
//		{
//			m[s] = 1;
//			result.push_back(s);
//		}
//		else {
//			m[s]++;
//		}
//	}
//	int start = 0;
//	if (result.size() > 8)
//		start = result.size() - 8; //输出最后8条string
//	for (int i = start; i < result.size(); ++ i)
//	{
//		cout << result[i] << " " << m[result[i]] << endl;
//	}
//	return 0;
//}

//20.密码验证合格程序：字符串、数组
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	vector<string> result;
//	string s;
//	while (cin >> s)
//	{
//		int lower = 0;
//		int upper = 0;
//		int number = 0;
//		int other = 0;
//		int flag = 0;
//		if (s.size() <= 8)
//		{
//			result.push_back("NG");
//			continue;
//		}
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] >= 48 && s[i] <= 57)
//				number++;
//			else if (s[i] >= 65 && s[i] <= 90)
//				upper++;
//			else if (s[i] >= 97 && s[i] <= 122)
//				lower++;
//			else
//				other++;
//		}
//		if (number != 0) flag++;
//		if (lower != 0) flag++;
//		if (upper != 0) flag++;
//		if (other != 0) flag++;
//		if (flag < 3)
//		{
//			result.push_back("NG");
//			continue;
//		}
//
//		判断是否有长度大于2的string重复
//		bool isfind = false;
//		for (int i = 0; i < s.size() - 2; i++)
//		{
//			string tmp = s.substr(i, 3);
//			if (s.find(tmp, i + 2) != s.npos)
//			{
//				isfind = true;
//				break;
//			}
//		}
//		if (isfind)
//		{
//			result.push_back("NG");
//			continue;
//		}
//		result.push_back("OK");
//	}
//	for (auto i : result)
//	{
//		cout << i << " ";
//	}
//	return 0;
//}

////20.简单密码：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	string result;
//	while (cin >> str)
//	{
//		for (int i = 0; i < str.size(); ++i)
//		{
//            if (str[i] >= 65 && str[i] <= 89)
//                result += str[i] + 33;
//            else if (str[i] == 90)
//                result += str[i] + 32 - 25; //'a'
//            else if (str[i] >= 97 && str[i] <= 99)
//                result += '2';
//            else if (str[i] >= 100 && str[i] <= 102)
//                result += '3';
//            else if (str[i] >= 103 && str[i] <= 105)
//                result += '4';
//            else if (str[i] >= 106 && str[i] <= 108)
//                result += '5';
//            else if (str[i] >= 109 && str[i] <= 111)
//                result += '6';
//            else if (str[i] >= 112 && str[i] <= 115)
//                result += '7';
//            else if (str[i] >= 116 && str[i] <= 118)
//                result += '8';
//            else if (str[i] >= 119 && str[i] <= 122)
//                result += '9';
//            else
//                result += str[i];
//		}
//	}
//    cout << result << endl;
//	return 0;
//}

//21.汽水瓶：数学、模拟
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//    int number;
//    int result = 0;
//    while (cin >> number)
//    {
//        result = 0;//
//        if (number < 2)
//            result = 0;
//        while (number % 3 == 0 && number >= 3)
//        {
//            result += number / 3;
//            number = number / 3;
//        }
//        while (number % 3 != 0 && number >= 3)
//        {
//            result += number / 3;
//            number = (number % 3) + (number / 3);
//        }
//        if (number == 2)
//            result++;
//        cout << result << endl;
//    }
//    return 0;
//}
//int main()
//{
//    int in;
//    vector<int> result;
//    while (cin >> in)
//    {
//        if (in == 0)
//            break;
//        int number = 0;
//        int first = in / 3;
//        int empty = in;
//        while (empty > 1)
//        {
//            if (empty == 2)
//            {
//                number++;
//                break;
//            }
//            number += first;
//            empty -= 2 * first;//
//            first = empty / 3;
//        }
//        result.push_back(number);
//    }
//    for (auto i : result)
//        cout << i << " ";
//    return 0;
//}

////23.删除字符串中出现次数最少的字符：字符串、STL、排序
//#include <iostream>
//#include <vector>
//#include <string>
//#include <map>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string s;
//    vector<string> result;
//    while (cin >> s)
//    {
//        map<char, int> m;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            m[s[i]]++;
//        }
//        vector<int> v;
//        for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
//        {
//            v.push_back(it->second);
//        }
//        sort(v.begin(), v.end());//
//        int min = v[0];
//        string tmp;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (m[s[i]] != min)
//                tmp += s[i];
//        }
//        result.push_back(tmp);
//        m.clear();//
//        v.clear();//
//    }
//    for (auto i : result)
//        cout << i << " ";
//    return 0;
//}

////24.合唱队：动态规划、队列
//#include <iostream>
//using namespace std;
//int main()
//{
//    int num;
//    int left[3000], right[3000], people[3000];
//    while (cin >> num)
//    {
//        for (int i = 0; i < num; ++i)
//        {
//            cin >> people[i];
//            left[i] = 1;
//            for (int j = 0; j < i; ++j)
//            {
//                if (people[i] > people[j])
//                    left[i] = max(left[i], left[j] + 1);//
//            }
//        }
//        for (int i = num - 1; i >= 0; --i)
//        {
//            right[i] = 1;
//            for (int j = num - 1; j >= 0; --j)
//            {
//                if (people[i] > people[j])
//                    right[i] = max(right[i], right[j] + 1);
//            }
//        }
//        int sum = 0;
//        for (int i = 0; i < num; ++i)
//        {
//            if (left[i] + right[i] - 1 > sum)
//                sum = left[i] + right[i] - 1;
//        }
//        cout << num - sum << endl;
//    }
//    return 0;
//}

////25.数据分类处理：排序、STL
//#include <iostream>
//#include <vector>
//#include <string>
//#include <set>
//using namespace std;
//int main()
//{
//    int num_I, num_R;
//    while (cin >> num_I)
//    {
//        vector<string> para_I;
//        set<int> para_R;
//        string s;
//        while (num_I--) { cin >> s; para_I.push_back(s); }
//        cin >> num_R;
//        int a;
//        while (num_R) { cin >> a; para_R.insert(a); }
//        vector<vector<string>> ans(para_R.size());
//        int dex = 0;
//        for (auto i = para_R.begin(); i != para_R.end(); ++i)
//        {
//            int count = 0;
//            for (int j = 0; j < para_I.size(); j++)
//            {
//                int pos = para_I[j].find(to_string(*i));
//                if (pos != para_I[j].npos)
//                {
//                    ans[dex].push_back(to_string(j)); //位置
//                    ans[dex].push_back(para_I[j]); //值
//                    count++;
//                }
//            }
//            if (count != 0)
//            {
//                ans[dex].insert(ans[dex].begin(), to_string(count));
//                ans[dex].insert(ans[dex].begin(), to_string(*i));
//            }
//            dex++;
//        }
//        int sum = 0;
//        for (auto i : ans)
//        {
//            sum += i.size();
//        }
//        cout << to_string(sum) << ' ';
//        for (auto i : ans)
//            for (auto j : i)
//                cout << j << ' ';
//        cout << endl;
//    }
//    return 0;
//}

////26.字符串排序：字符串、排序
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//    string in;
//    while (getline(cin, in))
//    {
//        string temp = in;
//        int a[10000] = { 0 }; 
//        vector<vector<char>> record(100);//       
//        for (int i = 0; i < in.size(); ++i)
//        {
//            if (in[i] >= 'A' && in[i] <= 'Z')
//            {
//                a[i] = 1;
//                record[in[i] - 'A'].push_back(in[i]); // record[0]是存 a或A
//            }
//            else if (in[i] >= 'a' && in[i] <= 'z')
//            {
//                a[i] = 1;
//                record[in[i] - 'a'].push_back(in[i]); //
//            }
//        }
//        int i = 0, j = 0;
//        for (int t = 0; t < in.size(); ++t)
//        {
//            if (a[t] == 1)
//            {
//                while (j == record[i].size())
//                {
//                    i++;//
//                    j = 0;
//                }
//                temp[t] = record[i][j];//对每个字符操作
//                j++;
//            }
//        }
//        cout << temp << endl;
//    }
//    return 0;
//}

////27.查找兄弟单词：查找、STL
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//#include <map>
//using namespace std;
//int main()
//{
//    int num;
//    cin >> num;
//    vector<string> in;
//    while (num--)
//    {
//        string s;
//        cin >> s;
//        in.push_back(s);
//    }
//    string t;
//    cin >> t;
//    int idx;
//    cin >> idx;
//    vector<string> result;
//    for (int p = 0; p < in.size(); ++p)
//    {
//        if (in[p].size() != t.size())
//            continue;
//        if (in[p] == t)
//            continue;
//        map<char, int> m1, m2;//
//        for (int m = 0; m < t.size(); ++m) //统计字符出现次数
//        {
//            m1[in[p][m]]++;
//            m2[t[m]]++;
//        }
//        bool isright = true;
//        for (int m = 0; m < t.size(); ++m)
//        {
//            if (m1[t[m]] != m2[t[m]])
//            {
//                isright = false;
//                break;
//            }
//        }
//        if (isright)
//        {
//            result.push_back(in[p]);
//        }
//    }
//    sort(result.begin(), result.end());
//    if (result.size() != 0)
//    {
//        cout << result.size() << endl;
//        cout << result[idx - 1] << endl;
//    }
//    else {
//        cout << '0' << endl;
//    }
//    return 0;
//}

////28.素数伴侣：匈牙利算法
//#include <iostream>
//#include <vector>
//using namespace std;
//int t[100][100] = { 0 };
//vector<int> modd(100, -1);
//vector<int> meven(100, -1);
//vector<int> visit(100, 0);
//// 判断是否为素数
//bool IsPrimer(int num)
//{
//    for (int i = 2; i * i <= num; ++i)
//    {
//        if (num % i == 0)
//            return false;
//    }
//    return true;
//}
//int dfs(int i)
//{
//    for (int j = 0; j < 100; ++j)
//    {
//        if (t[i][j] == 1 && !visit[j]) //如果是未访问的偶数
//        {
//            visit[j] = 1;
//            if (meven[j] == -1 || dfs(meven[j])) //如果偶数配对了，就让配对它的奇数再去找其他偶数配对
//            {
//                modd[i] = j;
//                meven[j] = i;//
//                return 1;
//            }
//        }
//    }
//    return 0;
//}
//int main()
//{
//    int number;
//    vector<int> even, odd;
//    while (cin >> number)
//    {
//        for (int i = 0; i < number; ++i)
//        {
//            int temp;
//            cin >> temp;
//            if (temp % 2 == 0) //分组
//                odd.push_back(temp);
//            else
//                even.push_back(temp);
//        }
//        for (int i = 0; i < odd.size(); ++i)
//        {
//            for (int j = 0; j < even.size(); ++j)
//            {
//                if (IsPrimer(odd[i] + even[j]))
//                    t[i][j] = 1;
//            }
//        }
//        // 匈牙利算法
//        int res = 0;
//        for (int i = 0; i < odd.size(); ++i)
//        {
//            if (modd[i] == -1)
//            {
//                for (int j = 0; j < visit.size(); ++j)
//                    visit[j] = 0;
//            }
//            res += dfs(i);//
//        }
//        cout << res << endl;
//
//        // 多组输入，清空容器和图
//        even.clear();
//        odd.clear();
//        for (int i = 0; i < 100; ++i)
//            for (int j = 0; j < 100; ++j)
//                t[i][j] = 0;
//        for (int i = 0; i < 100; ++i)
//        {
//            meven[i] = -1;
//            modd[i] = -1;
//        }
//    }
//    return 0;
//}

////29.字符串加解密：字符串
//#include <iostream>
//#include <vector>
//using namespace std;
//string encryption(string s)
//{
//    string result;
//    int size = s.size();
//    for (int i = 0; i < size; ++i)
//    {
//        if (s[i] >= 'A' && s[i] <= 'Y')
//            result += s[i] + 33;
//        else if (s[i] == 'Z')
//            result += s[i] + 33 - 25;
//        else if (s[i] >= 'a' && s[i] <= 'y')
//            result += s[i] - 31;
//        else if (s[i] == 'z')
//            result += s[i] - 31 - 25;
//        else if (s[i] >= '0' && s[i] <= '8')
//            result += s[i] + 1;
//        else if (s[i] == '9')
//            result = s[i] - 8;
//        else
//            result += s[i];
//    }
//    return result;
//}
//string decryption(string s)
//{
//    string result;
//    int size = s.size();
//    for (int i = 0; i < size; ++i)
//    {
//        if (s[i] >= 'A' && s[i] <= 'Y')
//            result += s[i] + 31;
//        else if (s[i] == 'Z')
//            result += s[i] + 31 - 25;
//        else if (s[i] >= 'a' && s[i] <= 'y')
//            result += s[i] - 33;
//        else if (s[i] == 'z')
//            result += s[i] - 33 - 25;
//        else if (s[i] >= '0' && s[i] <= '8')
//            result += s[i] + 1;
//        else if (s[i] == '9')
//            result = s[i] - 8;
//        else
//            result += s[i];
//    }
//    return result;
//}
//int main()
//{
//    string p1, p2;
//    while (cin >> p1 >> p2)
//    {
//        string r1 = encryption(p1);
//        string r2 = decryption(p2);
//        cout << r1 << endl << r2 << endl;
//    }
//    return 0;
//}

////30.字符串合并处理：字符串、排序、位运算、串流
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string>
//#include <sstream>//
//#include <bitset>//
//#include <cctype>//
//using namespace std;
////计算bit数据的16进制数值，再转化为字符类型
//char bitToHex(string s)
//{
//    int t = (s[0] * 1 - 48) * 8 + (s[1] * 1 - 48) * 4 + (s[2] * 1 - 48) * 2 + (s[3] * 1 - 48) * 1; //0是从48开始的
//    char ch = ' ';
//    switch (t)
//    {
//    case 10:
//        ch = 'A';
//        break;
//    case 11:
//        ch = 'B';
//        break;
//    case 12:
//        ch = 'C';
//        break;
//    case 13:
//        ch = 'D';
//        break;
//    case 14:
//        ch = 'E';
//        break;
//    case 15:
//        ch = 'F';
//        break;
//    default:
//        ch = char(t + 48); //0-9
//    }
//    return ch;
//}
//int main()
//{
//    string s1, s2;
//    vector<string> result;
//    while (cin >> s1 >> s2)
//    {
//        string s = s1 + s2;
//        vector<char> odd;
//        vector<char> even;
//        int size = s.size();
//        for (int i = 0; i < size; ++i)
//        {
//            if (i % 2 == 0)
//                even.push_back(s[i]);
//            else
//                odd.push_back(s[i]);
//        }
//        sort(even.begin(), even.end());
//        sort(odd.begin(), odd.end());
//        string ns;
//        int eveni = 0;
//        int oddi = 0;
//        for (int i = 0; i < size; ++i)
//        {
//            if (i % 2 == 0)
//            {
//                ns += even[eveni];
//                eveni++;
//            }
//            else {
//                ns += odd[oddi];
//                oddi++;
//            }
//        }
//        string results;
//        string num = "0123456789ABCDEF";
//        for (int i = 0; i < size; ++i)
//        {
//            if (isdigit(ns[i]) || (ns[i] >= 'A' && ns[i] <= 'F') || (ns[i] >= 'a' && ns[i] <= 'f'))
//            {
//                stringstream ss;
//                ss << bitset<4>(num.find(toupper(ns[i]))); //转化大写字母为4bit
//                string s = ss.str();
//                reverse(s.begin(), s.end());
//                results += bitToHex(s);
//            }
//            else
//            {
//                results += ns[i];
//            }
//        }
//        result.push_back(results);
//        s1.clear();
//        s2.clear();
//    }
//    for (auto i : result)
//        cout << i << endl;
//    return 0;
//}

////31.单词倒排：字符串、排序、STL
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//    string s;
//    vector<string> v;
//    getline(cin, s);
//    for (int i = 0; i < s.size(); ++i)
//    {
//        string temp;
//        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
//            temp += s[i];
//        else 
//            if (!s.empty())
//            {
//                v.push_back(temp);
//                temp.clear();
//            }
//    }
//    for (int i = v.size() - 1; i >= 0; --i)
//        cout << v[i] << " ";
//    return 0;
//}

////32.密码截取：字符串、STL、回文
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string str;
//    vector<int> result;
//    while (cin >> str)
//    {
//        int maxn = 1, flag = 0;
//        for (int i = 0; i < str.length(); ++i)
//            for (int j = str.length() - 1; j > i; --j)
//            {
//                flag = 0;
//                int l, r;
//                for (l = i, r = j; l <= (j + i) / 2; l++, r--)
//                {
//                    if (str[l] != str[r])
//                    {
//                        flag = 1;
//                        break;
//                    }
//                }
//                if (flag == 0) //若该长段为回文，则此级遍历进行下去也只能找到更短的回文，为提速可直接跳出循环
//                {
//                    maxn = max(maxn, (j - i + 1));
//                    break;
//                }
//            }
//        result.push_back(maxn);
//    }
//    for (auto i : result)
//        cout << i << endl;
//    return 0;
//}

////33.整数与IP地址间的转换：字符串、位运算、串流
//#include <iostream>
//#include <vector>
//#include <bitset>
//#include <sstream>
//using namespace std;
//long iptonum(string s)
//{
//    vector<int> nums;
//    istringstream in(s);//放入字符串流
//    int number;
//    while (in >> number)
//    {
//        nums.push_back(number);
//    }
//    string str;
//    for (auto i : nums)
//    {
//        bitset<8> temp(i);//int转8bit
//        str += temp.to_string();//连接8bit字符串
//    }
//    bitset<32> result(str);//string转32bit
//    long ip = result.to_ulong();//32bit转ulong
//    return ip;
//}
//string numtoip(long n)
//{
//    bitset<32> in(n);//ulong转32bit
//    string str = in.to_string();//32bit转string
//    vector<int> nums;
//    for (int i = 0; i < 4; ++i)
//    {
//        bitset<8> temp(str.substr(i * 8, 8));
//        nums.push_back(temp.to_ullong());//存入每8bit的整数值
//    }
//    string snum;
//    for (auto i : nums)
//    {
//        snum += '.' + to_string(i);//
//    }
//    return snum.substr(1);//排除第一个'.'
//}
//int main()
//{
//    string str;
//    long num;
//    while (cin >> str >> num)
//    {
//        for (auto& i : str)//
//        {
//            if (i == '.')
//                i = ' ';
//        }
//        long r1 = iptonum(str);
//        string r2 = numtoip(num);
//        cout << r1 << endl << r2 << endl;
//    }
//    return 0;
//}

////34.图片整理：字符串、STL
//#include <iostream>
//#include <map> //map会自动排序
//using namespace std;
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        map<char, int> m;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            m[str[i]]++;
//        }
//        for (auto i = m.begin(); i != m.end(); ++i)
//        {
//            for (int j = 0; j < i->second; ++j)
//                cout << i->first;
//        }
//        cout << endl;
//    }
//    return 0;
//}

////35.蛇形矩阵：数学、数组
//#include <iostream>
//using namespace std;
//int main()
//{
//    int n;
//    while (cin >> n)
//    {
//        //构造二维矩阵
//        int** a = new int* [n];//
//        for (int i = 0; i < n; ++i)
//        {
//            a[i] = new int[n];//
//        }
//        int start = 1;
//        for (int i = 0; i < n; ++i)
//        {
//            int k = i;
//            for (int j = 0; j <= i; ++j)
//            {
//                a[k][j] = start;
//                start++;
//                k--;
//            }
//        }
//        for (int i = 0; i < n; ++i)
//        {
//            for (int j = 0; j < n; ++j)
//            {
//                if (a[i][j] != 0)
//                    cout << a[i][j] << " ";
//            }
//            cout << endl;
//        }
//    }
//    return 0;
//}

////36.字符串加密：字符串、密码学
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string word, input;
//    while (cin >> word >> input)
//    {
//        char* alpha = new char[26];
//        int start = 0;
//        int len = word.length();
//        for (int i = 0; i < len; i++)
//        {
//            word[i] = tolower(word[i]);//字母最小化
//            if (word.find(word[i]) == i)//字母去重
//            {
//                alpha[start] = word[i];
//                start++;
//            }
//        }
//        for (char t = 'a'; t <= 'z'; ++t)
//        {
//            if (word.find(t) == string::npos)
//            {
//                alpha[start] = t;
//                start++;
//            }
//        }
//        for (int i = 0; i < input.length(); ++i)
//        {
//            if (input[i] >= 'a' && input[i] <= 'z')
//                cout << alpha[input[i] - 'a'];
//            else if (input[i] >= 'A' && input[i] <= 'Z')
//                cout << (char)(toupper(alpha[input[i] - 'A']));
//            else
//                cout << input[i];
//        }
//        cout << endl;
//    }
//    return 0;
//}

////37.统计每个月兔子的总数：查找、排序、斐波那契数列、递归
//#include <iostream>
//using namespace std;
//int getnum(int month)
//{
//    if (month == 1 || month == 2)//
//        return 1;
//    else
//        return getnum(month - 1) + getnum(month - 2);//
//}
//int main()
//{
//    int month;
//    while (cin >> month)
//    {
//        cout << getnum(month) << endl;
//    }
//    return 0;
//}

////38.求小球落地5次后所经历的路程和第5次反弹的高度：模拟、思维、数学
//#include <iostream>
//using namespace std;
//int main()
//{
//    int height;
//    while (cin >> height)
//    {
//        double sum = 0;
//        double temp = static_cast<double>(height);
//        sum += temp;
//        for (int i = 1; i < 5; ++i)
//        {
//            sum += temp;
//            temp /= 2;
//        }
//        cout << sum << ' ' << temp / 2 << endl;
//    }
//    return 0;
//}

////39.判断两个IP是否属于同一子网：字符串、模拟、位运算、串流、STL
//#include <iostream>
//#include <bitset>
//#include <string>
//#include <vector>
//#include <sstream>
//using namespace std;
//bool ipToNum(string &ip, unsigned int &num, bool isMask)
//{
//    for (auto &c : ip)//
//    {
//        if (c == '.')
//            c = ' ';
//    }
//    stringstream ss(ip);
//    vector<int> ips;////
//    unsigned int n = 0;
//    while (ss >> n)////
//    {
//        ips.push_back(n);
//    }
//    if (ips.size() != 4)
//        return false;
//    for (auto i : ips)
//    {
//        if (i < 0 || i > 255)
//            return false;
//    }
//    num = ips[0] << 24 | ips[1] << 16 | ips[2] << 8 | ips[3] << 0;//组合成32为无符号数
//    if (isMask)
//    {
//        bitset<32> t(num);
//        string st = t.to_string();
//        bool isZero = false;
//        for (int i = 0; i < st.length(); ++i)
//        {
//            if (isZero)
//                if (st[i] == '1')
//                    return false;
//            if (st[i] == '0')
//                isZero = true;
//        }
//
//    }
//    return true;
//}
//int main()
//{
//    string mask, ip1, ip2;
//    while (cin >> mask >> ip1 >> ip2)
//    {
//        unsigned int num1, num2, masknum;
//        if (ipToNum(mask,masknum,true) && ipToNum(ip1, num1, false) && ipToNum(ip2, num2, false))
//        {
//            if ((num1 & masknum) == (num2 & masknum))
//            {
//                cout << "0" << endl;
//            }
//            else
//            {
//                cout << "2" << endl;
//            }
//        }
//        else
//        {
//            cout << "1" << endl;
//        }
//    }
//    return 0;
//}

////40.统计字符：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        int letter = 0;
//        int space = 0;
//        int number = 0;
//        int other = 0;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
//            {
//                letter++;
//            }
//            else if (str[i] == ' ')
//            {
//                space++;
//            }
//            else if (str[i] >= '0' && str[i] <= '9')
//            {
//                number++;
//            }
//            else
//                other++;
//        }
//        cout << letter << ' ' << space << ' ' << number << ' ' << other << endl;
//    }
//    return 0;
//}

////41.称砝码：深度优先遍历DFS、字符串、STL
//#include <iostream>
//#include <string>
//#include <unordered_set>
//using namespace std;
//int num;
//int a[11];//每个砝码的重量
//int b[11];//每个砝码的数量
//void getWeight(int n, int w, unordered_set<int> &us)
//{
//    if (n >= num)
//        return;
//    for (int i = 0; i <= b[n]; ++i) //从b[0]开始
//    {
//        w += a[w] * i;
//        us.insert(w);
//        getWeight(n + 1, w, us);
//        w -= a[n] * i;
//    }
//    return;
//}
//int main()
//{
//    while (cin >> num)
//    {
//        for (int i = 0; i < num; ++i)
//        {
//            cin >> a[i];
//        }
//        for (int i = 0; i < num; ++i)
//        {
//            cin >> b[i];
//        }
//        unordered_set<int> weight;
//        getWeight(0, 0, weight);
//        cout << weight.size() << endl;
//    }
//    return 0;
//}

////42.学英语：字符串、字典、STL、思维
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//vector<string> T19 = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight",\
//                       "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",\
//                        "sixteen", "seventeen", "eighteen", "ninteen" };
//vector<string> Tenmul = { "none", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };
//string English(long num)
//{
//    if (num >= 0 && num <= 19)
//    {
//        return T19[num];
//    }
//    if (num >= 20 && num <= 99)
//    {
//        if (num % 10 == 0)
//        {
//            return Tenmul[num];
//        }
//        return Tenmul[num / 10] + " " + T19[num % 10];
//    }
//    if (num >= 100 && num < 999)
//    {
//        if (num % 100 == 0)
//        {
//            return T19[num / 100] + " hundred";
//        }
//        return T19[num / 100] + " hundred and " + English(num % 100);
//    }
//    if (num >= 1000 && num <= 999999)
//    {
//        if (num % 1000 == 0)
//        {
//            return English(num / 1000) + " thousand";
//        }
//        return English(num / 1000) + " thousand " + English(num % 1000);
//    }
//    if (num >= 1000000 && num <= 999999999)
//    {
//        if (num % 1000000 == 0)
//        {
//            return English(num / 1000000) + " million";
//        }
//        return English(num / 1000000) + " million " + English(num % 1000000 / 1000) + " thousand " + English(num % 1000);
//    }
//    return "error";
//}
//int main()
//{
//    long num;
//    while (cin >> num)
//    {
//        cout << English(num) << endl;
//    }
//    return 0;
//}

////43.迷宫问题：回溯法、深度优先遍历DFS、STL
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//struct list
//{
//    int x, y;
//    struct list* next;
//};
//typedef struct list node;//
//typedef node* link;//
//link push(link path, int x, int y);
//link pop(link path, int* x, int* y);
//int checkExit(int x, int y, int ex, int ey);
//link push(link path, int x, int y)
//{
//    link newnode;
//    newnode = new node;
//    if (!newnode)
//    {
//        cout << "Error:内存分配失败！" << endl;
//        return NULL;
//    }
//    newnode->x = x;
//    newnode->y = y;
//    newnode->next = path;//
//    path = newnode;
//    return path;
//}
//link pop(link path, int* x, int* y)
//{
//    link top;
//    if (path != NULL)
//    {
//        link temp = path;
//        path = path->next;//
//        *x = path->x;
//        *y = path->y;
//        delete temp;
//        return path;
//    }
//    return path;
//}
////到达终点
//int checkExit(int x, int y, int ex, int ey)
//{
//    if ((x == ex) && (y == ey))
//    {
//        return 1;
//    }
//    return 0;
//}
//int main()
//{
//    int row, col;
//    while (cin >> row >> col)
//    {
//        int** a = new int* [row];//
//        for (int i = 0; i < row; ++i)//
//        {
//            a[i] = new int[col];//
//        }
//        for (int i = 0; i < row; ++i)
//        {
//            for (int j = 0; j < col; ++j)
//            {
//                cin >> a[i][j];
//            }
//        }
//        link path = NULL;
//        int x = 0, y = 0;
//        path = push(path, x, y);
//        while (x < row && y < col)
//        {
//            a[x][y] = 2;
//            //往上走
//            if (x - 1 >= 0)
//            {
//                if (a[x - 1][y] == 0)
//                {
//                    x -= 1;
//                    path = push(path, x, y);
//                    continue;
//                }
//            }
//            //往下走
//            if (x + 1 < row)
//            {
//                if (a[x + 1][y] == 0)
//                {
//                    x += 1;
//                    path = push(path, x, y);
//                    continue;
//                }
//            }
//            //往左走
//            if (y - 1 >= 0)
//            {
//                if (a[x][y - 1] == 0)
//                {
//                    y -= 1;
//                    path = push(path, x, y);
//                    continue;
//                }
//            }
//            //往右走
//            if (y + 1 < col)
//            {
//                if (a[x][y + 1] == 0)
//                {
//                    y += 1;
//                    path = push(path, x, y);
//                    continue;
//                }
//            }
//            //判断是否到达终点
//            if (checkExit(x, y, row - 1, col -1) == 1)
//            {
//                break;
//            }
//            //倒退
//            path = pop(path, &x, &y);
//        }
//        vector<string> result;
//        while (path != NULL)
//        {
//            string p = "(" + to_string(path->x) + "," + to_string(path->y) + ")";
//            result.push_back(p);
//            path = path->next;//
//        }
//        for (int i = result.size() - 1; i >= 0; --i)
//        {
//            cout << result[i] << endl;
//        }
//    }
//    return 0;
//}

////44.Sudoku数独：思维、数学、搜索、深度优先遍历DFS
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//bool ValidExist(vector<vector<int>> sudoku, int row, int col, int m)
//{
//    //判断所在行
//    for (int k = 0; k < 9; k++)
//    {
//        if (sudoku[row][k] == m)
//            return false;
//    }
//    //判断所在列
//    for (int k = 0; k < 9; k++)
//    {
//        if (sudoku[k][col] == m)
//            return false;
//    }
//    //判断所在3*3方阵
//    int Lrow = row / 3 * 3;
//    int Lcol = col / 3 * 3;
//    for (int row = Lrow; row < Lrow + 3; ++row)
//        for (int col = Lcol; col < Lcol + 3; ++col)
//        {
//            if (sudoku[row][col] == m)
//                return false;
//        }
//    return true;
//}
//bool find(vector<vector<int>> sudoku, int &row, int &col)
//{
//    int i, j;
//    while (row < 9 && col < 9)
//    {
//        if (sudoku[row][col] == 0)
//            return true;
//        else
//        {
//            col++;
//            if (col == 9)
//            {
//                col = 0;
//                row++;
//            }
//        }
//    }
//    return false;
//}
//bool DFS(vector<vector<int>> &sudoku, int row, int col)
//{
//    bool flag = false;
//    if (col > 8)
//    {
//        col %= 9;
//        row++;
//    }
//    //如果没有0点了，则表示完成了填充
//    if (!find(sudoku, row, col))
//        return true;
//    //从1开始赋值，若填写某个数值后，其他0点位置无法找到合适值，则数值递进再次尝试
//    for (int m = 1; m <= 9; m++)
//    {
//        if (ValidExist(sudoku, row, col, m))
//        {
//            sudoku[row][col] = m;
//            flag = DFS(sudoku, row, col + 1);//
//            if (flag == false)//
//                continue;
//            else
//                return true;
//        }
//    }
//    //若没有合适值，将当前位置置0，返回false，使上个填充数据再变换其他数值尝试
//    if (flag == false)
//    {
//        sudoku[row][col] = 0;
//        return false;
//    }
//}
//int main()
//{
//    vector<vector<int>> sudoku(9, vector<int>(9, 0));
//    for (int i = 0; i < 9; ++i)
//        for (int j = 0; j < 9; ++j)
//            cin >> sudoku[i][j];
//    DFS(sudoku, 0, 0);//
//    for (int i = 0; i < 9; ++i)
//    {
//        for (int j = 0; j < 9; ++j)
//            cout << sudoku[i][j] << " ";
//        cout << endl;
//    }
//    return 0;
//}

////45.名字的漂亮度：字符串、排序、STL
//#include <iostream>
//#include <vector>
//#include <string>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		string name;
//		vector<int> results;
//		while (num--)
//		{
//			cin >> name;
//			int sum = 0;
//			int alpha[26] = { 0 };
//			for (int i = 0; i < name.size(); i++)
//			{
//				if (name[i] >= 'a' && name[i] <= 'z')
//				{
//					alpha[name[i] - 'a']++;//
//				}
//				else
//					alpha[name[i] - 'A']++;//
//			}
//			sort(alpha, alpha + 26);////
//			int k = 26;
//			for (int i = 25; i >= 0; --i)
//			{
//				sum += alpha[i] * k;
//				k--;
//			}
//			results.push_back(sum);
//		}
//		for (auto it = results.begin(); it != results.end(); it++)
//		{
//			cout << *it << endl;
//		}
//	}
//	return 0;
//}

////46.截取字符串：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string s;
//	int n;
//	while (cin >> s >> n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			cout << s[i];
//		}
//		cout << endl;
//	}
//	return 0;
//}

////48.从单向链表中删除指定值的节点：静态链表
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, head;
//	int a[10000];
//	while (cin >> n >> head)
//	{
//		fill(a, a + 10000, -1);
//		a[0] = head;
//		for (int i = 0; i < n; ++i)
//		{
//			int cur, pre;
//			cin >> cur >> pre;
//			int t = a[pre];//插入
//			a[pre] = cur;
//			a[cur] = t;
//		}
//		int del;
//		cin >> del;
//		int pHead = 0;//头结点
//		int pcur = pHead;
//		while (pcur != -1)
//		{
//			int t = a[pcur];
//			if (t == del)//删除
//				a[pcur] = a[t];
//			else
//				pcur = a[pcur];
//		}
//		//遍历输出
//		pcur = pHead;
//		while (a[pcur] != -1)
//		{
//			cout << a[pcur] << " ";
//			pcur = a[pcur];
//		}
//		cout << endl;
//	}
//	return 0;
//}

////49.多线程：多线程、锁
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <string>
//using namespace std;
//string s;
//mutex m;
//bool finish = false; //控制运行情况
//void thread1(int num)
//{
//	while (num)
//	{
//		if (m.try_lock())
//		{
//			int len = static_cast<int>(s.length());
//			if (len % 4 == 0)
//			{
//				s += 'A';
//				num--;
//			}
//			m.unlock();
//		}
//	}
//	finish = true;//
//}
//void thread2()
//{
//	while (1)
//	{
//		if (m.try_lock())
//		{
//			int len = static_cast<int>(s.length());
//			if (finish && len % 4 == 0)
//			{
//				m.unlock();
//				return;
//			}
//			if (len % 4 == 1)
//			{
//				s += 'B';
//			}
//			m.unlock();
//		}
//	}
//}
//void thread3()
//{
//	while (1)
//	{
//		if (m.try_lock())
//		{
//			int len = static_cast<int>(s.length());
//			if (finish && len % 4 == 0)//finish为true时线程无操作
//			{
//				m.unlock();
//				return;
//			}
//			if (len % 4 == 2)
//			{
//				s += 'C';
//			}
//			m.unlock();
//		}
//	}
//}
//void thread4()
//{
//	while (1)
//	{
//		if (m.try_lock())
//		{
//			int len = static_cast<int>(s.length());
//			if (finish && len % 4 == 0)
//			{
//				m.unlock();
//				return;
//			}
//			if (len % 4 == 3)
//			{
//				s += 'D';
//			}
//			m.unlock();
//		}
//	}
//}
//int main()
//{
//	int in;
//	while (cin >> in)
//	{
//		thread t1(thread1, in);
//		thread t2(thread2);
//		thread t3(thread3);
//		thread t4(thread4);
//		t1.join();
//		t2.join();
//		t3.join();
//		t4.join();
//		cout << s << endl;
//		s.clear();
//		finish = false;
//	}
//	return 0;
//}

////50.四则运算：字符串、数学、栈
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int Calculation(string expr, int start, int end)
//{
//	if ((expr[start] == '(' || expr[start] == '[' || expr[start] == '{') && 
//		(expr[end - 1] == ')' || expr[end - 1] == ']' || expr[end - 1] == '}'))
//	{
//		vector<int> vec;
//		for (int i = start; i < end - 1; ++i)
//		{
//			if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
//				vec.push_back(i);
//			else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
//				vec.pop_back();
//		}
//		if (vec.back() == start)
//		{
//			++start;
//			--end;
//		}
//	}
//	int layer = 0, am = 0, md = 0;
//	bool flag = false; //判断是否有内置括号
//	//
//	for (int i = start; i < end; ++i)
//	{
//		if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{')
//		{
//			++layer;
//			flag = true;
//		}
//		else if (expr[i] == ')' || expr[i] == ']' || expr[i] == '}')
//		{
//			--layer;
//			flag = true;
//		}
//		else if ((expr[i] == '+' || expr[i] == '-') && !layer)
//			am = i;
//		else if ((expr[i] == '*' || expr[i] == '/') && !layer)
//			md = i;
//	}
//	if (am > start)
//	{
//		if (expr[am] == '+')
//			return Calculation(expr, start, am) + Calculation(expr, am + 1, end);
//		else
//			return Calculation(expr, start, am) - Calculation(expr, am + 1, end);
//	}
//	else if (md > start)
//	{
//		if (expr[md] == '*')
//			return Calculation(expr, start, end) * Calculation(expr, md + 1, end);
//		else
//			return Calculation(expr, start, end) / Calculation(expr, md + 1, end);
//	}
//	else if (flag)
//	{
//		return Calculation(expr, start + 1, end - 1);
//	}
//	else
//		return stoi(expr.substr(start, end - start));
//}
//int main()
//{
//	string str;
//	while (cin >> str)
//	{
//		cout << Calculation(str, 0, str.size()) << endl;
//	}
//	return 0;
//}

////51.输出单向链表中倒数第k个结点：链表、查找
//#include <iostream>
//#include <string>
//using namespace std;
//struct ListNode
//{
//	int m_nKey;
//	ListNode* m_pNext;
//	ListNode(int x) : m_nKey(x), m_pNext(nullptr) {};
//};
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		ListNode* head = new ListNode(-1);
//		ListNode* p = head;
//		for (int i = 0; i < num; ++i)
//		{
//			int t;
//			cin >> t;
//			ListNode* tp = new ListNode(t);
//			tp->m_pNext = nullptr;
//			p->m_pNext = tp;
//			p = tp;
//		}
//		int target;
//		cin >> target;
//		if (target <= 0 || target > num)
//		{
//			cout << 0 << endl;
//			continue;
//		}
//		for (int i = 0; i < num - target + 1; ++i)
//			head = head->m_pNext;
//		cout << head->m_nKey << endl;
//	}
//	return 0;
//}

////52.计算字符串的距离：动态规划、字符串、图
//#include <iostream>
//#include <string>
//using namespace std;
//int getMin(int a, int b, int c)
//{
//	a = min(a, b);
//	b = min(b, c);
//	return min(a, b);
//}
//int Levenshiein(string a, string b)
//{
//	a.insert(0, 1, ' ');//开头创建空格，建立二分图
//	b.insert(0, 1, ' ');
//	int n = a.size();
//	int m = b.size();
//	int k;
//	//int L[n][m];//不能用非常量定义数组
//	int** L = new int* [n];//
//	for (int i = 0; i < n; ++i)//
//	{
//		L[i] = new int[m];
//	}
//	for (int i = 0; i < n; ++i)
//		L[i][0] = i;
//	for (int i = 0; i < m; ++i)
//		L[0][i] = i;
//	for (int i = 1; i < n; ++i)//从1，1开始动态计算
//		for (int j = 1; j < m; ++j)
//		{
//			if (a[i] == b[j])
//				k = 0;
//			else
//				k = 1;
//			L[i][j] = getMin(L[i][j - 1] + 1, L[i - 1][j] + 1, L[i - 1][j - 1] + k);//3种情况
//		}
//	return L[n - 1][m - 1];//
//}
//int main()
//{
//	string a, b;
//	while (cin >> a >> b)
//	{
//		cout << Levenshiein(a, b) << endl;
//	}
//	return 0;
//}

////53.杨辉三角的变形：数学、字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int row = num;
//		int col = 2 * num - 1;
//		int** L = new int* [row];
//		for (int i = 0; i < row; ++i)
//		{
//			L[i] = new int[col];
//		}
//		for (int j = 0; j < col; ++j)
//		{
//			L[0][j] = 0;
//		}
//		L[0][row - 1] = 1;
//		//计算杨辉三角的每个元素大小
//		for (int i = 0; i < row; ++i)
//		{
//			for (int j = 1; j < col - 1; ++j)
//			{
//				L[i][j] = L[i - 1][j - 1] + L[i - 1][j] + L[i - 1][j + 1];
//			}
//			L[i][0] = L[i - 1][0] + L[i - 1][1];
//			L[i][col - 1] = L[i - 1][col - 1] + L[i - 1][col - 2];
//		}
//		bool getresult = false;
//		for (int j = 0; j < col; ++j)
//		{
//			if (L[row - 1][j] % 2 == 0)
//			{
//				cout << j + 1 << endl;
//				getresult = true;
//				break;//
//			}
//		}
//		if (!getresult)//
//			cout << "-1" << endl;
//	}
//	return 0;
//}

////53.表达式求值：字符串、数学、栈
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//vector<char> sheet = { '+','-','*','/','(',')','0','1','2','3','4','5','6','7','8','9' };
//bool check(string s)
//{
//	int left = 0;
//	int right = 0;
//	for (int i = 0; i < s.size(); ++i)
//	{
//		bool isok = false;
//		for (int j = 0; j < sheet.size(); ++j)
//		{
//			if (s[i] == '(')
//				left++;
//			if (s[i] == ')')
//				right++;
//			if (s[i] == sheet[j])
//				isok = true;
//		}
//		if (!isok)
//			return false;
//	}
//	if (left != right)//左右括号数不相等
//		return false;
//	return true;
//}
//int calculate(string &s, int start, int end)
//{
//	if (s[start] == '(' && s[end - 1] == ')')
//	{
//		start++;
//		end--;
//	}
//	int layer = 0, am = 0, md = 0;
//	bool flag = false;
//	for (int i = start; i < end; ++i)
//	{
//		if (s[i] == '(')
//		{
//			++layer;
//			flag = true;
//		}
//		if (s[i] == ')')
//		{
//			--layer;
//			flag = true;
//		}
//		else if (s[i] == '+' || s[i] == '-')
//			am = i;
//		else if (s[i] == '*' || s[i] == '/')
//			md = i;
//	}
//	if (am > start)
//	{
//		if (s[am] == '+')
//			return calculate(s, start, am) + calculate(s, am + 1, end);
//		else
//			return calculate(s, start, am) - calculate(s, am + 1, end);
//	}
//	if (md > start)
//	{
//		if (s[md] == '*')
//			return calculate(s, start, md) * calculate(s, md, end);
//		else
//			return calculate(s, start, md) / calculate(s, md, end);
//	}
//	else if (flag)
//		return calculate(s, start + 1, end - 1);
//	else
//		return stoi(s.substr(start, end - start));//
//}
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		if (!check(s))
//			cout << -1 << endl;
//		else
//			cout << calculate(s, 0, s.size()) << endl;
//	}
//	return 0;
//}

////55.挑7：数学、穷举
//#include <iostream>
//#include <string>
//using namespace std;
//int statistic(int n)
//{
//	int result = 0;
//	for (int i = 7; i <= n; ++i)
//	{
//		int tmp = i;
//		if (i % 7 == 0)
//			result++;
//		else
//		{
//			while (tmp != 0)
//			{
//				if (tmp % 10 == 7)
//				{
//					result++;
//					break;
//				}
//				tmp /= 10;
//			}
//		}
//	}
//	return result;
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		cout << statistic(num) << endl;
//	}
//	return 0;
//}

////56.完全数计算：数学、提速、数组
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int a[500000] = { 0 };
//bool isPerfect(int n)
//{
//	vector<int> result;
//	result.push_back(1);
//	//计算n的所有因子
//	for (int i = 2; i <= n / 2; ++i)
//	{
//		if (n % i == 0)
//			result.push_back(i);
//	}
//	int sum = 0;
//	for (int it = 0; it < result.size(); ++it)
//		sum += result[it];
//	if (sum == n)
//	{
//		a[n] = a[n - 1] + 1;//增加一个完美数
//		return true;
//	}
//	else
//	{
//		a[n] = a[n - 1];//完美数个数不变
//	}
//	return false;
//}
//int statistic(int n)
//{
//	if (a[n] != 0)
//		return a[n];
//	int size = 0;
//	for (int i = 6; i < n; ++i)
//	{
//		if (isPerfect(i))
//			size++;
//	}
//	return size;
//}
//int main()
//{
//	int number;
//	while (cin >> number)
//	{
//		cout << statistic(number) << endl;
//	}
//	return 0;
//}

////57.高精度整数加法：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//string add(string s1, string s2)
//{
//	string result, Long, Short;
//	if (s1.size() > s2.size())
//	{
//		Long = s1;
//		Short = s2;
//	}
//	else
//	{
//		Long = s2;
//		Short = s1;
//	}
//	int j = Short.size() - 1;
//	bool carry = false; //进位符
//	for (int i = Long.size() - 1; i >= 0; --i)
//	{
//		//加法阶段
//		if (j >= 0)
//		{
//			int temp;
//			if (carry)
//			{
//				temp = int(Long[i] - '0') + int(Short[j] - '0') + 1;
//			}
//			else {
//				temp = int(Long[i] - '0') + int(Short[j] - '0');
//			}
//			if (temp < 10)
//			{
//				result = char(temp + '0') + result;
//				carry = false;
//			}
//			else {
//				carry = true;
//				temp -= 10;
//				result = char(temp + '0') + result;
//			}
//		}
//		//进位阶段
//		else if (carry)
//		{
//			int temp = int(Long[i] - '0') + 1;
//			if (temp < 10)
//			{
//				result = char(temp + '0') + result;
//				carry = false;
//			}
//			else {
//				carry = true;
//				temp -= 10;
//				result = char(temp + '0') + result;
//			}
//		}
//		else {
//			result = char(Long[i]) + result;
//		}
//		--j;//
//	}
//	// 判断最后结果是否有进位
//	if (carry)
//	{
//		result = "1" + result;
//	}
//	return result;
//}
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		cout << add(s1, s2) << endl;
//	}
//	return 0;
//}

////58.输入n个整数，输出其中最小的k个：数组、需求分析、排序
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//	int n, k;
//	while (cin >> n >> k)
//	{
//		vector<int> v;
//		for (int i = 0; i < n; ++i)
//		{
//			int a;
//			cin >> a;
//			v.push_back(a);
//		}
//		sort(v.begin(), v.end());
//		for (int j = 0; j < k; j++)
//		{
//			cout << v[j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

////59.找出字符串中第一个只出现一次的字符：字符串、STL
//#include <iostream>
//#include <string>
//#include <map>
//using namespace std;
//int main()
//{
//	string s;
//	while (cin >> s)
//	{
//		map<char, int> m;
//		bool isFind = false;
//		for (int i = 0; i < s.size(); ++i)
//		{
//			m[s[i]]++;
//		}
//		for (auto t = m.begin(); t != m.end(); ++t)
//		{
//			if (t->second == 1)
//			{
//				cout << t->first << endl;
//				isFind = true;
//			}
//		}
//		if (!isFind)
//			cout << "-1" << endl;
//	}
//	return 0;
//}

////60.查找组成一个偶数最接近的两个素数：查找、数学、穷举
//#include <iostream>
//#include <vector>
//using namespace std;
//bool isPrime(int n)
//{
//	for (int i = 2; i < n; ++i)
//	{
//		if (n % i == 0)
//			return false;
//	}
//	return true;
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		vector<int> primes;
//		for (int i = 2; i < num; ++i)
//		{
//			if (isPrime(i))
//				primes.push_back(i);
//		}
//		pair<int, int> result;//
//		int min = 9999;
//		for (int i = 0; i < primes.size(); ++i)
//			for (int j = i; j < primes.size(); ++j)
//			{
//				if ((primes[i] + primes[j] == num) && (primes[j] - primes[i] < min))
//				{
//					result.first = i;
//					result.second = j;
//					min = primes[j] - primes[i];
//				}
//			}
//		cout << primes[result.first] << endl;
//		cout << primes[result.second] << endl;
//	}
//	return 0;
//}

////61.放苹果：递归、动态规划
//#include <iostream>
//#include <vector>
//using namespace std;
//int func(int a, int d)
//{
//	if (a <= 0 || d <= 0)
//		return 0;
//	else if (a == 1 || d == 1)
//		return 1;
//	else if (a == d)
//		return func(a, d - 1) + func(a - d, d) + 1;//
//	else
//		return func(a, d - 1) + func(a - d, d);//
//}
//int main()
//{
//	int apples, dishes;
//	while (cin >> apples >> dishes)
//	{
//		int result = func(apples, dishes);
//		cout << result << endl;
//	}
//	return 0;
//}

////62.查找输入整数二进制中1的个数：位运算
//#include <iostream>
//using namespace std;
//int CountOne(int num)
//{
//	int cnt = 0;
//	while (num)
//	{
//		if (num % 2 == 1)
//			cnt++;
//		num >>= 1;
//	}
//	return cnt;
//}
//int main()
//{
//	int number;
//	while (cin >> number)
//	{
//		cout << CountOne(number) << endl;
//	}
//	return 0;
//}

////63.DNA序列：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	int length;
//	while (cin >> str >> length)
//	{
//		int size = str.size();
//		float max = 0.f;//
//		string result;
//		for (int i = 0; i < size - length + 1; ++i)//
//		{
//			string t = str.substr(i, length);//
//			float sum = 0.f;
//			for (int j = 0; j < t.size(); ++j)
//			{
//				if (t[j] == 'G' || t[j] == 'C')
//					sum++;
//			}
//			float R = float(sum / t.size());
//			if (R > max)
//			{
//				max = R;
//				result = t;
//			}
//		}
//		cout << result << endl;
//	}
//	return 0;
//}

////64.MP3光标位置：数组、思维
//#include <iostream>
//#include <vector>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		string op;
//		cin >> op;
//		vector<int> list(num);
//		for (int i = 0; i < num; ++i)
//			list[i] = i + 1;
//		int pos = 0, head = 0;
//		int size = op.size();
//		for (int i = 0; i < size; ++i)
//		{
//			if (op[i] == 'U')
//			{
//				pos--;
//				//一般翻页
//				if (head > pos)
//					head = pos;
//				//特殊翻页
//				if (pos < 0)
//				{
//					pos = list[num - 1] - 1;
//					head = list[num - 1] - 4;
//				}
//			}
//			else if (op[i] == 'D')
//			{
//				pos++;
//				//一般翻页
//				if (pos > (head + 3))
//					head = pos - 3;
//				//特殊翻页
//				if (pos > (list[num - 1] - 1))
//				{
//					pos = 0;
//					head = 0;
//				}
//			}
//		}
//		//歌曲总数小于4
//		if (num <= 4)
//			head = 0;
//		//打印当前列表
//		for (int i = head; i < (head + 4); ++i)
//		{
//			if (i < num)
//				cout << list[i] << " ";
//		}
//		cout << endl << list[pos] << endl;
//	}
//	return 0;
//}

////65.查找两个字符串a,b中的最长公共子串：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//string getresult(string s1, string s2)
//{
//	int lsize = s1.size();
//	int ssize = s2.size();
//	string result;
//	for (int i = ssize; i >= 0; --i)
//	{
//		for (int j = 0; j < (ssize - i + 1); ++j)
//		{
//			string temp = s2.substr(j, i);
//			int id = s1.find(temp);
//			if (id != string::npos)
//				return temp;
//		}
//	}
//	return "";
//}
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		string Long, Short;
//		if (s1.size() > s2.size())
//		{
//			Long = s1;
//			Short = s2;
//		}
//		else {
//			Long = s2;
//			Short = s1;
//		}
//		cout << getresult(Long, Short) << endl;
//	}
//	return 0;
//}

////66.配置文件恢复：字符串、字典
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//vector<string> cmd1 = { "reset", "reset", "board", "board", "reboot", "backplane" };
//vector<string> cmd2 = { "none", "board", "add", "delet", "backplane", "abort" };
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int size = str.size();
//		if (str == "")
//		{
//			continue;
//		}
//		if (size > 16)
//		{
//			cout << "unknown command" << endl;
//			continue;
//		}
//		bool isOne = true;
//		int pos = 0;
//		for (int i = 0; i < size; ++i)
//		{
//			if (str[i] == ' ')//
//			{
//				isOne = false;
//				pos = i;
//				break;
//			}
//		}
//		if (isOne)
//		{
//			if (str == cmd1[0].substr(0, size))
//			{
//				cout << "reset what" << endl;
//			}
//			else {
//				cout << "unknown command" << endl;
//			}
//		}
//		else {
//			int num = 0, id;
//			for (int i = 1; i < 6; ++i)
//			{
//				if ((str.substr(0, pos) == cmd1[i].substr(0, pos)) &&
//					(str.substr(pos + 1, size - pos - 1) == cmd2[i].substr(0, size - pos - 1)))
//				{
//					num++;
//					id = i;
//				}
//			}
//			 if(num==1)
//            {
//                switch(id){
//                    case 1:cout<<"board fault"<<endl;break;
//                    case 2:cout<<"where to add"<<endl;break;
//                    case 3:cout<<"no board at all"<<endl;break;
//                    case 4:cout<<"impossible"<<endl;break;
//                    case 5:cout<<"install first"<<endl;break;
//                    default:break;
//                }
//            }
//			else {
//				cout << "unknow command" << endl;
//			}
//		}
//	}
//	return 0;
//}

////67.24点游戏算法：深度优先遍历DFS、搜索
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//using namespace std;
//double op(double a, double b, int opera)
//{
//	if (opera == 0) return a + b;
//	else if (opera == 1) return a - b;
//	else if (opera == 2) return a * b;
//	else if (opera == 3) return a / b;
//	return 0;
//}
//bool cal24(vector<double> a, vector<int> o)
//{
//	bool flag = false;
//	if (o.empty())
//	{
//		if (fabs(a[0] - 24.0) < 0.01) flag = true;
//	}
//	else {
//		for (int i = 0; i < o.size() && !flag; i++)
//		{
//			a[i] = op(a[i], a[i + 1], o[i]);
//			a.erase(a.begin() + i + 1);//删除a[i + 1]
//			o.erase(o.begin() + i);//删除o[i]
//			flag |= cal24(a, o);//递归调用
//		}
//	}
//	return flag;
//}
//int main()
//{
//	double a[4];//4个操作数
//	int o[3];//3个运算符
//	while (cin >> a[0] >> a[1] >> a[2] >> a[3])
//	{
//		bool flag = false;
//		sort(a, a + 4);
//		do {
//			for (int i = 0; i < 4 && !flag; ++i)
//			{
//				o[0] = i;
//				for (int j = 0; j < 4 && !flag; ++j)
//				{
//					o[1] = j;
//					for (int k = 0; k < 4 && !flag; ++k)
//					{
//						o[2] = k;
//						vector<double> va(a, a + 4);
//						vector<int> vo(o, o + 3);
//						if (cal24(va, vo)) flag = true;
//					}
//				}
//			}
//		} while (next_permutation(a, a + 4) && !flag);//下一个全排列
//		if (flag) cout << "true" << endl;
//		else cout << "false" << endl;
//	}
//	return 0;
//}

////68.成绩排序：排序、STL
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//int main()
//{
//	int number, flag;
//	while (cin >> number >> flag)
//	{
//		vector<pair<string, int>> student;//
//		for (int i = 0; i < number; ++i)
//		{
//			pair<string, int> temp;
//			cin >> temp.first;
//			cin >> temp.second;
//			student.push_back(temp);
//		}
//		if (flag)
//		{
//			stable_sort(student.begin(), student.end(),
//				[](const pair<string, int>& v1, const pair<string, int>& v2) { return v1.second < v2.second; });
//		}
//		else {
//			stable_sort(student.begin(), student.end(),
//				[](const pair<string, int>& v1, const pair<string, int>& v2) { return v1.second > v2.second; });
//		}
//		for (auto it = student.begin(); it != student.end(); ++it)
//		{
//			cout << it->first << " " << it->second << endl;
//		}
//	}
//	return 0;
//}

////69.矩阵乘法：数组
//#include <iostream>
//#include <vector>
//using namespace std;
//vector<vector<int>> calcMatrix(vector<vector<int>> A, vector<vector<int>> B, int x, int z)
//{
//	vector<vector<int>> R(x, vector<int>(z, 0));//
//	for (int i = 0; i < x; ++i)
//		for (int j = 0; j < z; ++j)
//		{
//			int sum = 0;
//			for (int m = 0, n = 0; m < A[i].size(), n < B.size(); ++m, ++n) //A[i].size()是A的列数，B.size()是B的行数
//			{
//				sum += A[i][m] * B[n][j];
//			}
//			R[i][j] = sum;
//		}
//	return R;
//}
//int main()
//{
//	int x, y, z;
//	while (cin >> x >> y >> z)
//	{
//		vector<vector<int>> A(x, vector<int>(y, 0));
//		vector<vector<int>> B(y, vector<int>(z, 0));
//		for (int i = 0; i < x; ++i)
//			for (int j = 0; j < y; ++j)
//				cin >> A[i][j];
//		for (int i = 0; i < y; ++i)
//			for (int j = 0; j < z; ++j)
//				cin >> B[i][j];
//		vector<vector<int>> result = calcMatrix(A, B, x, z);
//		for (int i = 0; i < x; ++i)
//		{
//			for (int j = 0; j < z; ++j)
//				cout << result[i][j] << " ";
//			cout << endl;
//		}
//	}
//	return 0;
//}

////70.矩阵乘法计算量估算：字符串、STL
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int* Estimate(int* t1, int* t2, int& sum)
//{
//	int t1_row = t1[0];
//	int t1_col = t1[1];
//	int t2_row = t2[0];
//	int t2_col = t2[1];
//	sum = t1_row * t1_col * t2_col;
//	int* t3 = new int[2];
//	t3[0] = t1_row;
//	t3[1] = t2_col;
//	return t3;
//}
//int calc(vector<int*> &m)
//{
//	int* t1;
//	int* t2;
//	int* t3;
//	int sum = 0;
//	t2 = m.back();
//	m.pop_back();
//	t1 = m.back();
//	m.pop_back();
//	t3 = Estimate(t1, t2, sum);
//	m.push_back(t3);
//	return sum;
//}
//int solution(int* L[2], string str)
//{
//	vector<int*> m;
//	int size = str.size();
//	int sum = 0;
//	int k = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		if (str[i] == ')')
//		{
//			sum += calc(m);
//		}
//		else if (str[i] >= 'A' && str[i] <= 'Z')
//		{
//			m.push_back(L[k]);
//			k++;
//		}
//		//如果是'('就跳过
//	}
//	while (m.size() > 1)//
//	{
//		sum += calc(m);
//	}
//	return sum;
//}
//int main()
//{
//	int number;
//	while (cin >> number)
//	{
//		int** L = new int* [number];
//		for (int i = 0; i < number; ++i)
//		{
//			L[i] = new int[2];
//			cin >> L[i][0];
//			cin >> L[i][1];
//		}
//		string str;
//		cin >> str;
//		cout << solution(L, str) << endl;
//		delete[] L;//
//	}
//	return 0;
//}

////71.字符串通配符：字符串、动态规划、递归、表
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//bool isOk(char c)
//{
//	return (isalpha(c) || isalnum(c) || c == '.');
//}
//bool Match(string s1, string s2)
//{
//	int m = s1.size();
//	int n = s2.size();
//	vector<vector<bool>> v(m + 1, vector<bool>(n + 1, false));
//	v[0][0] = true;//
//	for (int i = 1; i <= m; ++i)
//	{
//		v[i][0] = v[i - 1][0] && (s1[i - 1] == '*');//
//		for (int j = 1; j <= n; ++j)
//		{
//			if (s1[i - 1] == '*')
//			{
//				if (isOk(s2[j - 1]))//匹配多个字符
//					v[i][j] = v[i - 1][j - 1];
//			}
//			else {
//				if (tolower(s1[i - 1]) == tolower(s2[j - 1]))//字母匹配
//					v[i][j] = v[i - 1][j - 1];
//				if (s1[i - 1] == '?' && isOk(s2[j - 1]))//？匹配1个字符
//					v[i][j] = v[i - 1][j - 1];
//			}
//		}
//	}
//	return v[m][n];
//}
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		if (Match(s1, s2)) {
//			cout << "true" << endl;
//		} else {
//			cout << "false" << endl;
//		}
//	}
//	return 0;
//}

////72.百钱买百鸡问题：查找、数学
//#include <iostream>
//#include <vector>
//#include <list>//
//using namespace std;
//int GetResult(vector<list<int>> &result)
//{
//	for (int i = 0; i <= 3; ++i)
//	{
//		list<int> temp;
//		temp.push_back(4 * i);//公鸡
//		temp.push_back(25 - 7 * i);//母鸡
//		temp.push_back(75 + 3 * i);//小鸡
//		result.push_back(temp);
//	}
//	if (result.empty())
//		return -1;
//	else
//		return 0;
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		vector<list<int>> result;
//		if (GetResult(result) == 0)
//		{
//			for (auto i = 0; i < result.size(); ++i)
//			{
//				while (!result[i].empty())
//				{
//					cout << *(result[i].begin()) << " ";//
//					result[i].pop_front();//pop_front
//				}
//				cout << endl;
//			}
//		}
//		result.clear();
//	}
//	return 0;
//}

////73.计算日期到天数转换：字符串、思维、字典
//#include <iostream>
//#include <vector>
//#include <string>
//using namespace std;
//int main()
//{
//	int year, month, day;
//	while (cin >> year >> month >> day)
//	{
//		bool flag = (year % 4 == 0 && year % 100 != 0) ? true : false;//判断闰年
//		vector<int> month1 = { 31, 28, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 };
//		vector<int> month2 = { 31, 29, 31, 30 ,31, 30, 31, 31, 30, 31, 30, 31 };//闰年
//		int sum = 0;
//		for (int i = 0; i < (month - 1); ++i)
//		{
//			if (flag)
//				sum += month2[i];
//			else
//				sum += month1[i];
//		}
//		sum += day;
//		cout << sum << endl;
//	}
//	return 0;
//}

////74.参数解析：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string input;
//	while (getline(cin, input))
//	{
//		int count = 0;
//		for (int i = 0; i < input.size(); ++i)
//		{
//			if (input[i] == '"')//忽略""间的空格
//			{
//				++i;
//				while (input[i] != '"')
//					++i;
//			}
//			if (input[i] == ' ')
//				++count;
//		}
//		cout << count + 1 << endl;
//		for (int i = 0; i < input.size(); ++i)
//		{
//			if (input[i] == '"')
//			{
//				++i;
//				while (input[i] != '"')
//					++i;
//			}
//			if (input[i] != ' ')
//			{
//				cout << input[i];
//			}
//			else {
//				cout << endl;
//			}
//		}
//	}
//	return 0;
//}

////75.公共子串计算：动态规划、STL
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	string s1, s2;
//	while (cin >> s1 >> s2)
//	{
//		vector<vector<int>> m(s1.size() + 1, vector<int>(s2.size() + 1, 0));//包含无字符0,1,2,...,size()所以是size() + 1
//		int max = 0;
//		for (int i = 1; i <= s1.size(); ++i)
//		{
//			for (int j = 1; j <= s2.size(); ++j)
//			{
//				if (s1[i - 1] == s2[j - 1])
//				{
//					m[i][j] = m[i - 1][j - 1] + 1;
//					if (m[i][j] > max)
//						max = m[i][j];
//				}
//			}
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

////76.尼科彻斯定理：数学
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int sum = num * (num - 1) / 2;
//		vector<int> result;
//		for (int k = 0; k < num; ++k)
//		{
//			if (k != num - 1)
//				cout << 2 * (sum + k) + 1 << "+";
//			else
//				cout << 2 * (sum + k) + 1 << endl;
//		}
//	}
//	return 0;
//}

////77.火车进站：栈、递归
//#include <iostream>
//#include <vector>
//#include <queue>//
//#include <stack>//
//#include <algorithm>
//#include <string>
//using namespace std;
//vector<string> result;
//void write_result(queue<int> q)
//{
//	string str;
//	while (!q.empty())
//	{
//		str += to_string(q.front());
//		str += ' ';
//		q.pop();
//	}
//	result.push_back(str);
//}
//void solve(queue<int> in, stack<int> st, queue<int> out, bool flag)
//{
//	if (in.empty()) //in队列为空时
//	{
//		if (flag)
//			return;
//		while (!st.empty()) //将栈中剩余内容全部出栈
//		{
//			out.push(st.top());
//			st.pop();
//		}
//		write_result(out);
//		return;
//	}
//	else {
//		if (flag) //flag为true入栈，为false出栈
//		{
//			//入栈，in队列放入st
//			st.push(in.front());
//			in.pop();
//		}
//		else {    //出栈，放入out队列
//			if (st.empty()) //判断栈内有无数据
//				return;
//			out.push(st.top());
//			st.pop();
//		}
//	}
//	//递归调用
//	solve(in, st, out, false);//出栈
//	solve(in, st, out, true);//入栈
//}
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		int sequence;
//		queue<int> in, out;
//		stack<int> st;
//		for (int i = 0; i < num; ++i)
//		{
//			cin >> sequence;
//			in.push(sequence);
//		}
//		solve(in, st, out, true);//
//		sort(result.begin(), result.end());//将结果按字典排序
//		for (auto it = result.begin(); it != result.end(); ++it)
//		{
//			cout << *it << endl;
//		}
//		result.clear();
//	}
//	return 0;
//}

////80.整型数组合并：排序、数组
//#include <iostream>
//#include <vector>
//#include <map>
//using namespace std;
//int main()
//{
//	int n1, n2, a;
//	while (cin >> n1)
//	{
//		map<int, int> m;
//		for (int i = 0; i < n1; ++i)
//		{
//			cin >> a;
//			m[a]++;
//		}
//		cin >> n2;
//		for (int i = 0; i < n2; ++i)
//		{
//			cin >> a;
//			m[a]++;
//		}
//		for (auto it : m)
//		{
//			cout << it.first;
//		}
//		cout << endl;
//	}
//	return 0;
//}

////81.字符串字符匹配：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string s1, s2;
//    while (cin >> s1 >> s2)
//    {
//        bool flag = true;
//        int size1 = s1.size();
//        int size2 = s2.size();
//        for (int i = 0; i < size1; ++i)
//        {
//            bool find = false;
//            for (int j = 0; j < size2; ++j)
//            {
//                if (s1[i] == s2[j])
//                {
//                    find = true;
//                    break;
//                }
//            }
//            if (!find)
//            {
//                flag = false;
//                break;
//            }
//        }
//        if (flag)
//            cout << "true" << endl;
//        else
//            cout << "false" << endl;
//    }
//    return 0;
//}

////82.将真分数分解为埃及分数：贪心算法、数学、搜索
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string s;
//    while (cin >> s)
//    {
//        string ans;
//        int a, b;
//        for (int i = 0; i < s.size(); ++i)
//        {
//            if (s[i] == '/')
//            {
//                a = stoi(s.substr(0, i));//分子
//                b = stoi(s.substr(i + 1));//分母
//                break;
//            }
//        }
//        while (1)
//        {
//            int e = b / a + 1;
//            ans = "1/";
//            ans += to_string(e);
//            a = a * e - b;//新的a   a/b - 1/e = (a * e - b)/(b * e)
//            b = b * e;//新的b
//            ans += "+";
//            if (a == 1)
//            {
//                ans += "1/";
//                ans += to_string(b);
//                break;
//            }
//            else if (a > 1 && b % a == 0)
//            {
//                ans += "1/";
//                ans += to_string(b / a);
//                break;
//            }
//        }
//        cout << ans << endl;
//    }
//    return 0;
//}

////83.二维数组操作：思维、数组
//#include <iostream>
//using namespace std;
//int main()
//{
//	int m, n;
//	while (cin >> m >> n)
//	{
//		if (m > 9 || n > 9)
//			cout << "-1" << endl;
//		else
//			cout << "0" << endl;
//		int m1, n1, m2, n2;
//		cin >> m1 >> n1 >> m2 >> n2;
//		if (m1 >= 0 && m1 < m && n1 >= 0 && n1 < n &&
//			m2 >= 0 && m2 < m && n2 >= 0 && n2 < n)
//			cout << "0" << endl;
//		else
//			cout << "-1" << endl;
//		int mi, ni;
//		cin >> mi >> ni;
//		if (mi >= 0 && mi < m && m < 9)
//			cout << "0" << endl;
//		else
//			cout << "-1" << endl;
//		if (ni >= 0 && ni < n && n < 9)
//			cout << "0" << endl;
//		else
//			cout << "-1" << endl;
//		int mt, nt;
//		cin >> mt >> nt;
//		if (mt >= 0 && nt >= 0 && mt < m && nt < n)
//			cout << "0" << endl;
//		else
//			cout << "-1" << endl;
//	}
//	return 0;
//}

////84.统计大写字母个数：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int sum = 0;
//		for (int i = 0; i < str.size(); ++i)
//		{
//			if (str[i] >= 'A' && str[i] <= 'Z')
//				sum++;
//		}
//		cout << sum << endl;
//	}
//	return 0;
//}

////85.最长回文子串：字符串、穷举、回文
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//	string str;
//	while (getline(cin, str))
//	{
//		int max = 0;
//		int size = str.size();
//		for (int i = 0; i < size; ++i)
//		{
//			for (int j = size - 1; j > i; --j)
//			{
//				int m = i, n = j, t = 0;
//				while (str[m] == str[n])
//				{
//					t++;
//					m++;
//					n--;
//					if (m >= n)
//					{
//						if (m == n) //奇数个
//							t = 2 * t + 1;
//						else //偶数个
//							t = 2 * t;
//						if (t > max)
//							max = t;
//						break;
//					}
//				}
//			}
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

////86.求最大连续bit数：位运算
//#include <iostream>
//#include <bitset>
//#include <string>
//using namespace std;
//int main()
//{
//	int num;
//	while (cin >> num)
//	{
//		string a;
//		bitset<8> t(num);
//		a = t.to_string();
//		int max = 0;
//		for (int i = 0; i < a.size(); ++i)
//		{
//			int len = 0;
//			while (a[i] == '1')
//			{
//				++len;
//				++i;
//			}
//			if (len > max)
//				max = len;
//		}
//		cout << max << endl;
//	}
//	return 0;
//}

////87.密码强度等级：字符串
//#include <iostream>
//#include <string>
//using namespace std;
//string SecurityLevel(string pw)
//{
//	int sum = 0;
//	int size = pw.size();
//	//长度
//	if (size <= 4)
//		sum += 5;
//	else if (size >= 8)
//		sum += 25;
//	else
//		sum += 10;
//	bool noletter = true;
//	bool haveupper = false;
//	bool havelower = false;
//	bool havenumber = false;
//	bool havesymbol = false;
//	int numsize = 0;
//	int symbolsize = 0;
//	for (int i = 0; i < size; ++i)
//	{
//		if (pw[i] >= '0' && pw[i] <= '9')
//		{
//			havenumber = true;
//			numsize++;
//		}
//		else if (pw[i] >= 'a' && pw[i] <= 'z')
//		{
//			havelower = true;
//			noletter = false;
//		}
//		else if (pw[i] >= 'A' && pw[i] <= 'Z')
//		{
//			haveupper = true;
//			noletter = false;
//		}
//		else {
//			symbolsize++;
//			havesymbol = true;
//		}
//	}
//	if (haveupper && havelower)
//		sum += 20;
//	else if ((haveupper && !havelower) || (!haveupper && havelower))
//		sum += 10;
//	if (numsize > 1)
//		sum += 20;
//	else if (numsize == 1)
//		sum += 10;
//	if (symbolsize > 1)
//		sum += 25;
//	else if (symbolsize == 1)
//		sum += 10;
//	if (haveupper && havelower && havenumber && havesymbol)
//		sum += 5;
//	else if (!noletter && havenumber && havesymbol)
//		sum += 3;
//	else if (!noletter && havenumber)
//		sum += 2;
//	//结果
//	if (sum >= 90)
//		return "VERY_SECURE";
//	else if (sum >= 80)
//		return "SECURE";
//	else if (sum >= 70)
//		return "VERY_STRONG";
//	else if (sum >= 60)
//		return "STRONG";
//	else if (sum >= 50)
//		return "AVERAGE";
//	else if (sum >= 25)
//		return "WEAK";
//	else
//		return "VERY_WEAK";
//}
//int main()
//{
//	string password;
//	while (getline(cin, password))
//	{
//		cout << SecurityLevel(password) << endl;
//	}
//	return 0;
//}

////88.扑克牌大小：字符串、字典、排序、链表、队列、栈
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//vector<string> card = { "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A", "2", "joker", "JOKER" };//
//vector<string> getchild(string s)
//{
//    vector<string> temp;
//    string ss;
//    for (int i = 0; i < s.size(); ++i)
//    {
//        if (s[i] == ' ')
//        {
//            temp.push_back(ss);
//            ss.clear();//
//            continue;
//        }
//        ss += s[i];
//    }
//    temp.push_back(ss);
//    return temp;
//}
//bool cmd(string s1, string s2)
//{
//    int m, n;
//    for (int i = 0; i < card.size(); ++i)
//    {
//        if (s1 == card[i])
//            m = i;
//        if (s2 == card[i])
//            n = i;
//    }
//    if (m > n)
//        return true;
//    else
//        return false;
//}
//bool isSame(vector<string> child)
//{
//    for (int i = 0; i < child.size(); ++i)
//    {
//        if (child[i] != child[0])
//            return false;
//    }
//    return true;
//}
//bool isBomb(string s)
//{
//    vector<string> child = getchild(s);
//    if (child.size() == 4 && isSame(child))
//        return true;
//    return false;
//}
//string Compare(string s1, string s2)
//{
//    if (s1 == "joker JOKER")
//        return s1;
//    else if (s2 == "joker JOKER")
//        return s2;
//    vector<string> c1 = getchild(s1);//
//    vector<string> c2 = getchild(s2);
//    if (isBomb(s1) && !isBomb(s2))
//        return s1;
//    else if (!isBomb(s1) && isBomb(s2))
//        return s2;
//    else if (isBomb(s1) && isBomb(s2))
//    {
//        if (cmd(c1[0], c2[0]))
//            return s1;
//        else
//            return s2;
//    }
//    else {
//        if (c1.size() != c2.size())
//            return "ERROR";
//        if (cmd(c1[0], c2[0]))//牌面从小到大，比较最小就行了
//            return s1;
//        else
//            return s2;
//    }
//}
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        string s1, s2;
//        bool first = true;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            if (str[i] == '-')
//            {
//                first = false;
//                continue;
//            }
//            if (first)
//                s1 += str[i];
//            else
//                s2 += str[i];
//        }
//        cout << Compare(s1, s2) << endl;
//    }
//    return 0;
//}

////89.24点运算：字符串、模拟、穷举、STL
//#include <iostream>
//#include <string>
//#include <algorithm>
//#include <unordered_set>
//#include <unordered_map>
//#include <stack>
//using namespace std;
//unordered_set<string> err{ "joker", "JOKER" };
//unordered_set<char> pri{ '+', '-', '*', '/' };
//unordered_map<string, int> st;
//string path = "";
//int change(char c)
//{
//    if (isdigit(c)) return c - '0';
//    else if (c == 'A') return 1;
//    else if (c == 'J') return 11;
//    else if (c == 'Q') return 12;
//    else if (c == 'K') return 13;
//}
//int cal(string path)
//{
//    stack<int> st;
//    stack<char> stc;
//    for (int i = 0; i < path.size(); ++i)
//    {
//        if (!pri.count(path[i]))//是数字
//        {
//            if (!stc.empty())//运算符栈非空，计算
//            {
//                int a = st.top(); st.pop();
//                int c = stc.top(); stc.pop();
//                if (c == '+') a += change(path[i]);
//                else if (c == '-') a -= change(path[i]);
//                else if (c == '*') a *= change(path[i]);
//                else a /= change(path[i]);
//                st.push(a);//
//            }
//            else st.push(change(path[i]));//无运算符，数字入栈
//        }
//        else stc.push(path[i]);//运算符入栈
//    }
//    return st.top();
//}
//bool dfs(int x)
//{
//    char div[4] = { '+', '-', '*', '/' };
//    bool flag = false;
//    if (x == 4)
//    {
//        if (cal(path) == 24)
//        {
//            cout << path << endl;
//            flag = true;
//        }
//    }
//    for (auto& p : st)
//    {
//        if (p.second)
//        {
//            p.second--;
//            path += p.first;//
//            if (x != 3)
//            {
//                for (int i = 0; i < 4; ++i)
//                {
//                    path += div[i];//
//                    flag = dfs(x + 1);////
//                    if (flag)
//                        return flag;
//                    path.pop_back();
//                }
//            }
//            else
//                flag = dfs(x + 1);////
//            if (flag)
//                return flag;
//            path.pop_back();//
//            p.second++;//
//        }
//    }
//    return flag;
//}
//int main()
//{
//    string a, b, c, d;
//    while (cin >> a >> b >> c >> d)
//    {
//        if (err.count(a) || err.count(b) || err.count(c) || err.count(d))
//            cout << "ERROR" << endl;
//        else
//        {
//            st[a]++;
//            st[b]++;
//            st[c]++;
//            st[d]++;
//            if (!dfs(0))
//                cout << "NONE" << endl;
//        }
//    }
//    return 0;
//}

////90.合法IP：字符串、链表、队列、栈
//#include <iostream>
//#include <string>
//using namespace std;
//string analyze(string str)
//{
//    string temp;
//    int k = 0;
//    for (int i = 0; i < str.size(); ++i)
//    {
//        if (str[i] == '.')
//        {
//            temp = str.substr(k, i - k);
//            k = i + 1;
//            int t = stoi(temp);
//            if (t < 0 || t > 255)
//                return "NO";
//        }
//    }
//    temp = str.substr(k, str.size() - k);
//    int t = stoi(temp);
//    if (t < 0 || t > 255)
//        return "NO";
//    else
//        return "YES";
//}
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        cout << analyze(str) << endl;
//    }
//    return 0;
//}

////91.走方格的方案数：字符串、递归
//#include <iostream>
//#include <string>
//using namespace std;
//int func(int n, int m)
//{
//    if (n == 0 || m == 0)
//        return 1;
//    else if (n < 0 || m < 0)
//        return 0;
//    else
//        return func(n - 1, m) + func(n, m - 1);//
//}
//int main()
//{
//    int n, m;
//    while (cin >> n >> m)
//    {
//        cout << func(n, m) << endl;
//    }
//    return 0;
//}

////92.在字符串中找出连续最长的数字串：字符串、STL
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//string find(string str, int &maxnum)
//{
//    vector<string> result;
//    string maxstr, temp;
//    int num = 0;
//    int size = str.size();
//    for (int i = 0; i < size; ++i)
//    {
//        if (str[i] >= '0' && str[i] <= '9')
//        {
//            temp += str[i];
//            num++;
//        }
//        else {
//            if (num > maxnum)
//            {
//                maxnum = num;
//                result.clear();//
//                result.push_back(temp);
//            }
//            else if (num == maxnum)
//            {
//                result.push_back(temp);
//            }
//            temp.clear();//
//            num = 0;
//        }
//    }
//    //末尾数字处理
//    if (num > maxnum)
//    {
//        maxnum = num;
//        result.clear();
//        result.push_back(temp);
//    }
//    else if (num == maxnum) 
//    {
//        result.push_back(temp);
//    }
//    for (auto i : result)
//        maxstr += i;
//    return maxstr;
//}
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        int maxnum = 0;
//        cout << find(str, maxnum) << "," << maxnum << endl;
//    }
//    return 0;
//}

////93.数组分组：字符串、数组、递归
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//bool add(int num5, int num3, vector<int> v)
//{
//    if (v.size())
//    {
//        if (num5 == num3)
//            return true;
//        else
//            return false;
//    }
//    else {
//        int b = v.back();
//        v.pop_back();
//        return add(num5 + b, num3, v) || add(num5, num3 + b, v);
//    }
//}
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        int num3 = 0;
//        int num5 = 0;
//        vector<int> v;
//        for (int i = 0; i < num; ++i)
//        {
//            int temp;
//            cin >> temp;
//            if (temp % 5 == 0)
//                num5 += temp;//
//            else if (temp % 3 == 0)
//                num3 += temp;//
//            else
//                v.push_back(temp);
//        }
//        if (add(num5, num3, v))
//            cout << "true" << endl;
//        else
//            cout << "false" << endl;
//    }
//    return 0;
//}

////94.记票统计：查找、STL
//#include <iostream>
//#include <string>
//#include <vector>
//#include <unordered_map>
//using namespace std;
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        vector<string> m(num);
//        unordered_map<string, bool> flags(num);
//        unordered_map<string, int> values(num);
//        for (int i = 0; i < num; ++i)
//        {
//            string candidate;
//            cin >> candidate;
//            m[i] = candidate;
//            flags[m[i]] = true;
//        }
//        int n;
//        int invalid = 0;
//        cin >> n;
//        string vote;
//        for (int i = 0; i < n; ++i)
//        {
//            
//            cin >> vote;
//            if (flags[vote] == true)
//            {
//                values[vote]++;
//            }
//            else
//                invalid++;
//        }
//        for (int i = 0; i < num; ++i)
//        {
//            cout << m[i] << " : " << values[m[i]] << endl;
//        }
//        cout << "Invalid: " << invalid << endl;
//    }
//    return 0;
//}

////95.人民币转换：字符串、思维、STL
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//using namespace std;
//vector<string> nums = { "零", "壹", "贰", "叁", "肆", "伍", "陆", "柒", "捌", "玖" };
//vector<string> unit1 = { "元", "万", "亿", "万", "亿" };
//vector<string> unit2 = { "仟", " ", "拾", "佰" };
//int main()
//{
//	double money;
//	while (cin >> money)
//	{
//		cout << "人民币";
//		string sm = to_string(money);
//		int index = sm.find('.');//
//		string mf = sm.substr(0, index);
//		string mb = sm.substr(index + 1);
//		if (mf == "0")
//		{
//			if (mb[0] == '0' && mb[1] == '0')
//				cout << "零元整";
//			else if (mb[1] == '0')
//				cout << nums[mb[0] - '0'] << "角";
//			else if (mb[0] == '0')
//				cout << "零" << nums[mb[1] - '0'] << "分";
//			else
//				cout << nums[mb[0] - '0'] << "角" << nums[mb[1] - '0'] << "分";
//			cout << endl;
//			continue;
//		}
//		while (mf.size())
//		{
//			int t1 = mf.size() / 4;//每四位处理一次
//			int t2 = mf.size() % 4;
//			if (t2 != 1)
//			{
//				if (mf[0] == '0')
//				{
//					if (mf[1] == '0')
//					{
//						mf = mf.substr(1);
//						continue;
//					}
//					else {
//						cout << nums[0];
//					}
//				}
//				else {
//					if (mf[0] - '0' == 1 && t2 == 2)
//						cout << unit2[t2];
//					else
//						cout << nums[mf[0] - '0'] << unit2[t2];
//				}
//			}
//			else {
//				if (mf[0] == '0')
//					cout << unit1[t1];
//				else
//					cout << nums[mf[0] - '0'] << unit1[t1];
//			}
//		}
//		if (mb[0] == '0' && mb[1] == '0')
//			cout << "整";
//		else if (mb[1] == '0')
//			cout << nums[mb[0] - '0'] << "角";
//		else if (mb[0] == '0')
//			cout << nums[mb[1] - '0'] << "分";
//		else
//			cout << nums[mb[0] - '0'] << "角" << nums[mb[1] - '0'] << "分";
//		cout << endl;
//	}
//	return 0;
//}

////96.表示数字：字符串、ST
//#include <iostream>
//#include <string>
//using namespace std;
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        string result;
//        bool start = false;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            if (str[i] >= '0' && str[i] <= '9')
//            {
//                if (start)
//                    result += str[i];
//                else {
//                    result += '*';
//                    result += str[i];
//                    start = true;
//                }
//            }
//            else if (start)
//            {
//                result += '*';
//                result += str[i];
//                start = false;
//            }
//            else
//            {
//                result += str[i];
//            }
//        }
//        if (str[str.size() - 1] >= '0' && str[str.size() - 1] <= '9') //判断最后一个字符是不是数字
//            result += '*';
//        cout << result << endl;
//    }
//    return 0;
//}

////97.记负均正：数组、思维
//#include <iostream>
//#include <string>
//#include <vector>
//#include <iomanip>
//using namespace std;
//double mean(vector<int> pos)
//{
//    double ans = 0.0;
//    for (int i = 0; i < pos.size(); ++i)
//    {
//        ans += pos[i];
//    }
//    ans /= pos.size();
//    return ans;
//}
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        vector<int> pos;
//        vector<int> neg;
//        for (int i = 0; i < num; ++i)
//        {
//            int t;
//            cin >> t;
//            if (t > 0)
//                pos.push_back(t);
//            else if (t < 0)
//                neg.push_back(t);
//        }
//        double result = mean(pos);
//        cout << neg.size() << endl;
//        cout << fixed << setprecision(1) << result << endl;
//    }
//    return 0;
//}

////98.自动售货系统：模拟、面向对象、字符串
//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//#include <unordered_map>
//using namespace std;
////商品类
//class Goods
//{
//private:
//    string name;
//    int price;
//    int num;
//public:
//    Goods() {
//        name = "NONE";
//        price = 0;
//        num = 0;
//    }
//    Goods(string str, int i, int j) {
//        name = str;
//        price = i;
//        num = j;
//    }
//    void Init(int j) {
//        num = j;
//    }
//    string& Name() { return name; }
//    int& Price() { return price; }
//    int& Num() { return num; }
//    void addGoods(int i = 1) {
//        num += i;
//    }
//    void redeceGoods(int i = 1) {
//        num -= i;
//    }
//};
////存钱盒类
//class SavingBox
//{
//private:
//    unordered_map<int, int> coins;
//public:
//    SavingBox() {
//        coins[1] = 0;
//        coins[2] = 0;
//        coins[5] = 0;
//        coins[10] = 0;
//    }
//    SavingBox(unordered_map<int, int>& index) {
//        for (auto iter = index.begin(); iter != index.end(); ++iter) {
//            coins[iter->first] = iter->second;
//        }
//    }
//    unordered_map<int, int>& Coins() { return coins; };
//
//    void Init(unordered_map<int, int>& index) {
//        for (auto iter = index.begin(); iter != index.end(); iter++) {
//            coins[iter->first] = iter->second;
//        }
//    }
//    void addCoin(int i, int j = 1) {
//        coins[i] += j;
//    }
//    void reduceCoin(int i, int j = 1) {
//        coins[i] -= j;
//    }
//    int getCoinNum(int i) {
//        if (coins.count(i))
//            return coins[i];
//        else
//            throw("输入错误");
//    }
//};
////售货系统类
//class VendingSystem
//{
//private:
//    vector<string> names = { "A1", "A2", "A3", "A4", "A5", "A6" };
//    vector<int> prices = { 2, 3, 4, 5, 8, 6 };
//    vector<Goods> shops;//
//    vector<int> coins = { 1, 2, 5, 10 };
//    SavingBox box;//
//    int balance;//投币余额
//public:
//    VendingSystem() {
//        for (int i = 0; i < 6; ++i) {
//            shops.push_back(Goods(names[i], prices[i], 0));
//        }
//        unordered_map<int, int> index;
//        for (int k = 0; k < int(coins.size()); ++k) {
//            index[coins[k]] = 0;
//        }
//        box = SavingBox(index);
//        balance = 0;
//    }
//    void Run(string str) {
//        if (str[0] == 'r') {
//            Init(str);
//        }
//        else if (str[0] == 'p') {
//            Pay(str);
//        }
//        else if (str[0] == 'b') {
//            Buy(str);
//        }
//        else if (str[0] == 'c') {
//            Charge();
//        }
//        else if (str[0] == 'q') {
//            Query(str);
//        }
//        else {
//            throw("输入错误");
//        }
//    }
//    void Init(string str) {
//        balance = 0;
//        str = str.substr(2, str.size() - 2);
//        string initGoodsCmd = str.substr(0, str.find(' '));
//        string initBoxCmd = str.substr(str.find(' ') + 1, str.size() - str.find(' ') - 1);
//        vector<int> nums;
//        int i = 0, j = 0;
//        while (j < int(initGoodsCmd.size())) {
//            if (initGoodsCmd[j] == '-') {
//                nums.push_back(stoi(initGoodsCmd.substr(i, j - i).c_str()));
//                i = j + 1;
//            }
//            j++;
//        }
//        nums.push_back(stoi(initBoxCmd.substr(i, j - i).c_str()));
//        for (int i = 0; i < 6; ++i) {
//            shops[i].Init(nums[i]);
//        }
//        nums.clear();
//        i = 0, j = 0;
//        while (j < int(initBoxCmd.size())) {
//            if (initBoxCmd[j] == '-') {
//                nums.push_back(stoi(initBoxCmd.substr(i, j - i).c_str()));
//                i = j + 1;
//            }
//            j++;
//        }
//        nums.push_back(stoi(initBoxCmd.substr(i, j - i).c_str()));
//        unordered_map<int, int> index;
//        for (int k = 0; k < int(coins.size()); ++k) {
//            index[coins[k]] = nums[k];
//        }
//        box.Init(index);
//        cout << "S001:Initialization is successful" << endl;
//    }
//    void Pay(string str) {
//        int money = atoi(str.substr(2, str.size() - 2).c_str());
//        if (!count(coins.begin(), coins.end(), money)) {
//            cout << "E002:Denomination error" << endl;
//            return;
//        }
//        if (money == 5 || money == 10) {
//            if ((box.getCoinNum(1) + box.getCoinNum(2) * 2) < money) {
//                cout << "E003:Charge is not enough, pay fail" << endl;
//                return;
//            }
//        }
//        bool flag = true;
//        for (auto shop : shops) {
//            if (shop.Num() > 0) {
//                flag = false;
//                break;
//            }
//        }
//        if (flag) {
//            cout << "E005:All the goods sold out" << endl;
//            return;
//        }
//        balance += money;
//        box.addCoin(money);
//        cout << "S001:Pay success, balance = " << balance << endl;
//    }
//    void Buy(string str) {
//        string name = str.substr(2, str.size() - 1);
//        if (!count(names.begin(), names.end(), name)) {
//            cout << "E006:Goods does not exist" << endl;
//        }
//        Goods& shop = shops[distance(names.begin(), find(names.begin(), names.end(), name))];//distance()
//        if (shop.Num() == 0) {
//            cout << "E007:The goods sold out" << endl;
//            return;
//        }
//        if (shop.Price() > balance) {
//            cout << "E008:Lack of balance" << endl;
//        }
//        shop.redeceGoods();
//        balance -= shop.Price();
//        cout << "S003:Buy success, balance = " << balance << endl;
//    }
//    void Charge() {
//        if (balance == 0) {
//            cout << "E009:Wor failure" << endl;
//            return;
//        }
//        vector<int> info(coins.size());
//        for (int i = coins.size() - 1; i >= 0; i--) {
//            int coin = coins[i];
//            while (balance >= coin && box.getCoinNum(coin) > 0) {
//                balance -= coin;
//                box.reduceCoin(coin);
//                info[i]++;
//            }
//        }
//        for (int i = 0; i < int(info.size()); i++) {
//            cout << coins[i] << " yuan coin number = " << info[i] << endl;
//        }
//    }
//    void Query(string str) {
//        if (str == "q 0") {
//            vector<Goods> shops_ = shops;
//            sort(shops_.begin(), shops_.end(), cmp); //根据商品数量从大到小排序
//            for (auto shop : shops_) {
//                cout << shop.Name() << " " << shop.Price() << " " << shop.Num() << endl;
//            }
//            return;
//        }
//        if (str == "q 1") {
//            for (int coin : coins) {
//                cout << coin << " yuan coin number = " << box.getCoinNum(coin) << endl;
//            }
//            return;
//        }
//        cout << "E010:Parameter error" << endl;
//    }
//    static bool cmp(Goods g1, Goods g2) {
//        return g1.Num() < g2.Num();
//    }
//};
//int main()
//{
//    string str;
//    vector<string> cmds;
//    VendingSystem sys;
//    while (getline(cin, str))
//    {
//        int i = 0, j = 0;
//        cmds.clear();//
//        while (j < int(str.size()))
//        {
//            if (str[j] == ';')
//            {
//                cmds.push_back(str.substr(i, j - i));
//                i = j + 1;
//            }
//            j++;
//        }
//        for (unsigned int i = 0; i < cmds.size(); ++i)
//        {
//            sys.Run(cmds[i]);
//        }
//    }
//    return 0;
//}

////99.自守数：数学、查找、提速
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//bool isAN(int num)
//{
//    int square = num * num;
//    string sn = to_string(num);
//    string ss = to_string(square);
//    int k = ss.size() - 1;
//    for (int i = sn.size() - 1; i >= 0; --i)
//    {
//        if (sn[i] != ss[k])
//            return false;
//        k--;
//    }
//    return true;
//}
//int getAN(int num)
//{
//    int sum = 0;
//    for (int i = 0; i <= num; ++i)
//    {
//        if (isAN(i))
//        {
//            sum++;
//        }
//    }
//    return sum;
//}
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        cout << getAN(num) << endl;
//    }
//    return 0;
//}

////100.等差数列：数学
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        cout << num * 2 + num * (num - 1) * 3 / 2 << endl; //Sn = n * a1 + n * (n - 1) * d / 2
//    }
//    return 0;
//}

////101.对数组元素按照升序或降序进行排序：排序
//#include <iostream>
//#include <algorithm>
//#include <vector>
//using namespace std;
//bool cmpdes(int a, int b)
//{
//    return a > b;
//}
//bool cmpasc(int a, int b)
//{
//    return a < b;
//}
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        vector<int> t;
//        for (int i = 0; i < num; ++i)
//        {
//            int a;
//            cin >> a;
//            t.push_back(a);
//        }
//        int flag;
//        cin >> flag;
//        if (flag)
//        {
//            sort(t.begin(), t.end(), cmpdes);
//        }
//        else {
//            sort(t.begin(), t.end(), cmpasc);
//        }
//        for (auto i : t)
//            cout << i << " ";
//        cout << endl;
//    }
//    return 0;
//}

////102.字符统计：字符串、排序、STL
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <string>
//using namespace std;
//bool cmd(pair<char, int> a, pair<char, int> b)
//{
//    if (a.second == b.second)
//        return a.first < b.first;
//    else
//        return a.second > b.second;
//}
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        map<char, int> m;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            m[str[i]]++;
//        }
//        vector<pair<char, int>> v(m.begin(), m.end());
//        sort(v.begin(), v.end(), cmd);//
//        for (auto i : v)
//            cout << i.first;
//        cout << endl;
//    }
//    return 0;
//}

////103.字符统计：字符串、排序、STL
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <map>
//#include <string>
//using namespace std;
//bool cmd(pair<char, int> a, pair<char, int> b)
//{
//    if (a.second == b.second)
//        return a.first < b.first;
//    else
//        return a.second > b.second;
//}
//int main()
//{
//    string str;
//    while (getline(cin, str))
//    {
//        map<char, int> m;
//        for (int i = 0; i < str.size(); ++i)
//        {
//            m[str[i]]++;
//        }
//        vector<pair<char, int>> v(m.begin(), m.end());
//        sort(v.begin(), v.end(), cmd);//
//        for (auto i : v)
//            cout << i.first;
//        cout << endl;
//    }
//    return 0;
//}

////103.Redraiment的走法：排序、动态规划
//#include <iostream>
//#include <vector>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    int num;
//    while (cin >> num)
//    {
//        vector<int> v;
//        for (int i = 0; i < num; ++i)
//        {
//            int temp;
//            cin >> temp;
//            v.push_back(temp);
//        }
//        vector<int> result(num, 1);
//        for (int i = 0; i < num; ++i)
//            for (int j = 0; j < i; j++)
//                if (v[j] < v[i])
//                    result[i] = max(result[i], result[j] + 1);//动态刷新
//        int max = *max_element(result.begin(), result.end());
//        cout << max << endl;
//    }
//    return 0;
//}

////105.记负均正II：数组、思维
//#include <iostream>
//#include <vector>
//#include <iomanip>
//using namespace std;
//double mean(vector<int> pos)
//{
//    double ans = 0.0;
//    for (int i = 0; i < pos.size(); ++i)
//    {
//        ans += pos[i];
//    }
//    return ans /= pos.size();
//}
//int main()
//{
//    int num;
//    vector<int> pos;
//    vector<int> neg;
//    while (cin >> num)
//    {
//        if (num >= 0)
//            pos.push_back(num);
//        else
//            neg.push_back(num);
//    }
//    double result = mean(pos);
//    cout << neg.size() << endl;
//    if (pos.size() == 0)//
//        cout << "0.0" << endl;
//    else
//        cout << fixed << setprecision(1) << result << endl;
//    return 0;
//}

////106.字符逆序：字符串
//#include <iostream>
//#include <algorithm>
//using namespace std;
//int main()
//{
//    string str;
//    while (cin >> str)
//    {
//        reverse(str.begin(), str.end());
//        cout << str << endl;
//    }
//    return 0;
//}

////107.求解立方根：数学、二分、牛顿迭代法
//#include <iostream>
//#include <iomanip>
//using namespace std;
//double func(double t, double num)
//{
//    if (abs(t * t * t - num) < 0.00001)
//        return t;
//    else
//        return func((num / t / t + 2 * t) / 3, num);//x(n+1)=x(n)+(c/(x(n)^2)-x(n))/3
//}
//int main()
//{
//    double num;
//    while (cin >> num)
//    {
//        double result = func(1, num);
//        cout << fixed << setprecision(1) << result << endl;
//    }
//    return 0;
//}

////108.求最小公倍数：数学、递归
//#include <iostream>
//#include <string>
//#include <vector>
//using namespace std;
//int func(int n1, int n2)
//{
//    for (int i = n1; i <= n1 * n2; ++i)
//    {
//        if (i % n1 == 0 && i % n2 == 0)
//            return i;
//    }
//    return n1 * n2;
//}
//int main()
//{
//    int n1, n2;
//    while (cin >> n1 >> n2)
//    {
//        cout << func(n1, n2) << endl;
//    }
//    return 0;
//}