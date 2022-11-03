//前中后序遍历用栈实现，层序遍历用队列实现
//DFS深度优先遍历（前序遍历） BFS广度优先遍历（层序遍历）

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
////层序打印二叉树
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


////2.二叉树的迭代遍历
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
////层序打印二叉树
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
//    //前序迭代遍历 (处理顺序和访问顺序是一致的)
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root == NULL) return result;
//        st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();//处理中间结点
//            st.pop();
//            result.push_back(node->val);
//            if (node->right) st.push(node->right);//入栈先入右孩子再入左孩子
//            if (node->left) st.push(node->left);
//        }
//        return result;
//    }
//    //中序迭代遍历 (处理顺序和访问顺序是不一致的)
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->left;//左
//            }
//            else {
//                cur = st.top();
//                st.pop();
//                result.push_back(cur->val);//中
//                cur = cur->right;//右
//            }
//        }
//        return result;
//    }
//    //后序迭代遍历 (处理顺序和访问顺序是不一致的) (前序)中左右-->中右左-->(后序)左右中
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root == NULL) return result;
//        st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            st.pop();
//            result.push_back(node->val);//处理中间结点
//            if (node->left) st.push(node->left);//相对于前序遍历，这更改一下入栈顺序
//            if (node->right) st.push(node->right);//
//        }
//        reverse(result.begin(), result.end());//结果反转
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    vector<int> result = solution.postorderTraversal(root);
//    print_binary_tree(root);
//    cout << endl;
//    for (auto i : result) {
//        cout << i << " ";
//    }
//    return 0;
//}


////3.二叉树的统一迭代法 (标记法)
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
////层序打印二叉树
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
//    //前序统一迭代遍历
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root != NULL) st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop();//
//                if (node->right) st.push(node->right);
//                if (node->left) st.push(node->left);
//                st.push(node);
//                st.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记
//            }
//            else {
//                st.pop();
//                node = st.top();
//                st.pop();
//                result.push_back(node->val);
//            }
//        }
//        return result;
//    }
//    //中序统一迭代遍历
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root != NULL) st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop();
//                if (node->right) st.push(node->right);
//                st.push(node);
//                st.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记
//                if (node->left) st.push(node->left);
//            }
//            else {
//                st.pop();
//                node = st.top();
//                st.pop();
//                result.push_back(node->val);
//            }
//        }
//        return result;
//    }
//    //后序统一迭代遍历
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root != NULL) st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop();//
//                st.push(node);
//                st.push(NULL);// 中节点访问过，但是还没有处理，加入空节点做为标记
//                if (node->right) st.push(node->right);
//                if (node->left) st.push(node->left);
//            }
//            else {
//                st.pop();//弹出NULL结点
//                node = st.top();
//                st.pop();
//                result.push_back(node->val);
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    vector<int> result = solution.postorderTraversal(root);
//    print_binary_tree(root);
//    cout << endl;
//    for (auto i : result) {
//        cout << i << " ";
//    }
//    return 0;
//}


////4.二叉树的层序遍历
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
//class Solution {
//public:
//    //层序遍历
//    vector<vector<int>> levelorderTraversal(TreeNode* root) {
//        queue<TreeNode*> que;
//        if (root != NULL) que.push(root);
//        vector<vector<int>> result;
//        while (!que.empty()) {
//            vector<int> vec;
//            int size = que.size();//
//            for (int i = 0; i < size; ++i) 
//            {
//                TreeNode* node = que.front();
//                que.pop();
//                vec.push_back(node->val);
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//            result.push_back(vec);
//        }
//        return result;
//    }
//    //递归法 recursion
//    void order(TreeNode* cur, vector<vector<int>>& result, int depth) {
//        if (cur == NULL) return;
//        if (result.size() == depth) result.push_back(vector<int>());
//        result[depth].push_back(cur->val);
//        order(cur->left, result, depth + 1);
//        order(cur->right, result, depth + 1);
//    }
//    vector<vector<int>> recursionlevelorderTraversal(TreeNode* root) {
//        vector<vector<int>> result;
//        int depth = 0;
//        order(root, result, depth);
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    vector<vector<int>> result = solution.recursionlevelorderTraversal(root);
//    for (int i = 0; i < result.size(); ++i) {
//        for (int j = 0; j < result[i].size(); ++j) {
//            cout << result[i][j] << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}


////5.翻转二叉树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//class Solution {
//public:
//    //层序遍历翻转 (广度优先遍历)
//    TreeNode* levelorderInvertTree(TreeNode* root) {
//        queue<TreeNode*> que;
//        if (root != NULL) que.push(root);
//        while (!que.empty()) {
//            int size = que.size();//
//            for (int i = 0; i < size; ++i)
//            {
//                TreeNode* node = que.front();
//                que.pop();
//                swap(node->left, node->right);////
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//        }
//        return root;
//    }
//    //前序统一遍历翻转（深度优先遍历）
//    TreeNode* preorderInvertTree1(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root != NULL) st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();//
//            if (node != NULL) {
//                st.pop();//
//                if (node->right) st.push(node->right);
//                if (node->left) st.push(node->left);
//                st.push(node);
//                st.push(NULL);
//            }
//            else {
//                st.pop();
//                node = st.top();//
//                st.pop();
//                swap(node->left, node->right);//
//            }
//        }
//        return root;
//    }
//    //前序迭代遍历翻转（深度优先遍历）iteration
//    TreeNode* preorderInvertTree2(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root == NULL) return root;
//        st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();//
//            st.pop();
//            swap(node->left, node->right);//
//            if (node->right) st.push(node->right);
//            if (node->left) st.push(node->left);
//        }
//        return root;
//    }
//    //前序递归遍历翻转（深度优先遍历）recursion
//    TreeNode* preorderInvertTree3(TreeNode* root) {
//        if (root == NULL) return root;
//        swap(root->left, root->right);//中
//        preorderInvertTree3(root->left);//左
//        preorderInvertTree3(root->right);//右
//        return root;
//    }
//};
////层序打印二叉树
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
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    solution.preorderInvertTree3(root);
//    print_binary_tree(root);
//    return 0;
//}


////6.对称二叉树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
//class Solution {
//public:
//    bool compare(TreeNode* left, TreeNode* right) {
//        if (left == NULL && right != NULL) return false;
//        else if (left != NULL && right == NULL) return false;
//        else if (left == NULL && right == NULL) return true;
//        else if (left->val != right->val) return false;
//        //单层递归:处理左右节点都不为空，且数值相同的情况
//        bool outside = compare(left->left, right->right);//
//        bool inside = compare(left->right, right->left);//
//        bool isSame = outside && inside;
//        return isSame;
//    }
//    bool isSymmetric(TreeNode* root) {
//        if (root == NULL) return true;
//        return compare(root->left, root->right);
//    }
//};
////层序打印二叉树
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
//int main()
//{
//    vector<int> vec = { 1,2,2,3,4,4,3 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.isSymmetric(root);
//    return 0;
//}


////7.二叉树的最大深度
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//    //后序遍历递归法
//    int getMaxDepth1(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftdepth = getMaxDepth1(root->left);//左
//        int rightdepth = getMaxDepth1(root->right);//右
//        int depth = 1 + max(leftdepth, rightdepth);//中
//        return depth;
//    }
//    //前序遍历递归法
//    int result;
//    void getDepth(TreeNode* node, int depth) {
//        result = depth > result ? depth : result;//中
//        if (node->left == NULL && node->right == NULL) return;
//        if (node->left) { //左
//            getDepth(node->left, depth + 1);
//        }
//        if (node->right) { //右
//            getDepth(node->right, depth + 1);
//        }
//        return;
//    }
//    int getMaxDepth2(TreeNode* root) {
//        result = 0;
//        if (root == NULL) return 0;
//        getDepth(root, 1);//
//        return result;
//    }
//    //层序遍历迭代法
//    int getMaxDepth3(TreeNode* root) {
//        if (root == NULL) return 0;
//        int depth = 0;
//        queue<TreeNode*> que;
//        que.push(root);
//        while (!que.empty()) {
//            depth++;//
//            int size = que.size();
//            for (int i = 0; i < size; ++i) {
//                TreeNode* node = que.front();
//                que.pop();
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//        }
//        return depth;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.getMaxDepth3(root);
//    return 0;
//}


////8.二叉树的最小深度
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//    //后序遍历递归法
//    int getMinDepth1(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftdepth = getMinDepth1(root->left);//左
//        int rightdepth = getMinDepth1(root->right);//右
//        //中
//        if (root->left == NULL && root->right != NULL) {
//            return 1 + rightdepth;
//        }
//        if (root->left != NULL && root->right == NULL) {
//            return 1 + leftdepth;
//        }
//        int result = 1 + min(leftdepth, rightdepth);
//        return result;
//    }
//    //前序遍历递归法
//    int result;
//    void getDepth(TreeNode* node, int depth) {
//        if (node->left == NULL && node->right == NULL) {//叶子结点
//            result = min(result, depth);
//            return;
//        }
//        //中
//        if (node->left) { //左
//            getDepth(node->left, depth + 1);
//        }
//        if (node->right) { //右
//            getDepth(node->right, depth + 1);
//        }
//        return;
//    }
//    int getMaxDepth2(TreeNode* root) {
//        result = INT_MAX;
//        if (root == NULL) return 0;
//        getDepth(root, 1);//
//        return result;
//    }
//    //层序遍历迭代法
//    int getMaxDepth3(TreeNode* root) {
//        if (root == NULL) return 0;
//        int depth = 0;
//        queue<TreeNode*> que;
//        que.push(root);
//        while (!que.empty()) {
//            depth++;
//            int size = que.size();
//            for (int i = 0; i < size; ++i) {
//                TreeNode* node = que.front();
//                que.pop();
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//                if (node->left == NULL && node->right == NULL) {
//                    return depth;//找到叶子结点就返回
//                }
//            }
//        }
//        return depth;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.getMinDepth1(root);
//    return 0;
//}


////9.完全二叉树的结点个数
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//    //后序遍历递归法
//    int getNodesNum1(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftnum = getNodesNum1(root->left);//左
//        int rightnum = getNodesNum1(root->right);//右
//        //中
//        int treeNum = leftnum + rightnum + 1;//
//        return treeNum;
//    }
//    //前序遍历递归法
//    int result;
//    void getNum(TreeNode* node, int depth) {
//        result++;//记录节点数量
//        if (node->left == NULL && node->right == NULL) {//叶子结点
//            return;
//        }
//        //中
//        if (node->left) { //左
//            getNum(node->left, depth + 1);
//        }
//        if (node->right) { //右
//            getNum(node->right, depth + 1);
//        }
//        return;
//    }
//    int getNodesNum2(TreeNode* root) {
//        result = 0;
//        if (root == NULL) return 0;
//        getNum(root, 1);//
//        return result;
//    }
//    //层序遍历迭代法
//    int getNodesNum3(TreeNode* root) {
//        queue<TreeNode*> que;
//        if (root != NULL) que.push(root);
//        int result = 0;
//        while (!que.empty()) {
//            int size = que.size();
//            for (int i = 0; i < size; ++i) {
//                TreeNode* node = que.front();
//                que.pop();
//                result++;//记录节点数量
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//        }
//        return result;
//    }
//    //完全二叉树法
//    int getNodesNum4(TreeNode* root) {
//        if (root == NULL) return 0;
//        TreeNode* left = root->left;
//        TreeNode* right = root->right;
//        int leftDepth = 0, rightDepth = 0;
//        while (left) {
//            left = left->left;
//            leftDepth++;
//        }
//        while (right) {
//            right = right->right;
//            rightDepth++;
//        }
//        //满二叉树
//        if (leftDepth == rightDepth) {
//            return (2 << leftDepth) - 1; //leftDepth是从0开始计算
//        }
//        //非满二叉树
//        return getNodesNum4(root->left) + getNodesNum4(root->right) + 1;
//    }
//};
//int main()
//{
//    //保证输入的树是完全二叉树！！！
//    vector<int> vec = { 1,2,3,4,5,6 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.getNodesNum4(root);
//    return 0;
//}


////10.平衡二叉树  
////求深度可以用前序和后序，但是求高度不能用前序遍历
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//    //后序遍历递归法
//    int getHight(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftHight = getHight(root->left);//左
//        if (leftHight == -1) return -1;
//        int rightHight = getHight(root->right);//右
//        if (rightHight == -1) return -1;
//        //中
//        return abs(leftHight - rightHight) > 1 ? -1 : 1 + max(leftHight, rightHight);//如果差值小于等于1，则返回当前二叉树的高度
//    }
//    bool isBalanced1(TreeNode* root) {
//        return getHight(root) == -1 ? false : true;
//    }
//    //迭代法
//    int getDepth(TreeNode* cur) {
//        stack<TreeNode*> st;
//        if (cur != NULL) st.push(cur);
//        int depth = 0, result = 0;
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop();
//                //统一前序遍历迭代 求最大深度
//                st.push(node);
//                st.push(NULL);
//                depth++;//
//                if (node->right) st.push(node->right);
//                if (node->left) st.push(node->left);
//            }
//            else {
//                st.pop();
//                node = st.top();
//                st.pop();
//                depth--;//
//            }
//            result = result > depth ? result : depth;//max
//        }
//        return result;
//    }
//    bool isBalanced2(TreeNode* root) {
//        stack<TreeNode*> st;
//        if (root == NULL) return true;
//        st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            st.pop();
//            //后序遍历
//            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) return false;//中
//            if (node->right) st.push(node->right);//右
//            if (node->left) st.push(node->left);//左
//        }                                         
//        return true;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.isBalanced2(root);
//    return 0;
//}


////11.二叉树的所有路径 (回溯算法)
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//    //前序遍历 递归法
//    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
//        path.push_back(cur->val);//// 中，中为什么写在这里，因为最后一个节点也要加入到path中
//        if (cur->left == NULL && cur->right == NULL) { //遇到叶子结点
//            string sPath;
//            for (int i = 0; i < path.size() - 1; ++i) {
//                sPath += to_string(path[i]);
//                sPath += "->";
//            }
//            sPath += to_string(path[path.size() - 1]);
//            result.push_back(sPath);
//            return;
//        }
//        //path.push_back(cur->val);//中，中如果在这里，path就会缺最后一个结点
//        if (cur->left) {
//            traversal(cur->left, path, result);//左
//            path.pop_back();//回溯
//        }
//        if (cur->right) {
//            traversal(cur->right, path, result);//右
//            path.pop_back();//回溯
//        }
//    }
//    vector<string> binaryTreePaths1(TreeNode* root) {
//        vector<string> result;
//        vector<int> path;
//        if (root == NULL) return result;
//        traversal(root, path, result);
//        return result;
//    }
//    //前序遍历迭代法
//    vector<string> binaryTreePaths2(TreeNode* root) {
//        stack<TreeNode*> treeSt;
//        stack<string> pathSt;
//        vector<string> result;
//        if (root == NULL) return result;
//        treeSt.push(root);
//        pathSt.push(to_string(root->val));
//        while (!treeSt.empty()) {
//            TreeNode* node = treeSt.top();
//            treeSt.pop();
//            string path = pathSt.top();
//            pathSt.pop();
//            if (node->left == NULL && node->right == NULL) {
//                result.push_back(path);
//            }
//            if (node->right) {
//                treeSt.push(node->right);
//                pathSt.push(path + "->" + to_string(node->right->val));
//            }
//            if (node->left) {
//                treeSt.push(node->left);
//                pathSt.push(path + "->" + to_string(node->left->val));
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 1,2,3,-1,5 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    vector<string> result = solution.binaryTreePaths2(root);
//    for (string s : result) {
//        cout << s << endl;
//    }
//    return 0;
//}


////12.左叶子之和
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
//class Solution {
//public:
//    //后序遍历 递归法
//    int sumOfLeftLeaves1(TreeNode* root) {
//        if (root == NULL) return 0;
//        if (root->left == NULL && root->right == NULL) return 0;
//        int leftValue = sumOfLeftLeaves1(root->left);//左
//        if (root->left && !root->left->left && !root->left->right) {
//            leftValue = root->left->val;//
//        }
//        int rightValue = sumOfLeftLeaves1(root->right);//右
//        int sum = leftValue + rightValue;//中
//        return sum;
//    }
//    //前序遍历 迭代法
//    int sumOfLeftLeaves2(TreeNode* root) {
//        stack<TreeNode*> st;
//        if (root == NULL) return 0;
//        st.push(root);
//        int result = 0;
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            st.pop();
//            if (node->left != NULL && node->left->left == NULL && node->left->right == NULL) {
//                result += node->left->val;
//            }
//            if (node->right) st.push(node->right);
//            if (node->left) st.push(node->left);
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.sumOfLeftLeaves2(root);
//    return 0;
//}


////13.找树左下角的值
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
//class Solution {
//public:
//    //前序遍历 递归法
//    int maxDepth = INT_MIN;
//    int result;
//    void traversal(TreeNode* root, int depth) {
//        if (root->left == NULL && root->right == NULL) {
//            if (depth > maxDepth) {
//                maxDepth = depth;
//                result = root->val;
//            }
//            return;
//        }
//        if (root->left) traversal(root->left, depth + 1);
//        if (root->right) traversal(root->right, depth + 1);
//    }
//    int findBottomLeftValue1(TreeNode* root) {
//        traversal(root, 1);
//        return result;
//    }
//    //层序遍历 迭代法
//    int findBottomLeftValue2(TreeNode* root) {
//        if (root == NULL) return 0;
//        queue<TreeNode*> que;
//        que.push(root);
//        int result = 0;
//        while (!que.empty()) {
//            int size = que.size();
//            for (int i = 0; i < size; ++i) {
//                TreeNode* node = que.front();
//                que.pop();
//                if (i == 0) result = node->val;//
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.findBottomLeftValue1(root);
//    return 0;
//}


////!14.从中序和后序遍历序列构造二叉树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////层序打印二叉树
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
//	TreeNode* traversal(vector<int>& invec, vector<int>& postvec) {
//		//1 如果数组大小为零的话，说明是空节点
//		if (postvec.size() == 0) return NULL;
//		//2 如果不为空，那么取后序数组最后一个元素作为节点元素
//		int rootValue = postvec[postvec.size() - 1];//
//		TreeNode* root = new TreeNode(rootValue);
//		if (postvec.size() == 1) return root;////
//		//3 找到后序数组最后一个元素在中序数组的位置，作为切割点
//		int delimiterIndex;
//		for (delimiterIndex = 0; delimiterIndex < invec.size(); ++delimiterIndex) {
//			if (invec[delimiterIndex] == rootValue) break;
//		}
//		//4 切割中序数组
//		vector<int> leftInvec(invec.begin(), invec.begin() + delimiterIndex);
//		vector<int> rightInvec(invec.begin() + delimiterIndex + 1, invec.end());
//		//5 切割后序数组
//		postvec.resize(postvec.size() - 1);
//		vector<int> leftPostvec(postvec.begin(), postvec.begin() + leftInvec.size());
//		vector<int> rightPostvec(postvec.begin() + leftPostvec.size(), postvec.end());
//		//6 递归处理左区间和右区间
//		root->left = traversal(leftInvec, leftPostvec);
//		root->right = traversal(rightInvec, rightPostvec);
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& invec, vector<int>& postvec) {
//		if (invec.size() == 0 || postvec.size() == 0) return NULL;
//		return traversal(invec, postvec);
//	}
//};
//int main()
//{
//	vector<int> invec = { 9,3,15,20,7 };//中序数组
//	vector<int> postvec = { 9,15,7,20,3 };//后序数组
//	Solution solution;
//	print_binary_tree(solution.buildTree(invec, postvec));
//	return 0;
//}


////!15.从前序和中序遍历序列构造二叉树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////层序打印二叉树
//void print_binary_tree(TreeNode* root) {
//	queue<TreeNode*> que;
//	if (root != NULL) que.push(root);//
//	vector<vector<int>> result;
//	while (!que.empty()) {
//		vector<int> vec;
//		int size = que.size();//二叉树每层的结点数
//		for (int i = 0; i < size; ++i) {
//			TreeNode* node = que.front();
//			que.pop();
//			if (node != NULL) {
//				vec.push_back(node->val);
//				que.push(node->left);
//				que.push(node->right);
//			}
//			else vec.push_back(-1);//空结点表示为-1
//		}
//		result.push_back(vec);
//	}
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; j < result[i].size(); ++j) {
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//class Solution {
//public:
//	TreeNode* traversal(vector<int>& prevec,int prevecBegin, int prevecEnd, vector<int>& invec, int invecBegin, int invecEnd) {
//		//1 如果数组大小为零的话，说明是空节点
//		if (prevecBegin == prevecEnd) return NULL;
//		//2 如果不为空，那么取后序数组最后一个元素作为节点元素
//		int rootValue = prevec[prevecBegin];//
//		TreeNode* root = new TreeNode(rootValue);
//		if (prevecEnd - prevecBegin == 1) return root;////
//		//3 找到后序数组最后一个元素在中序数组的位置，作为切割点
//		int delimiterIndex;
//		for (delimiterIndex = invecBegin; invecBegin < invecEnd; ++delimiterIndex) {
//			if (invec[delimiterIndex] == rootValue) break;
//		}
//		//4 切割中序数组
//		int leftInvecBegin = invecBegin;
//		int leftInvecEnd = delimiterIndex;
//		int rightInvecBegin = delimiterIndex + 1;
//		int rightInvecEnd = invecEnd;
//		//5 切割前序数组
//		int leftPrevecBegin = prevecBegin + 1;
//		int leftPrevecEnd = prevecBegin + 1 + (delimiterIndex - invecBegin);
//		int rightPrevecBegin = prevecBegin + 1 + (delimiterIndex - invecBegin);
//		int rightPrevecEnd = prevecEnd;
//		//6 递归处理左区间和右区间
//		root->left = traversal(prevec, leftPrevecBegin, leftPrevecEnd, invec, leftInvecBegin, leftInvecEnd);
//		root->right = traversal(prevec, rightPrevecBegin, rightPrevecEnd, invec, rightInvecBegin, rightInvecEnd);
//		return root;
//	}
//	TreeNode* buildTree(vector<int>& prevec, vector<int>& invec) {
//		if (invec.size() == 0 || prevec.size() == 0) return NULL;
//		return traversal(prevec, 0, prevec.size(), invec, 0, invec.size());
//	}
//};
//int main()
//{
//	vector<int> prevec = { 3,9,20,15,7 };//中序数组
//	vector<int> invec = { 9,3,15,20,7 };//后序数组
//	Solution solution;
//	print_binary_tree(solution.buildTree(prevec, invec));
//	return 0;
//}


////16.最大二叉树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
//using namespace std;
//struct TreeNode {
//	int val;
//	TreeNode* left;
//	TreeNode* right;
//	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////层序打印二叉树
//void print_binary_tree(TreeNode* root) {
//	queue<TreeNode*> que;
//	if (root != NULL) que.push(root);//
//	vector<vector<int>> result;
//	while (!que.empty()) {
//		vector<int> vec;
//		int size = que.size();//二叉树每层的结点数
//		for (int i = 0; i < size; ++i) {
//			TreeNode* node = que.front();
//			que.pop();
//			if (node != NULL) {
//				vec.push_back(node->val);
//				que.push(node->left);
//				que.push(node->right);
//			}
//			else vec.push_back(-1);//空结点表示为-1
//		}
//		result.push_back(vec);
//	}
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; j < result[i].size(); ++j) {
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//class Solution {
//public:
//	TreeNode* traversal(vector<int>& vec) {
//		TreeNode* node = new TreeNode(0);
//		if (vec.size() == 1) {
//			node->val = vec[0];
//			return node;
//		}
//		int maxValue = 0;
//		int maxValueIndex = 0;
//		for (int i = 0; i < vec.size(); ++i) {
//			if (vec[i] > maxValue) {
//				maxValue = vec[i];
//				maxValueIndex = i;
//			}
//		}
//		node->val = maxValue;
//		// 最大值所在的下标左区间 构造左子树
//		if (maxValueIndex > 0) {
//			vector<int> newVec(vec.begin(), vec.begin() + maxValueIndex);
//			node->left = traversal(newVec);
//		}
//		// 最大值所在的下标右区间 构造右子树
//		if (maxValueIndex < (vec.size() - 1)) {
//			vector<int> newVec(vec.begin() + maxValueIndex + 1, vec.end());
//			node->right = traversal(newVec);
//		}
//		return node;
//
//	}
//	TreeNode* buildTree(vector<int>& vec) {
//		if (vec.size() == 0) return NULL;
//		return traversal(vec);
//	}
//};
//int main()
//{
//	vector<int> prevec = { 3,2,1,6,0,5 };//不重复数组
//	Solution solution;
//	print_binary_tree(solution.buildTree(prevec));
//	return 0;
//}


////17.合并二叉树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
//void print_binary_tree(TreeNode* root) {
//	queue<TreeNode*> que;
//	if (root != NULL) que.push(root);//
//	vector<vector<int>> result;
//	while (!que.empty()) {
//		vector<int> vec;
//		int size = que.size();//二叉树每层的结点数
//		for (int i = 0; i < size; ++i) {
//			TreeNode* node = que.front();
//			que.pop();
//			if (node != NULL) {
//				vec.push_back(node->val);
//				que.push(node->left);
//				que.push(node->right);
//			}
//			else vec.push_back(-1);//空结点表示为-1
//		}
//		result.push_back(vec);
//	}
//	for (int i = 0; i < result.size(); ++i) {
//		for (int j = 0; j < result[i].size(); ++j) {
//			cout << result[i][j] << " ";
//		}
//		cout << endl;
//	}
//}
//class Solution {
//public:
//    //前序遍历 递归法
//    TreeNode* mergeTree1(TreeNode* root1, TreeNode* root2) {
//        if (root1 == NULL) return root2;
//        if (root2 == NULL) return root1;
//        TreeNode* root = new TreeNode(0);
//        root->val = root1->val + root2->val;
//        root->left = mergeTree1(root1->left, root2->left);
//        root->right= mergeTree1(root1->right, root2->right);
//        return root;
//    }
//    //迭代法
//    TreeNode* mergeTree2(TreeNode* root1, TreeNode* root2) {
//        if (root1 == NULL) return root2;
//        if (root2 == NULL) return root1;
//        queue<TreeNode*> que;
//        que.push(root1);
//        que.push(root2);
//        while (!que.empty()) {
//            TreeNode* node1 = que.front(); que.pop();
//            TreeNode* node2 = que.front(); que.pop();
//            node1->val += node2->val;
//            if (node1->left && node2->left) {
//                que.push(node1->left);//
//                que.push(node2->left);//
//            }
//            if (node1->right && node2->right) {
//                que.push(node1->right);//
//                que.push(node2->right);//
//            }
//            if (node1->left == NULL && node2->left) {
//                node1->left = node2->left;
//            }
//            if (node1->right == NULL && node2->right) {
//                node1->right = node2->right;
//            }
//        }
//        return root1;
//    }
//};
//int main()
//{
//    vector<int> vec1 = { 1,3,2,5 };
//    TreeNode* root1 = construct_binary_tree(vec1);
//    vector<int> vec2 = { 2,1,3,-1,4,-1,7 };
//    TreeNode* root2 = construct_binary_tree(vec2);
//    Solution solution;
//    print_binary_tree(solution.mergeTree2(root1, root2));
//    return 0;
//}


////!18.二叉搜索树的搜索 (结点有序)（二叉搜索树，递归遍历和迭代遍历和普通二叉树都不一样）
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//    //递归法
//    TreeNode* searchBST1(TreeNode* root, int val) {
//        if (root == NULL || root->val == val) return root;
//        TreeNode* result = NULL;
//        if (root->val > val) result = searchBST1(root->left, val);
//        if (root->val < val) result = searchBST1(root->right, val);
//        return result;
//    }
//    //迭代法 二叉搜索树不需要回溯，所以不用栈和队列就可以搜索值
//    TreeNode* searchBST2(TreeNode* root, int val) {
//        while (root != NULL) {
//            if (root->val > val) root = root->left;
//            else if (root->val < val) root = root->right;
//            else return root;
//        }
//        return NULL;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,2,7,1,3 };
//    int val = 7;
//    TreeNode* root1 = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.searchBST1(root1, val)->val;
//    return 0;
//}


////19.验证二叉搜索树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
//class Solution {
//public:
//    //中序递归法
//    vector<int> vec;
//    void traversal(TreeNode* root) {
//        if (root == NULL) return;
//        traversal(root->left);
//        vec.push_back(root->val);//中
//        traversal(root->right);
//    }
//    bool isValidBST1(TreeNode* root) {
//        vec.clear();
//        traversal(root);
//        for (int i = 1; i < vec.size(); ++i) {
//            if (vec[i] <= vec[i - 1]) return false;
//        }
//        return true;
//    }
//    //递归法2 （递归遍历的过程中直接判断是否有序）
//    long long maxVal = LONG_MIN; //测试数据中有int最小值
//    bool isValidBST2(TreeNode* root) {
//        if (root == NULL) return true;
//        bool left = isValidBST2(root->left);
//        //中序遍历，验证遍历的元素是不是从小到大
//        if (maxVal < root->val) maxVal = root->val;
//        else return false;
//        bool right = isValidBST2(root->right);
//        return left && right;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,2,7,1,3 };
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.isValidBST2(root);
//    return 0;
//}


////20.二叉搜索树的最小绝对差
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <string>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
//class Solution {
//public:
//    //中序递归法
//    vector<int> vec;
//    void traversal(TreeNode* root) {
//        if (root == NULL) return;
//        traversal(root->left);
//        vec.push_back(root->val);//中
//        traversal(root->right);
//    }
//    int getMinimumDifference1(TreeNode* root) {
//        vec.clear();
//        traversal(root);//遍历获得有序数组
//        if (vec.size() < 2) return 0;
//        int result = INT_MAX;
//        for (int i = 1; i < vec.size(); ++i) {
//            result = min(result, vec[i] - vec[i - 1]);
//        }
//        return result;
//    }
//    //中序递归法 （遍历过程中直接计算）
//    int result = INT_MAX;
//    TreeNode* pre = NULL;//
//    void traversa2(TreeNode* cur) {
//        if (cur == NULL) return;
//        traversa2(cur->left);
//        if (pre != NULL) {
//            result = min(result, cur->val - pre->val);
//        }
//        pre = cur;
//        traversa2(cur->right);
//    }
//    int getMinimumDifference2(TreeNode* root) {
//        traversa2(root);//遍历获得有序数组
//        return result;
//    }
//    //中序迭代法
//    int getMinimumDifference3(TreeNode* root) {
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        TreeNode* pre = NULL;
//        int result = INT_MAX;
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->left; //左
//            }
//            else {
//                cur = st.top();
//                st.pop();
//                if (pre != NULL) { //中
//                    result = min(result, cur->val - pre->val);
//                }
//                pre = cur;
//                cur = cur->right; //右
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,2,7,1,3 };
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.getMinimumDifference3(root);
//    return 0;
//}


////20.二叉搜索树中的众数
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//#include <unordered_map>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//class Solution1 {
//private:
//
//    void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // 前序遍历
//        if (cur == NULL) return;
//        map[cur->val]++; // 统计元素频率
//        searchBST(cur->left, map);
//        searchBST(cur->right, map);
//        return;
//    }
//    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
//        return a.second > b.second;
//    }
//public:
//    vector<int> findMode(TreeNode* root) {
//        unordered_map<int, int> map; // key:元素，value:出现频率
//        vector<int> result;
//        if (root == NULL) return result;
//        searchBST(root, map);
//        vector<pair<int, int>> vec(map.begin(), map.end());//
//        sort(vec.begin(), vec.end(), cmp); // 给频率排个序
//        result.push_back(vec[0].first);////
//        for (int i = 1; i < vec.size(); i++) {
//            // 取最高的放到result数组中
//            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
//            else break;
//        }
//        return result;
//    }
//};
////递归法
//class Solution2 {
//private:
//    int maxCount = 0;
//    int count = 0;
//    TreeNode* pre = NULL;
//    vector<int> result;
//    void searchBST(TreeNode* cur) { // 前序遍历
//        if (cur == NULL) return;
//        searchBST(cur->left);//左
//        if (pre == NULL) { //中
//            count = 1;
//        }
//        else if (pre->val == cur->val) {
//            count++;
//        }
//        else {
//            count = 1;
//        }
//        pre = cur;
//        if (count == maxCount) {
//            result.push_back(cur->val);//
//        }
//        if (count > maxCount) {
//            maxCount = count;
//            result.clear();
//            result.push_back(cur->val);
//        }
//        searchBST(cur->right);//右
//        return;
//    }
//public:
//    vector<int> findMode(TreeNode* root) {
//        count = 0;
//        maxCount = 0;
//        TreeNode* pre = NULL;
//        result.clear();
//        searchBST(root);
//        return result;
//    }
//};
////迭代法
//class Solution3 {
//public:
//    vector<int> findMode(TreeNode* root) {
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        TreeNode* pre = NULL;
//        int maxCount = 0;
//        int count = 0;
//        vector<int> result;
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->left;
//            }
//            else {
//                cur = st.top();
//                st.pop();
//                if (pre == NULL) {
//                    count = 1;
//                }
//                else if (pre->val == cur->val) {
//                    count++;
//                }
//                else {
//                    count = 1;
//                }
//                if (count == maxCount) {
//                    result.push_back(cur->val);
//                }
//                if (count > maxCount) {
//                    maxCount = count;
//                    result.clear();
//                    result.push_back(cur->val);
//                }
//                pre = cur;
//                cur = cur->right;
//            }
//        }
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 1,-1,2,-1,-1,2 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution3 solution;
//    vector<int> result = solution.findMode(root);
//    for (int s : result) {
//        cout << s << endl;
//    }
//    return 0;
//}


////21.二叉树的最近公共祖先
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////后序遍历递归法
//class Solution1 {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
//        if (root->val == q || root->val == p || root == NULL) return root;//终止条件
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//        if (left != NULL && right != NULL) return root;
//        if (left == NULL) return right;//
//        return left;//
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,5,1,6,2,0,8,-1,-1,7,4 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution1 solution;
//    int q = 5, p = 1;
//    cout << solution.lowestCommonAncestor(root, p, q)->val;
//    return 0;
//}


////22.二叉搜索树的最近公共祖先
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////递归法
//class Solution1 {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
//        if (root == NULL) return root;
//        if (root->val > p && root->val > q) {
//            TreeNode* left = lowestCommonAncestor(root->left, p, q);
//            if (left != NULL) return left;
//        }
//        if (root->val < p && root->val < q) {
//            TreeNode* right = lowestCommonAncestor(root->right, p, q);
//            if (right != NULL) return right;
//        }
//        return root;
//    }
//};
////迭代法
//class Solution2 {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
//        while (root) {
//            if (root->val > p && root->val > q) {
//                root = root->left;
//            }
//            else if (root->val < p && root->val < q) {
//                root = root->right;
//            }
//            else return root;
//        }
//        return NULL;
//    }
//};
//int main()
//{
//    vector<int> vec = { 6,2,8,0,4,7,9,-1,-1,3,5 };//层序建立二叉树
//    TreeNode* root = construct_binary_tree(vec);
//    Solution2 solution;
//    int q = 2, p = 8;
//    cout << solution.lowestCommonAncestor(root, p, q)->val;
//    return 0;
//}


////23.二叉搜索树中的插入操作
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
////递归法
//class Solution1 {
//public:
//    //写法一
//    TreeNode* insertBST(TreeNode* root, int val) {
//        if (root == NULL) {//终止条件
//            TreeNode* node = new TreeNode(val);
//            return node;//返回结点
//        }
//        if (root->val > val) root->left = insertBST(root->left, val);
//        if (root->val < val) root->right = insertBST(root->right, val);
//        return root;
//    }
//    //写法二
//    TreeNode* parent;
//    void traversal(TreeNode* cur, int val) {
//        if (cur == NULL) {
//            TreeNode* node = new TreeNode(val);
//            if (val > parent->val) parent->right = node;
//            else parent->left = node;
//            return;
//        }
//        parent = cur;
//        if (cur->val > val) traversal(cur->left, val);
//        if (cur->val < val) traversal(cur->right, val);
//        return;
//    }
//    TreeNode* insertBST2(TreeNode* root, int val) {
//        parent = new TreeNode(0);
//        if (root == NULL) {
//            root = new TreeNode(val);
//        }
//        traversal(root, val);
//        return root;
//    }
//    //迭代法
//    TreeNode* insertBST3(TreeNode* root, int val) {
//        if (root == NULL) {
//            TreeNode* node = new TreeNode(val);
//            return node;
//        }
//        TreeNode* cur = root;
//        TreeNode* parent = root;
//        while (cur != NULL) {
//            parent = cur;
//            if (cur->val > val) cur = cur->left;
//            else cur = cur->right;
//        }
//        TreeNode* node = new TreeNode(val);
//        if (val < parent->val) parent->left = node;
//        else parent->right = node;
//        return root;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,2,7,1,3 };
//    TreeNode* root = construct_binary_tree(vec);
//    Solution1 solution;
//    int val = 5;
//    solution.insertBST3(root, val);
//    print_binary_tree(root);
//    return 0;
//}


////24.删除二叉搜索树中的节点
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//class Solution1 {
//public:
//    //普通二叉树的删除方式
//    TreeNode* deleteNode0(TreeNode* root, int key) {
//        if (root == NULL) return root;
//        if (root->val == key) {
//            if (root->right == NULL) {//
//                return root->left;
//            }
//            TreeNode* cur = root->right;
//            while (cur) {
//                cur = cur->left;
//            }
//            swap(root->val, cur->val);////
//        }
//        root->left = deleteNode0(root->left, key);
//        root->right = deleteNode0(root->right, key);
//        return root;
//    }
//    //递归法
//    TreeNode* deleteNode1(TreeNode* root, int key) {
//        if (root == NULL) return root;
//        if (root->val == key) {
//            if (root->left == NULL && root->right == NULL) {
//                delete root;
//                return NULL;
//            }
//            else if (root->left == NULL) {
//                auto retNode = root->right;
//                delete root;
//                return retNode;
//            }
//            else if (root->right == NULL) {
//                auto retNode = root->left;
//                delete root;
//                return retNode;
//            } 
//            else {
//                TreeNode* cur = root->right;//
//                while (cur->left != NULL) {
//                    cur = cur->left;
//                }
//                cur->left = root->left;////
//                TreeNode* tmp = root;
//                root = root->right;//
//                delete tmp;
//                return root;
//            }
//        }
//        if (root->val > key) root->left = deleteNode1(root->left, key);
//        if (root->val < key) root->right = deleteNode1(root->right, key);
//        return root;
//    }
//    //迭代法
//    TreeNode* deleteOneNode(TreeNode* target) {
//        if (target == NULL) return target;
//        if (target->right == NULL) return target->left;
//        TreeNode* cur = target->right;
//        while (cur->left) {
//            cur = cur->left;
//        }
//        cur->left = target->left;
//        return target->right;
//    }
//    TreeNode* deleteNode2(TreeNode* root, int key) {
//        if (root == NULL) return root;
//        TreeNode* cur = root;
//        TreeNode* pre = NULL;
//        while (cur) {
//            if (cur->val == key) break;
//            pre = cur;
//            if (cur->val > key) cur = cur->left;
//            else cur = cur->right;
//        }
//        // pre 要知道是删左孩子还是右孩子
//        if (pre->left && pre->left->val == key) {
//            pre->left = deleteOneNode(cur);
//        }
//        if (pre->right && pre->right->val == key) {
//            pre->right = deleteOneNode(cur);
//        }
//        return root;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,2,7,1,3 };
//    TreeNode* root = construct_binary_tree(vec);
//    Solution1 solution;
//    int val = 7;
//    solution.deleteNode2(root, val);
//    print_binary_tree(root);
//    return 0;
//}


////25.修剪二叉搜索树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
//class Solution1 {
//public:
//    //递归法
//    TreeNode* trimBST(TreeNode* root, int low, int high) {
//        if (root == NULL) return NULL;
//        if (root->val < low) {
//            TreeNode* right = trimBST(root->right, low, high);
//            return right;
//        }
//        if (root->val > high) {
//            TreeNode* left = trimBST(root->left, low, high);
//            return left;
//        }
//        root->left = trimBST(root->left, low, high);
//        root->right = trimBST(root->right, low, high);
//        return root;
//    }
//    //迭代法
//    TreeNode* trimBST2(TreeNode* root, int low, int high) {
//        if (!root) return NULL;
//        while (root != NULL && (root->val < low || root->val > high)) {
//            if (root->val < low) root = root->right;
//            else root = root->left;
//        }
//        TreeNode* cur = root;
//        while (cur != NULL) 
//        {
//            while (cur->left && cur->left->val < low) {
//                cur->left = cur->left->right;
//            }
//            cur = cur->left;
//        }
//        cur = root;
//        while (cur != NULL) {
//            while (cur->right && cur->right->val > high) {
//                cur->right = cur->right->left;
//            }
//            cur = cur->right;
//        }
//        return root;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,2,7,1,3 };
//    TreeNode* root = construct_binary_tree(vec);
//    Solution1 solution;
//    int low = 1, high = 4;
//    solution.trimBST(root, low, high);
//    print_binary_tree(root);
//    return 0;
//}


////26.将有序数组转换为高度平衡二叉搜索树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
//using namespace std;
//struct TreeNode {
//    int val;
//    TreeNode* left;
//    TreeNode* right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};
////层序打印二叉树
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
//class Solution1 {
//public:
//    //递归法
//    TreeNode* traversal(vector<int>& nums, int left, int right) {
//        if (left > right) return NULL;
//        int mid = left + (right - left) / 2;
//        TreeNode* root = new TreeNode(nums[mid]);
//        root->left = traversal(nums, left, mid - 1);
//        root->right = traversal(nums, mid + 1, right);
//        return root;
//    }
//    TreeNode* sortedArrayToBST(vector<int>& nums) {
//        TreeNode* root = traversal(nums, 0, nums.size() - 1);
//        return root;
//    }
//};
//int main()
//{
//    vector<int> vec = { -10,-3,0,5,9 };
//    Solution1 solution;
//    TreeNode* root = solution.sortedArrayToBST(vec);
//    print_binary_tree(root);
//    return 0;
//}


////27.把二叉搜索树转换为累加树
//#include <iostream>
//#include <vector>
//#include <queue>
//#include <stack>
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
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
//        vecTree[i] = node;
//        if (i == 0) root = node;
//    }
//    for (int i = 0; i < vec.size() / 2; ++i) {
//        if (vecTree[i] != NULL) {
//            vecTree[i]->left = vecTree[2 * i + 1];//
//            if (i * 2 + 2 < vec.size())
//                vecTree[i]->right = vecTree[2 * i + 2];//
//        }
//    }
//    return root;
//}
////层序打印二叉树
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
////递归法 (反中序遍历)
//class Solution1 {
//public:
//    int pre = 0;
//    void traversal1(TreeNode* cur) {
//        if (cur == NULL) return;
//        traversal1(cur->right);
//        cur->val += pre;
//        pre = cur->val;
//        traversal1(cur->left);
//    }
//    TreeNode* convertBST1(TreeNode* root) {
//        pre = 0;
//        traversal1(root);
//        return root;
//    }
//};
////迭代法
//class Solution2 {
//public:
//    int pre = 0;
//    void traversal2(TreeNode* root) {
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->right;
//            }
//            else {
//                cur = st.top();
//                st.pop();
//                cur->val += pre;
//                pre = cur->val;
//                cur = cur->left;
//            }
//        }
//    }
//    TreeNode* convertBST2(TreeNode* root) {
//        pre = 0;
//        traversal2(root);
//        return root;
//    }
//};
//int main()
//{
//    vector<int> vec = { 5,2,13 };
//    TreeNode* root = construct_binary_tree(vec);
//    Solution2 solution;
//    solution.convertBST2(root);
//    print_binary_tree(root);
//    return 0;
//}