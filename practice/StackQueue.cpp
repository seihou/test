//stack:可以用vector, deque, list实现
//queue:可以用deque, list实现
//priority_queue:可以用deque, vector实现

////1.用栈实现队列 (两个栈来实现)
//#include <iostream>
//#include <stack>
//using namespace std;
//class MyQueue {
//public:
//	stack<int> stIn;
//	stack<int> stOut;
//	MyQueue() {
//
//	}
//	void push(int x) {
//		stIn.push(x);
//	}
//	int pop() {
//		if (stOut.empty()) {
//			while (!stIn.empty()) {
//				stOut.push(stIn.top());//
//				stIn.pop();//
//			}
//		}
//		int result = stOut.top();
//		stOut.pop();
//		return result;
//	}
//	int peek() {
//		int result = this->pop(); // 直接使用已有的pop函数
//		stOut.push(result); // 因为pop函数弹出了元素res，所以再添加回去
//		return result;
//	}
//	bool empty() {
//		return stIn.empty() && stOut.empty();
//	}
//};
//int main()
//{
//	MyQueue* queue = new MyQueue;
//	queue->push(1);
//	queue->push(2);
//	cout << queue->pop() << endl;
//	cout << queue->peek() << endl;
//	cout << queue->empty();
//	return 0;
//}


////2.用队列实现栈
//#include <iostream>
//#include <queue>
//using namespace std;
////使用2个队列
//class MyStack1 {
//public:
//	queue<int> q1;
//	queue<int> q2;
//	MyStack1() {
//		
//	}
//	void push(int x) {
//		q1.push(x);
//	}
//	int pop() {
//		int size = q1.size();
//		size--;
//		while (size--) {
//			q2.push(q1.front());//将que1 导入que2，但要留下最后一个元素
//			q1.pop();
//		}
//		int result = q1.front();
//		q1.pop();
//		q1 = q2;//q2赋值给q1
//		while (!q2.empty()) {
//			q2.pop();
//		}
//		return result;
//	}
//	int top() {
//		return q1.back();
//	}
//	bool empty() {
//		return q1.empty();
//	}
//};
////只使用一个队列
//class MyStack2 {
//public:
//	queue<int> q;
//	MyStack2() {
//
//	}
//	void push(int x) {
//		q.push(x);
//	}
//	int pop() {
//		int size = q.size();
//		size--;
//		while (size--) {
//			q.push(q.front());
//			q.pop();
//		}
//		int result = q.front();
//		q.pop();
//		return result;
//	}
//	int top() {
//		return q.back();
//	}
//	bool empty() {
//		return q.empty();
//	}
//};
//int main()
//{
//	MyStack2* stack = new MyStack2;
//	stack->push(1);
//	stack->push(2);
//	cout << stack->pop() << endl;
//	cout << stack->top() << endl;
//	cout << stack->empty();
//	return 0;
//}


////3.有效的括号
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    bool invalidBrace(string s) {
//        if (s.size() % 2 != 0) return false;
//        stack<char> st;
//        for (int i = 0; i < s.size(); ++i) {
//            if (s[i] == '(') st.push(')');
//            else if (s[i] == '[') st.push(']');
//            else if (s[i] == '{') st.push('}');
//            else if (st.empty() || st.top() != s[i]) return false;
//            else st.pop();
//        }
//        return st.empty();
//    }
//};
//int main()
//{
//    string str;
//    Solution solution;
//    while (cin >> str) {
//        cout << solution.invalidBrace(str) << endl;
//    }
//    return 0;
//}


////4.删除字符串中的所有相邻重复项
//#include <iostream>
//#include <stack>
//#include <string>
//using namespace std;
//class Solution {
//public:
//    string removeRepetItem(string s) {
//        stack<char> st;
//        for (char c : s) {
//            if (st.empty() || c != st.top()) {
//                st.push(c);
//            }
//            else {
//                st.pop();
//            }
//        }
//        string result = "";
//        while (!st.empty()) {
//            result += st.top();
//            st.pop();
//        }
//        reverse(result.begin(), result.end());
//        return result;
//    }
//};
//int main()
//{
//    string str;
//    Solution solution;
//    while (cin >> str) {
//        cout << solution.removeRepetItem(str) << endl;
//    }
//    return 0;
//}


////5.逆波兰表达式求值
//#include <iostream>
//#include <stack>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    int evalRPN(vector<string>& tokens) {
//        stack<int> st;
//        for (int i = 0; i < tokens.size(); ++i) {
//            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
//                int num1 = st.top();
//                st.pop();
//                int num2 = st.top();
//                st.pop();
//                if (tokens[i] == "+") st.push(num1 + num2);
//                if (tokens[i] == "-") st.push(num1 - num2);
//                if (tokens[i] == "*") st.push(num1 * num2);
//                if (tokens[i] == "/") st.push(num1 / num2);
//            }
//            else {
//                st.push(stoi(tokens[i]));
//            }
//        }
//        int result = st.top();
//        return result;
//    }
//};
//int main()
//{
//    string str;
//    vector<string> input;
//    Solution solution;
//    while (cin >> str) {
//        input.push_back(str);
//    }
//    cout << solution.evalRPN(input);
//    return 0;
//}


////6.滑动窗口最大值 (单调队列)
//#include <iostream>
//#include <deque>
//#include <string>
//#include <vector>
//using namespace std;
//class Solution {
//private:
//    class MyQueue {
//    public:
//        deque<int> que;
//        void pop(int value) {
//            if (!que.empty() && value == que.front()) {
//                que.pop_front();
//            }
//        }
//        void push(int value) {
//            while (!que.empty() && value > que.back()) {
//                que.pop_back();
//            }
//            que.push_back(value);
//        }
//        int front() {
//            return que.front();
//        }
//    };
//public:
//    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//        MyQueue mq;
//        vector<int> result;
//        for (int i = 0; i < k; ++i) {
//            mq.push(nums[i]);
//        }
//        result.push_back(mq.front());
//        for (int i = k; i < nums.size(); ++i) {
//            mq.pop(nums[i - k]);// 滑动窗口移除最前面元素
//            mq.push(nums[i]);// 滑动窗口前加入最后面的元素
//            result.push_back(mq.front());
//        }
//        return result;
//    }
//};
//int main()
//{
//    int a[] = { 1,3,-1,-3,5,3,6,7 };
//    int k = 3;
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution solution;
//    vector<int> result = solution.maxSlidingWindow(nums, k);
//    for (int i : result) {
//        cout << i << " ";
//    }
//    return 0;
//}


////7.前K个高频元素 （优先队列构建小顶堆）
//#include <iostream>
//#include <unordered_map>
//#include <queue>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    // 小顶堆
//    class mycomparison {
//    public:
//        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
//            return lhs.second > rhs.second;//比较频率
//        }
//    };
//    vector<int> topKFrequent(vector<int> nums, int k) {
//        // 要统计元素出现频率
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); ++i) {
//            map[nums[i]]++;
//        }
//        // 对频率排序
//        // 定义一个小顶堆，大小为k
//        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
//        // 用固定大小为k的小顶堆，扫面所有频率的数值
//        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
//            pri_que.push(*it);
//            if (pri_que.size() > k) {
//                pri_que.pop();//去掉堆顶
//            }
//        }
//        // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
//        vector<int> result(k);
//        for (int i = k - 1; i >= 0; --i) {
//            result[i] = pri_que.top().first;
//            pri_que.pop();
//        }
//        return result;
//    }
//};
//int main()
//{
//    int a[] = { 1,1,1,2,2,3 };
//    int k = 2;
//    vector<int> nums(a, a + sizeof(a) / sizeof(*a));
//    Solution solution;
//    vector<int> result = solution.topKFrequent(nums, k);
//    for (int i : result) {
//        cout << i << " ";
//    }
//    return 0;
//}