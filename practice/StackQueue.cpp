//stack:������vector, deque, listʵ��
//queue:������deque, listʵ��
//priority_queue:������deque, vectorʵ��

////1.��ջʵ�ֶ��� (����ջ��ʵ��)
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
//		int result = this->pop(); // ֱ��ʹ�����е�pop����
//		stOut.push(result); // ��Ϊpop����������Ԫ��res����������ӻ�ȥ
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


////2.�ö���ʵ��ջ
//#include <iostream>
//#include <queue>
//using namespace std;
////ʹ��2������
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
//			q2.push(q1.front());//��que1 ����que2����Ҫ�������һ��Ԫ��
//			q1.pop();
//		}
//		int result = q1.front();
//		q1.pop();
//		q1 = q2;//q2��ֵ��q1
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
////ֻʹ��һ������
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


////3.��Ч������
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


////4.ɾ���ַ����е����������ظ���
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


////5.�沨�����ʽ��ֵ
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


////6.�����������ֵ (��������)
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
//            mq.pop(nums[i - k]);// ���������Ƴ���ǰ��Ԫ��
//            mq.push(nums[i]);// ��������ǰ����������Ԫ��
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


////7.ǰK����ƵԪ�� �����ȶ��й���С���ѣ�
//#include <iostream>
//#include <unordered_map>
//#include <queue>
//#include <vector>
//using namespace std;
//class Solution {
//public:
//    // С����
//    class mycomparison {
//    public:
//        bool operator() (const pair<int, int>& lhs, const pair<int, int>& rhs) {
//            return lhs.second > rhs.second;//�Ƚ�Ƶ��
//        }
//    };
//    vector<int> topKFrequent(vector<int> nums, int k) {
//        // Ҫͳ��Ԫ�س���Ƶ��
//        unordered_map<int, int> map;
//        for (int i = 0; i < nums.size(); ++i) {
//            map[nums[i]]++;
//        }
//        // ��Ƶ������
//        // ����һ��С���ѣ���СΪk
//        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;
//        // �ù̶���СΪk��С���ѣ�ɨ������Ƶ�ʵ���ֵ
//        for (unordered_map<int, int>::iterator it = map.begin(); it != map.end(); it++) {
//            pri_que.push(*it);
//            if (pri_que.size() > k) {
//                pri_que.pop();//ȥ���Ѷ�
//            }
//        }
//        // �ҳ�ǰK����ƵԪ�أ���ΪС�����ȵ���������С�ģ����Ե��������������
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