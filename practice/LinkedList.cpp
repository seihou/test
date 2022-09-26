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


////2.设计链表
//#include <iostream>
//using namespace std;
//class MyLinkedList {
//public:
//	//结点结构体
//	struct LinkedNode {
//		int val;
//		LinkedNode* next;
//		LinkedNode(int x) : val(x), next(NULL) {}
//	};
//	//初始化链表
//	MyLinkedList() {
//		_dummyHead = new LinkedNode(0);
//		_size = 0;
//	}
//	//获取index结点的数值，头节点是index=0
//	int get(int index) {
//		if (index < 0 || index > _size - 1) {
//			return -1;
//		}
//		LinkedNode* cur = _dummyHead->next; 
//		while (index--) { //如果--index会陷入死循环
//			cur = cur->next;
//		}
//		return cur->val;
//	}
//	//在链表最前面插入一个节点
//	void addAtHead(int val) {
//		LinkedNode* node = new LinkedNode(val);
//		node->next = _dummyHead->next;
//		_dummyHead->next = node;
//		_size++;
//	}
//	//在链表最后面插入一个节点
//	void addAtTail(int val) {
//		LinkedNode* node = new LinkedNode(val);
//		LinkedNode* cur = _dummyHead;
//		while (cur->next != NULL) {
//			cur = cur->next;
//		}
//		cur->next = node;
//		_size++;
//	}
//	// 在index节点之前插入一个新节点，例如index为0，那么新插入的节点为链表的新头节点。
//	// 如果index 等于链表的长度，则说明是新插入的节点为链表的尾结点
//	// 如果index大于链表的长度，则返回空
//	// 如果index小于0，则置为0，作为链表的新头节点。
//	void addAtIndex(int index, int val) {
//		if (index <= 0) {
//			addAtHead(val);
//		}
//		else if (index > _size - 1) {
//			return;
//		}
//		else if (index == _size - 1) {
//			addAtTail(val);
//		}
//		else {
//			LinkedNode* node = new LinkedNode(val);
//			LinkedNode* pre = _dummyHead;
//			while (index--) {
//				pre = pre->next;
//			}
//			node->next = pre->next;
//			pre->next = node;
//			_size++;
//		}
//	}
//	// 删除index节点，如果index 大于等于链表的长度，直接return，注意index是从0开始的
//	void deleteAtIndex(int index) {
//		if (index >= _size || index < 0) return;
//		LinkedNode* pre = _dummyHead;
//		while (index--) {
//			pre = pre->next;
//		}
//		LinkedNode* temp = pre->next;
//		pre->next = pre->next->next;
//		delete temp;
//		_size--;
//	}
//	//打印链表
//	void printLinkedList() {
//		LinkedNode* cur = _dummyHead;
//		while (cur->next != NULL) {
//			cout << cur->next->val << " ";//打印下一个节点的值
//			cur = cur->next;
//		}
//		cout << endl;
//	}
//private:
//	int _size;
//	LinkedNode* _dummyHead;
//};
//int main()
//{
//	MyLinkedList list;
//	for (int i = 0; i < 5; ++i) {
//		list.addAtHead(i);
//	}
//	list.addAtTail(9);
//	list.printLinkedList();
//	cout << list.get(3) << endl;
//	list.addAtIndex(3, 4);
//	list.deleteAtIndex(0);
//	list.printLinkedList();
//	return 0;
//}


////3.翻转链表
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
//	//双指针法
//	ListNode* reverseList(ListNode* head) {
//		ListNode* pre = NULL;
//		ListNode* cur = head;
//		ListNode* temp;
//		while (cur) {
//			temp = cur->next;
//			cur->next = pre;
//			pre = cur;
//			cur = temp;
//		}
//		return pre;
//	}
//};
//class Solution2 {
//public:
//	//递归法
//	ListNode* reverse(ListNode* pre, ListNode* cur) {
//		if (cur == NULL) return pre;
//		ListNode* temp = cur->next;
//		cur->next = pre;
//		return reverse(cur, temp);
//	}
//	ListNode* reverseList(ListNode* head) {
//		return reverse(NULL, head);
//	}
//};
//int main()
//{
//	int nums[] = { 1,2,6,3,4,5 };
//	vector<int> v(nums, nums + sizeof(nums) / sizeof(*nums));
//	ListNode* head = new ListNode(v[0]);
//	ListNode* cur = head;
//	for (int i = 1; i < v.size(); ++i) {
//		ListNode* node = new ListNode(v[i]);
//		cur->next = node;
//		cur = node;
//	}
//	Solution2 solution;
//	head = solution.reverseList(head);
//	while (head != NULL)
//	{
//		cout << head->val << " ";
//		head = head->next;
//	}
//	return 0;
//}


////4.两两交换链表中的节点
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
//	ListNode* swapPairs(ListNode* head) {
//		ListNode* dummyHead = new ListNode(0);
//		dummyHead->next = head;
//		ListNode* cur = dummyHead;
//		while (cur->next != nullptr && cur->next->next != nullptr) {
//			ListNode* temp = cur->next;
//			ListNode* temp1 = cur->next->next->next;
//
//			cur->next = cur->next->next;//步骤一
//			cur->next->next = temp;//步骤二
//			cur->next->next->next = temp1;//步骤三
//			cur = cur->next->next;//移动两位，准备下一轮交换
//		}
//		return dummyHead->next;
//	}
//};
//int main()
//{
//	int nums[] = { 1,2,6,3,4,5 };
//	vector<int> v(nums, nums + sizeof(nums) / sizeof(*nums));
//	ListNode* head = new ListNode(v[0]);
//	ListNode* cur = head;
//	for (int i = 1; i < v.size(); ++i) {
//		ListNode* node = new ListNode(v[i]);
//		cur->next = node;
//		cur = node;
//	}
//	Solution1 solution;
//	head = solution.swapPairs(head);
//	while (head != NULL)
//	{
//		cout << head->val << " ";
//		head = head->next;
//	}
//	return 0;
//}


////5.删除链表的倒数第N个节点
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
//	//双指针法
//	ListNode* removeNthFromEnd(ListNode* head, int n) {
//		ListNode* dummyHead = new ListNode(0);
//		dummyHead->next = head;
//		ListNode* fast = dummyHead;
//		ListNode* slow = dummyHead;
//		int num = n + 1;
//		while (num--) {
//			fast = fast->next;
//		}
//		while (fast != nullptr) {
//			fast = fast->next;
//			slow = slow->next;
//		}
//		ListNode* temp = slow->next;
//		slow->next = slow->next->next;
//		delete temp;
//		return dummyHead->next;
//	}
//};
//int main()
//{
//	int nums[] = { 1,2,6,3,4,5 };
//	int n = 2;
//	vector<int> v(nums, nums + sizeof(nums) / sizeof(*nums));
//	ListNode* head = new ListNode(v[0]);
//	ListNode* cur = head;
//	for (int i = 1; i < v.size(); ++i) {
//		ListNode* node = new ListNode(v[i]);
//		cur->next = node;
//		cur = node;
//	}
//	Solution1 solution;
//	head = solution.removeNthFromEnd(head, n);
//	while (head != NULL)
//	{
//		cout << head->val << " ";
//		head = head->next;
//	}
//	return 0;
//}


////6.链表相交
//#include <iostream>
//#include <vector>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//class Solution {
//public:
//	int getIntersectionNode(ListNode* headA, ListNode* headB) {
//		ListNode* curA = headA;
//		ListNode* curB = headB;
//		int lenA = 0, lenB = 0;
//		while (curA != NULL) { // 求链表A的长度
//			lenA++;
//			curA = curA->next;
//		}
//		while (curB != NULL) { // 求链表B的长度
//			lenB++;
//			curB = curB->next;
//		}
//		curA = headA;
//		curB = headB;
//		// 让curA为最长链表的头，lenA为其长度
//		if (lenB > lenA) {
//			swap(lenA, lenB);
//			swap(curA, curB);
//		}
//		// 求长度差
//		int gap = lenA - lenB;
//		// 让curA和curB在同一起点上（末尾位置对齐）
//		while (gap--) {
//			curA = curA->next;
//		}
//		// 遍历curA 和 curB，遇到相同则直接返回
//		while (curA != NULL) {
//			if (curA->val == curB->val) {
//				return curA->val;
//			}
//			curA = curA->next;
//			curB = curB->next;
//		}
//		return NULL;
//	}
//};
//int main()
//{
//	int nums1[] = { 1,2,6,3,4,5 };
//	vector<int> v1(nums1, nums1 + sizeof(nums1) / sizeof(*nums1));
//	ListNode* head1 = new ListNode(v1[0]);
//	ListNode* cur1 = head1;
//	for (int i = 1; i < v1.size(); ++i) {
//		ListNode* node1 = new ListNode(v1[i]);
//		cur1->next = node1;
//		cur1 = node1;
//	}
//	int nums2[] = { 6,3,4,5 };
//	vector<int> v2(nums2, nums2 + sizeof(nums2) / sizeof(*nums2));
//	ListNode* head2 = new ListNode(v2[0]);
//	ListNode* cur2 = head2;
//	for (int i = 1; i < v2.size(); ++i) {
//		ListNode* node2 = new ListNode(v2[i]);
//		cur2->next = node2;
//		cur2 = node2;
//	}
//	Solution solution;
//	cout << (solution.getIntersectionNode(head1, head2)) << endl;
//	return 0;
//}


////7.环形链表Ⅱ
//#include <iostream>
//#include <vector>
//using namespace std;
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode(int x) : val(x), next(NULL) {}
//};
//class Solution {
//public:
//	ListNode* detectCycle(ListNode* head) {
//		ListNode* fast = head;
//		ListNode* slow = head;
//		while (fast != NULL && fast->next != NULL) {
//			slow = slow->next;
//			fast = fast->next->next;
//			if (slow == fast) {
//				ListNode* index1 = fast;//
//				ListNode* index2 = head;//
//				while (index1 != index2) {
//					index1 = index1->next;
//					index2 = index2->next;
//				}
//				return index2;//返回环的入口
//			}
//		}
//		return NULL;
//	}
//};
//int main()
//{
//	int nums[] = { 1,2,6,3,4,5 };
//	int n = 2;
//	vector<int> v(nums, nums + sizeof(nums) / sizeof(*nums));
//	ListNode* head = new ListNode(v[0]);
//	ListNode* cur = head;
//	for (int i = 1; i < v.size(); ++i) {
//		ListNode* node = new ListNode(v[i]);
//		cur->next = node;
//		cur = node;
//	}
//	ListNode* temp = head->next->next;
//	cur->next = temp;//形成环链
//	Solution solution;
//	cout << solution.detectCycle(head)->val << endl;//打印环入口节点的值
//	return 0;
//}