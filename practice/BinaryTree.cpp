////1.�������ĵݹ����
//#include <iostream>
//#include <vector>
//#include <queue>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;
//        if (vec[i] != -1) node = new TreeNode(vec[i]);//-1����սڵ�
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    //�������Һ�����ϵ
//    for (int i = 0; i * 2 < vec.size(); ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////�����ӡ��ӡ������
//void print_binary_tree(TreeNode* root) {
//    queue<TreeNode*> que;
//    if (root != NULL) que.push(root);//
//    vector<vector<int>> result;
//    while (!que.empty()) {
//        vector<int> vec;
//        int size = que.size();//������ÿ��Ľ����
//        for (int i = 0; i < size; ++i) {
//            TreeNode* node = que.front();
//            que.pop();
//            if (node != NULL) {
//                vec.push_back(node->val);
//                que.push(node->left);
//                que.push(node->right);
//            }
//            else vec.push_back(-1);//�ս���ʾΪ-1
//        }
//        result.push_back(vec);
//    }
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//class Solution {
//public:
//    void traversal(TreeNode* cur, vector<int>& vec) {
//        if (cur == NULL) return;
//        //ǰ�����
//        vec.push_back(cur->val);
//        traversal(cur->left, vec);
//        traversal(cur->right, vec);
//        ////�������
//        //traversal(cur->left, vec);
//        //vec.push_back(cur->val);
//        //traversal(cur->right, vec);
//        ////�������
//        //traversal(cur->left, vec);
//        //traversal(cur->right, vec);
//        //vec.push_back(cur->val);
//    }
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> result;
//        traversal(root, result);
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    vector<int> result = solution.preorderTraversal(root);
//    print_binary_tree(root);
//    cout << endl;
//    for (auto i : result) {
//        cout << i << " ";
//    }
//    return 0;
//}


//2.�������ĵ�������
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//�������鹹��������
TreeNode* construct_binary_tree(vector<int> vec) {
    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
    TreeNode* root = NULL;
    //Ϊ������ķ�-1ֵ�������
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]);//-1����սڵ�
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    //�������Һ�����ϵ
    for (int i = 0; i * 2 < vec.size(); ++i) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[2 * i + 1];//
            if (i * 2 + 2 < vec.size())
                vecTree[i]->right = vecTree[2 * i + 2];//
        }
    }
    return root;
}
//�����ӡ��ӡ������
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);//
    vector<vector<int>> result;
    while (!que.empty()) {
        vector<int> vec;
        int size = que.size();//������ÿ��Ľ����
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            else vec.push_back(-1);//�ս���ʾΪ-1
        }
        result.push_back(vec);
    }
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}
class Solution {
public:
    //ǰ��������� (����˳��ͷ���˳����һ�µ�)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();//�����м���
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);//��ջ�����Һ�����������
            if (node->left) st.push(node->left);
        }
        return result;
    }
    //����������� (����˳��ͷ���˳���ǲ�һ�µ�)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;//��
            }
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);//��
                cur = cur->right;//��
            }
        }
        return result;
    }
    //����������� (����˳��ͷ���˳���ǲ�һ�µ�) ������-->������-->������
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();//�����м���
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);//�����ǰ������������һ����ջ˳��
            if (node->right) st.push(node->right);//
        }
        reverse(result.begin(), result.end());//�����ת
        return result;
    }
};
int main()
{
    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//������������
    TreeNode* root = construct_binary_tree(vec);
    Solution solution;
    vector<int> result = solution.postorderTraversal(root);
    print_binary_tree(root);
    cout << endl;
    for (auto i : result) {
        cout << i << " ";
    }
    return 0;
}


//3.��������ͳһ������

////�������
//vector<int> inorderTraversal(TreeNode* root) {
//    vector<int> result;
//    stack<TreeNode*> st;
//    if (root != NULL) st.push(root);
//    while (!st.empty()) {
//        TreeNode* node = st.top();
//        if (node != NULL) {
//            st.pop();
//            if (node->right) st.push(node->right);
//            st.push(node);
//            st.push(NULL);
//            if (node->left) st.push(node->left);
//        }
//        else {
//            st.pop();
//            node = st.top();
//            st.pop();
//            result.push_back(node->val);
//        }
//    }
//    return result;
//}


//4.�������Ĳ������