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

////11.
//#include <iostream>
//using namespace std;
//int main()
//{
//	return 0;
//}

//d



