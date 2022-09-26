////1.移除链表元素
//#include <iostream>
//#include <vector>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//class Solution1 {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		//删除头节点
//		while (head != NULL && head->val == val) {
//			ListNode* temp = head;
//			head = head->next;
//			delete temp;
//		}
//		//删除非头结点
//		ListNode* cur = head;
//		while (cur != NULL && cur->next != NULL) {
//			if (cur->next->val == val) {
//				ListNode* temp = cur->next;
//				cur->next = temp->next;
//				delete temp;
//			}
//			else {
//				cur = cur->next;
//			}
//		}
//		return head;
//	}
//};
//class Solution2 {
//public:
//	ListNode* removeElements(ListNode* head, int val) {
//		//设置虚拟头结点,头节点和普通结点一样处理
//		ListNode* dummyHead = new ListNode(0);
//		dummyHead->next = head;
//		ListNode* cur = dummyHead;
//		while (cur->next != NULL) {
//			if (cur->next->val == val) {
//				ListNode* temp = cur->next;
//				cur->next = cur->next->next;
//				delete temp;
//			}
//			else {
//				cur = cur->next;
//			}
//		}
//		head = dummyHead->next;
//		delete dummyHead;//
//		return head;
//	}
//};
//int main()
//{
//	int nums[] = { 1,2,6,3,4,5 };
//	int val = 6;
//	vector<int> v(nums, nums + sizeof(nums) / sizeof(*nums));
//	ListNode* head = new ListNode(v[0]);
//	ListNode* cur = head;
//	for (int i = 1; i < v.size(); ++i) {
//		ListNode* node = new ListNode(v[i]);
//		cur->next = node;
//		cur = node;
//	}
//	Solution2 solution;
//	head = solution.removeElements(head, val);
//	while (head != NULL)
//	{
//		cout << head->val << " ";
//		head = head->next;
//	}
//	return 0;
//}


//2.设计链表
#include <iostream>
#include <vector>
using namespace std;
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};
class MyLinkedList {
public:
	ListNode* removeElements(ListNode* head, int val) {
		//删除头节点
		while (head != NULL && head->val == val) {
			ListNode* temp = head;
			head = head->next;
			delete temp;
		}
		//删除非头结点
		ListNode* cur = head;
		while (cur != NULL && cur->next != NULL) {
			if (cur->next->val == val) {
				ListNode* temp = cur->next;
				cur->next = temp->next;
				delete temp;
			}
			else {
				cur = cur->next;
			}
		}
		return head;
	}
};
int main()
{
	int nums[] = { 1,2,6,3,4,5 };
	int val = 6;
	vector<int> v(nums, nums + sizeof(nums) / sizeof(*nums));
	ListNode* head = new ListNode(v[0]);
	ListNode* cur = head;
	for (int i = 1; i < v.size(); ++i) {
		ListNode* node = new ListNode(v[i]);
		cur->next = node;
		cur = node;
	}
	Solution2 solution;
	head = solution.removeElements(head, val);
	while (head != NULL)
	{
		cout << head->val << " ";
		head = head->next;
	}
	return 0;
}