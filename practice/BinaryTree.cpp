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
//    //先序遍历 递归法
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


//12.左叶子之和
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
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
        TreeNode* node = NULL;//
        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1代表空节点NULL
        vecTree[i] = node;
        if (i == 0) root = node;
    }
    for (int i = 0; i < vec.size() / 2; ++i) {
        if (vecTree[i] != NULL) {
            vecTree[i]->left = vecTree[2 * i + 1];//
            if (i * 2 + 2 < vec.size())
                vecTree[i]->right = vecTree[2 * i + 2];//
        }
    }
    return root;
}
class Solution {
public:
    //先序遍历 递归法
    
};
int main()
{
    vector<int> vec = { 1,2,3,-1,5 };//层序建立二叉树
    TreeNode* root = construct_binary_tree(vec);
    Solution solution;
    vector<string> result = solution.binaryTreePaths2(root);
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}