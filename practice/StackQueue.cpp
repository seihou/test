//stack:������vector, deque, listʵ��.
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


//2.�ö���ʵ��ջ
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