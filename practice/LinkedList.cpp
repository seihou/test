////1.�Ƴ�����Ԫ��
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
//		//ɾ��ͷ�ڵ�
//		while (head != NULL && head->val == val) {
//			ListNode* temp = head;
//			head = head->next;
//			delete temp;
//		}
//		//ɾ����ͷ���
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
//		//��������ͷ���,ͷ�ڵ����ͨ���һ������
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


////2.�������
//#include <iostream>
//using namespace std;
//class MyLinkedList {
//public:
//	//���ṹ��
//	struct LinkedNode {
//		int val;
//		LinkedNode* next;
//		LinkedNode(int x) : val(x), next(NULL) {}
//	};
//	//��ʼ������
//	MyLinkedList() {
//		_dummyHead = new LinkedNode(0);
//		_size = 0;
//	}
//	//��ȡindex������ֵ��ͷ�ڵ���index=0
//	int get(int index) {
//		if (index < 0 || index > _size - 1) {
//			return -1;
//		}
//		LinkedNode* cur = _dummyHead->next; 
//		while (index--) { //���--index��������ѭ��
//			cur = cur->next;
//		}
//		return cur->val;
//	}
//	//��������ǰ�����һ���ڵ�
//	void addAtHead(int val) {
//		LinkedNode* node = new LinkedNode(val);
//		node->next = _dummyHead->next;
//		_dummyHead->next = node;
//		_size++;
//	}
//	//��������������һ���ڵ�
//	void addAtTail(int val) {
//		LinkedNode* node = new LinkedNode(val);
//		LinkedNode* cur = _dummyHead;
//		while (cur->next != NULL) {
//			cur = cur->next;
//		}
//		cur->next = node;
//		_size++;
//	}
//	// ��index�ڵ�֮ǰ����һ���½ڵ㣬����indexΪ0����ô�²���Ľڵ�Ϊ�������ͷ�ڵ㡣
//	// ���index ��������ĳ��ȣ���˵�����²���Ľڵ�Ϊ�����β���
//	// ���index��������ĳ��ȣ��򷵻ؿ�
//	// ���indexС��0������Ϊ0����Ϊ�������ͷ�ڵ㡣
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
//	// ɾ��index�ڵ㣬���index ���ڵ�������ĳ��ȣ�ֱ��return��ע��index�Ǵ�0��ʼ��
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
//	//��ӡ����
//	void printLinkedList() {
//		LinkedNode* cur = _dummyHead;
//		while (cur->next != NULL) {
//			cout << cur->next->val << " ";//��ӡ��һ���ڵ��ֵ
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


////3.��ת����
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
//	//˫ָ�뷨
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
//	//�ݹ鷨
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


////4.�������������еĽڵ�
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
//			cur->next = cur->next->next;//����һ
//			cur->next->next = temp;//�����
//			cur->next->next->next = temp1;//������
//			cur = cur->next->next;//�ƶ���λ��׼����һ�ֽ���
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


////5.ɾ������ĵ�����N���ڵ�
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
//	//˫ָ�뷨
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


////6.�����ཻ
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
//		while (curA != NULL) { // ������A�ĳ���
//			lenA++;
//			curA = curA->next;
//		}
//		while (curB != NULL) { // ������B�ĳ���
//			lenB++;
//			curB = curB->next;
//		}
//		curA = headA;
//		curB = headB;
//		// ��curAΪ������ͷ��lenAΪ�䳤��
//		if (lenB > lenA) {
//			swap(lenA, lenB);
//			swap(curA, curB);
//		}
//		// �󳤶Ȳ�
//		int gap = lenA - lenB;
//		// ��curA��curB��ͬһ����ϣ�ĩβλ�ö��룩
//		while (gap--) {
//			curA = curA->next;
//		}
//		// ����curA �� curB��������ͬ��ֱ�ӷ���
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


////7.���������
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
//				return index2;//���ػ������
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
//	cur->next = temp;//�γɻ���
//	Solution solution;
//	cout << solution.detectCycle(head)->val << endl;//��ӡ����ڽڵ��ֵ
//	return 0;
//}