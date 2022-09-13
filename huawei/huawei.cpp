//https://zhaitianbao.blog.csdn.net/article/details/120820959

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

//33.整数与IP地址间的转换：字符串、位运算、串流
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    
    return 0;
}