////1.二叉树的递归遍历
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
////根据数组构建二叉树
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//指针数组，默认值为空
//    TreeNode* root = NULL;
//    //为数组里的非-1值创建结点
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;
//        if (vec[i] != -1) node = new TreeNode(vec[i]);//-1代表空节点
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    //建立左右孩子联系
//    for (int i = 0; i * 2 < vec.size(); ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印打印二叉树
//void print_binary_tree(TreeNode* root) {
//    queue<TreeNode*> que;
//    if (root != NULL) que.push(root);//
//    vector<vector<int>> result;
//    while (!que.empty()) {
//        vector<int> vec;
//        int size = que.size();//二叉树每层的结点数
//        for (int i = 0; i < size; ++i) {
//            TreeNode* node = que.front();
//            que.pop();
//            if (node != NULL) {
//                vec.push_back(node->val);
//                que.push(node->left);
//                que.push(node->right);
//            }
//            else vec.push_back(-1);//空结点表示为-1
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
//        //前序遍历
//        vec.push_back(cur->val);
//        traversal(cur->left, vec);
//        traversal(cur->right, vec);
//        ////中序遍历
//        //traversal(cur->left, vec);
//        //vec.push_back(cur->val);
//        //traversal(cur->right, vec);
//        ////后序遍历
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
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//层序建立二叉树
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


//2.二叉树的迭代遍历
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
//根据数组构建二叉树
TreeNode* construct_binary_tree(vector<int> vec) {
    vector<TreeNode*> vecTree(vec.size(), NULL);//指针数组，默认值为空
    TreeNode* root = NULL;
    //为数组里的非-1值创建结点
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode* node = NULL;
        if (vec[i] != -1) node = new TreeNode(vec[i]);//-1代表空节点
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    //建立左右孩子联系
    for (int i = 0; i * 2 < vec.size(); ++i) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[2 * i + 1];//
            if (i * 2 + 2 < vec.size())
                vecTree[i]->right = vecTree[2 * i + 2];//
        }
    }
    return root;
}
//层序打印打印二叉树
void print_binary_tree(TreeNode* root) {
    queue<TreeNode*> que;
    if (root != NULL) que.push(root);//
    vector<vector<int>> result;
    while (!que.empty()) {
        vector<int> vec;
        int size = que.size();//二叉树每层的结点数
        for (int i = 0; i < size; ++i) {
            TreeNode* node = que.front();
            que.pop();
            if (node != NULL) {
                vec.push_back(node->val);
                que.push(node->left);
                que.push(node->right);
            }
            else vec.push_back(-1);//空结点表示为-1
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
    //前序迭代遍历 (处理顺序和访问顺序是一致的)
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();//处理中间结点
            st.pop();
            result.push_back(node->val);
            if (node->right) st.push(node->right);//入栈先入右孩子再入左孩子
            if (node->left) st.push(node->left);
        }
        return result;
    }
    //中序迭代遍历 (处理顺序和访问顺序是不一致的)
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode* cur = root;
        while (cur != NULL || !st.empty()) {
            if (cur != NULL) {
                st.push(cur);
                cur = cur->left;//左
            }
            else {
                cur = st.top();
                st.pop();
                result.push_back(cur->val);//中
                cur = cur->right;//右
            }
        }
        return result;
    }
    //后序迭代遍历 (处理顺序和访问顺序是不一致的) 中左右-->中右左-->左右中
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        if (root == NULL) return result;
        st.push(root);
        while (!st.empty()) {
            TreeNode* node = st.top();//处理中间结点
            st.pop();
            result.push_back(node->val);
            if (node->left) st.push(node->left);//相对于前序遍历，这更改一下入栈顺序
            if (node->right) st.push(node->right);//
        }
        reverse(result.begin(), result.end());//结果反转
        return result;
    }
};
int main()
{
    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//层序建立二叉树
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


//3.二叉树的统一迭代法

////中序遍历
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


//4.二叉树的层序遍历