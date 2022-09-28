//stack:可以用vector, deque, list实现.
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


//2.用队列实现栈
#include <iostream>
#include <queue>
using namespace std;
class MyStack {
public:
	queue<int> q1;
	queue<int> q2;
	MyStack() {

	}
	
};
int main()
{
	MyStack* stack = new MyStack;
	stack->push(1);
	stack->push(2);
	cout << stack->pop() << endl;
	cout << stack->top() << endl;
	cout << stack->empty();
	return 0;
}