//ǰ�к��������ջʵ�֣���������ö���ʵ��
//DFS������ȱ�����ǰ������� BFS������ȱ��������������

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
////�����ӡ������
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


////2.�������ĵ�������
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
////�����ӡ������
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
//    //ǰ��������� (����˳��ͷ���˳����һ�µ�)
//    vector<int> preorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root == NULL) return result;
//        st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();//�����м���
//            st.pop();
//            result.push_back(node->val);
//            if (node->right) st.push(node->right);//��ջ�����Һ�����������
//            if (node->left) st.push(node->left);
//        }
//        return result;
//    }
//    //����������� (����˳��ͷ���˳���ǲ�һ�µ�)
//    vector<int> inorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->left;//��
//            }
//            else {
//                cur = st.top();
//                st.pop();
//                result.push_back(cur->val);//��
//                cur = cur->right;//��
//            }
//        }
//        return result;
//    }
//    //����������� (����˳��ͷ���˳���ǲ�һ�µ�) (ǰ��)������-->������-->(����)������
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root == NULL) return result;
//        st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            st.pop();
//            result.push_back(node->val);//�����м���
//            if (node->left) st.push(node->left);//�����ǰ������������һ����ջ˳��
//            if (node->right) st.push(node->right);//
//        }
//        reverse(result.begin(), result.end());//�����ת
//        return result;
//    }
//};
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//������������
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


////3.��������ͳһ������ (��Ƿ�)
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
////�����ӡ������
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
//    //ǰ��ͳһ��������
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
//                st.push(NULL);// �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ���
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
//    //����ͳһ��������
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
//                st.push(NULL);// �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ���
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
//    //����ͳһ��������
//    vector<int> postorderTraversal(TreeNode* root) {
//        vector<int> result;
//        stack<TreeNode*> st;
//        if (root != NULL) st.push(root);
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop();//
//                st.push(node);
//                st.push(NULL);// �нڵ���ʹ������ǻ�û�д�������սڵ���Ϊ���
//                if (node->right) st.push(node->right);
//                if (node->left) st.push(node->left);
//            }
//            else {
//                st.pop();//����NULL���
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
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//������������
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


////4.�������Ĳ������
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
//class Solution {
//public:
//    //�������
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
//    //�ݹ鷨 recursion
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
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//������������
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


////5.��ת������
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
//class Solution {
//public:
//    //���������ת (������ȱ���)
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
//    //ǰ��ͳһ������ת��������ȱ�����
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
//    //ǰ�����������ת��������ȱ�����iteration
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
//    //ǰ��ݹ������ת��������ȱ�����recursion
//    TreeNode* preorderInvertTree3(TreeNode* root) {
//        if (root == NULL) return root;
//        swap(root->left, root->right);//��
//        preorderInvertTree3(root->left);//��
//        preorderInvertTree3(root->right);//��
//        return root;
//    }
//};
////�����ӡ������
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
//int main()
//{
//    vector<int> vec = { 4,1,6,0,2,5,7,-1,-1,-1,3,-1,-1,-1,8 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    solution.preorderInvertTree3(root);
//    print_binary_tree(root);
//    return 0;
//}


////6.�Գƶ�����
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
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�
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
//        //����ݹ�:�������ҽڵ㶼��Ϊ�գ�����ֵ��ͬ�����
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
////�����ӡ������
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
//int main()
//{
//    vector<int> vec = { 1,2,2,3,4,4,3 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.isSymmetric(root);
//    return 0;
//}


////7.��������������
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
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�NULL
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
////�����ӡ������
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
//    //��������ݹ鷨
//    int getMaxDepth1(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftdepth = getMaxDepth1(root->left);//��
//        int rightdepth = getMaxDepth1(root->right);//��
//        int depth = 1 + max(leftdepth, rightdepth);//��
//        return depth;
//    }
//    //ǰ������ݹ鷨
//    int result;
//    void getDepth(TreeNode* node, int depth) {
//        result = depth > result ? depth : result;//��
//        if (node->left == NULL && node->right == NULL) return;
//        if (node->left) { //��
//            getDepth(node->left, depth + 1);
//        }
//        if (node->right) { //��
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
//    //�������������
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
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.getMaxDepth3(root);
//    return 0;
//}


////8.����������С���
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
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�NULL
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
////�����ӡ������
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
//    //��������ݹ鷨
//    int getMinDepth1(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftdepth = getMinDepth1(root->left);//��
//        int rightdepth = getMinDepth1(root->right);//��
//        //��
//        if (root->left == NULL && root->right != NULL) {
//            return 1 + rightdepth;
//        }
//        if (root->left != NULL && root->right == NULL) {
//            return 1 + leftdepth;
//        }
//        int result = 1 + min(leftdepth, rightdepth);
//        return result;
//    }
//    //ǰ������ݹ鷨
//    int result;
//    void getDepth(TreeNode* node, int depth) {
//        if (node->left == NULL && node->right == NULL) {//Ҷ�ӽ��
//            result = min(result, depth);
//            return;
//        }
//        //��
//        if (node->left) { //��
//            getDepth(node->left, depth + 1);
//        }
//        if (node->right) { //��
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
//    //�������������
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
//                    return depth;//�ҵ�Ҷ�ӽ��ͷ���
//                }
//            }
//        }
//        return depth;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.getMinDepth1(root);
//    return 0;
//}


////9.��ȫ�������Ľ�����
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
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�NULL
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
////�����ӡ������
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
//    //��������ݹ鷨
//    int getNodesNum1(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftnum = getNodesNum1(root->left);//��
//        int rightnum = getNodesNum1(root->right);//��
//        //��
//        int treeNum = leftnum + rightnum + 1;//
//        return treeNum;
//    }
//    //ǰ������ݹ鷨
//    int result;
//    void getNum(TreeNode* node, int depth) {
//        result++;//��¼�ڵ�����
//        if (node->left == NULL && node->right == NULL) {//Ҷ�ӽ��
//            return;
//        }
//        //��
//        if (node->left) { //��
//            getNum(node->left, depth + 1);
//        }
//        if (node->right) { //��
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
//    //�������������
//    int getNodesNum3(TreeNode* root) {
//        queue<TreeNode*> que;
//        if (root != NULL) que.push(root);
//        int result = 0;
//        while (!que.empty()) {
//            int size = que.size();
//            for (int i = 0; i < size; ++i) {
//                TreeNode* node = que.front();
//                que.pop();
//                result++;//��¼�ڵ�����
//                if (node->left) que.push(node->left);
//                if (node->right) que.push(node->right);
//            }
//        }
//        return result;
//    }
//    //��ȫ��������
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
//        //��������
//        if (leftDepth == rightDepth) {
//            return (2 << leftDepth) - 1; //leftDepth�Ǵ�0��ʼ����
//        }
//        //����������
//        return getNodesNum4(root->left) + getNodesNum4(root->right) + 1;
//    }
//};
//int main()
//{
//    //��֤�����������ȫ������������
//    vector<int> vec = { 1,2,3,4,5,6 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.getNodesNum4(root);
//    return 0;
//}


////10.ƽ�������  
////����ȿ�����ǰ��ͺ��򣬵�����߶Ȳ�����ǰ�����
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
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�NULL
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
////�����ӡ������
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
//    //��������ݹ鷨
//    int getHight(TreeNode* root) {
//        if (root == NULL) return 0;
//        int leftHight = getHight(root->left);//��
//        if (leftHight == -1) return -1;
//        int rightHight = getHight(root->right);//��
//        if (rightHight == -1) return -1;
//        //��
//        return abs(leftHight - rightHight) > 1 ? -1 : 1 + max(leftHight, rightHight);//�����ֵС�ڵ���1���򷵻ص�ǰ�������ĸ߶�
//    }
//    bool isBalanced1(TreeNode* root) {
//        return getHight(root) == -1 ? false : true;
//    }
//    //������
//    int getDepth(TreeNode* cur) {
//        stack<TreeNode*> st;
//        if (cur != NULL) st.push(cur);
//        int depth = 0, result = 0;
//        while (!st.empty()) {
//            TreeNode* node = st.top();
//            if (node != NULL) {
//                st.pop();
//                //ͳһǰ��������� ��������
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
//            //�������
//            if (abs(getDepth(node->left) - getDepth(node->right)) > 1) return false;//��
//            if (node->right) st.push(node->right);//��
//            if (node->left) st.push(node->left);//��
//        }                                         
//        return true;
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    print_binary_tree(root);
//    cout << endl;
//    Solution solution;
//    cout << solution.isBalanced2(root);
//    return 0;
//}


////11.������������·�� (�����㷨)
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
////�������鹹��������
//TreeNode* construct_binary_tree(vector<int> vec) {
//    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
//    TreeNode* root = NULL;
//    //Ϊ������ķ�-1ֵ�������
//    for (int i = 0; i < vec.size(); ++i) {
//        TreeNode* node = NULL;//
//        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�NULL
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
////�����ӡ������
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
//    //������� �ݹ鷨
//    void traversal(TreeNode* cur, vector<int>& path, vector<string>& result) {
//        path.push_back(cur->val);//// �У���Ϊʲôд�������Ϊ���һ���ڵ�ҲҪ���뵽path��
//        if (cur->left == NULL && cur->right == NULL) { //����Ҷ�ӽ��
//            string sPath;
//            for (int i = 0; i < path.size() - 1; ++i) {
//                sPath += to_string(path[i]);
//                sPath += "->";
//            }
//            sPath += to_string(path[path.size() - 1]);
//            result.push_back(sPath);
//            return;
//        }
//        //path.push_back(cur->val);//�У�����������path�ͻ�ȱ���һ�����
//        if (cur->left) {
//            traversal(cur->left, path, result);//��
//            path.pop_back();//����
//        }
//        if (cur->right) {
//            traversal(cur->right, path, result);//��
//            path.pop_back();//����
//        }
//    }
//    vector<string> binaryTreePaths1(TreeNode* root) {
//        vector<string> result;
//        vector<int> path;
//        if (root == NULL) return result;
//        traversal(root, path, result);
//        return result;
//    }
//    //ǰ�����������
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
//    vector<int> vec = { 1,2,3,-1,5 };//������������
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


//12.��Ҷ��֮��
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
//�������鹹��������
TreeNode* construct_binary_tree(vector<int> vec) {
    vector<TreeNode*> vecTree(vec.size(), NULL);//ָ�����飬Ĭ��ֵΪ��
    TreeNode* root = NULL;
    //Ϊ������ķ�-1ֵ�������
    for (int i = 0; i < vec.size(); ++i) {
        TreeNode* node = NULL;//
        if (vec[i] != -1) node = new TreeNode(vec[i]);////-1����սڵ�NULL
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
    //������� �ݹ鷨
    
};
int main()
{
    vector<int> vec = { 1,2,3,-1,5 };//������������
    TreeNode* root = construct_binary_tree(vec);
    Solution solution;
    vector<string> result = solution.binaryTreePaths2(root);
    for (string s : result) {
        cout << s << endl;
    }
    return 0;
}