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
//    //ǰ����� �ݹ鷨
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


////12.��Ҷ��֮��
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
//class Solution {
//public:
//    //������� �ݹ鷨
//    int sumOfLeftLeaves1(TreeNode* root) {
//        if (root == NULL) return 0;
//        if (root->left == NULL && root->right == NULL) return 0;
//        int leftValue = sumOfLeftLeaves1(root->left);//��
//        if (root->left && !root->left->left && !root->left->right) {
//            leftValue = root->left->val;//
//        }
//        int rightValue = sumOfLeftLeaves1(root->right);//��
//        int sum = leftValue + rightValue;//��
//        return sum;
//    }
//    //ǰ����� ������
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
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.sumOfLeftLeaves2(root);
//    return 0;
//}


////13.�������½ǵ�ֵ
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
//class Solution {
//public:
//    //ǰ����� �ݹ鷨
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
//    //������� ������
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
//    vector<int> vec = { 3,9,20,-1,-1,15,7 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    Solution solution;
//    cout << solution.findBottomLeftValue1(root);
//    return 0;
//}


////!14.������ͺ���������й��������
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
//	TreeNode* traversal(vector<int>& invec, vector<int>& postvec) {
//		//1 ��������СΪ��Ļ���˵���ǿսڵ�
//		if (postvec.size() == 0) return NULL;
//		//2 �����Ϊ�գ���ôȡ�����������һ��Ԫ����Ϊ�ڵ�Ԫ��
//		int rootValue = postvec[postvec.size() - 1];//
//		TreeNode* root = new TreeNode(rootValue);
//		if (postvec.size() == 1) return root;////
//		//3 �ҵ������������һ��Ԫ�������������λ�ã���Ϊ�и��
//		int delimiterIndex;
//		for (delimiterIndex = 0; delimiterIndex < invec.size(); ++delimiterIndex) {
//			if (invec[delimiterIndex] == rootValue) break;
//		}
//		//4 �и���������
//		vector<int> leftInvec(invec.begin(), invec.begin() + delimiterIndex);
//		vector<int> rightInvec(invec.begin() + delimiterIndex + 1, invec.end());
//		//5 �и��������
//		postvec.resize(postvec.size() - 1);
//		vector<int> leftPostvec(postvec.begin(), postvec.begin() + leftInvec.size());
//		vector<int> rightPostvec(postvec.begin() + leftPostvec.size(), postvec.end());
//		//6 �ݹ鴦���������������
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
//	vector<int> invec = { 9,3,15,20,7 };//��������
//	vector<int> postvec = { 9,15,7,20,3 };//��������
//	Solution solution;
//	print_binary_tree(solution.buildTree(invec, postvec));
//	return 0;
//}


////!15.��ǰ�������������й��������
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
////�����ӡ������
//void print_binary_tree(TreeNode* root) {
//	queue<TreeNode*> que;
//	if (root != NULL) que.push(root);//
//	vector<vector<int>> result;
//	while (!que.empty()) {
//		vector<int> vec;
//		int size = que.size();//������ÿ��Ľ����
//		for (int i = 0; i < size; ++i) {
//			TreeNode* node = que.front();
//			que.pop();
//			if (node != NULL) {
//				vec.push_back(node->val);
//				que.push(node->left);
//				que.push(node->right);
//			}
//			else vec.push_back(-1);//�ս���ʾΪ-1
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
//		//1 ��������СΪ��Ļ���˵���ǿսڵ�
//		if (prevecBegin == prevecEnd) return NULL;
//		//2 �����Ϊ�գ���ôȡ�����������һ��Ԫ����Ϊ�ڵ�Ԫ��
//		int rootValue = prevec[prevecBegin];//
//		TreeNode* root = new TreeNode(rootValue);
//		if (prevecEnd - prevecBegin == 1) return root;////
//		//3 �ҵ������������һ��Ԫ�������������λ�ã���Ϊ�и��
//		int delimiterIndex;
//		for (delimiterIndex = invecBegin; invecBegin < invecEnd; ++delimiterIndex) {
//			if (invec[delimiterIndex] == rootValue) break;
//		}
//		//4 �и���������
//		int leftInvecBegin = invecBegin;
//		int leftInvecEnd = delimiterIndex;
//		int rightInvecBegin = delimiterIndex + 1;
//		int rightInvecEnd = invecEnd;
//		//5 �и�ǰ������
//		int leftPrevecBegin = prevecBegin + 1;
//		int leftPrevecEnd = prevecBegin + 1 + (delimiterIndex - invecBegin);
//		int rightPrevecBegin = prevecBegin + 1 + (delimiterIndex - invecBegin);
//		int rightPrevecEnd = prevecEnd;
//		//6 �ݹ鴦���������������
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
//	vector<int> prevec = { 3,9,20,15,7 };//��������
//	vector<int> invec = { 9,3,15,20,7 };//��������
//	Solution solution;
//	print_binary_tree(solution.buildTree(prevec, invec));
//	return 0;
//}


////16.��������
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
////�����ӡ������
//void print_binary_tree(TreeNode* root) {
//	queue<TreeNode*> que;
//	if (root != NULL) que.push(root);//
//	vector<vector<int>> result;
//	while (!que.empty()) {
//		vector<int> vec;
//		int size = que.size();//������ÿ��Ľ����
//		for (int i = 0; i < size; ++i) {
//			TreeNode* node = que.front();
//			que.pop();
//			if (node != NULL) {
//				vec.push_back(node->val);
//				que.push(node->left);
//				que.push(node->right);
//			}
//			else vec.push_back(-1);//�ս���ʾΪ-1
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
//		// ���ֵ���ڵ��±������� ����������
//		if (maxValueIndex > 0) {
//			vector<int> newVec(vec.begin(), vec.begin() + maxValueIndex);
//			node->left = traversal(newVec);
//		}
//		// ���ֵ���ڵ��±������� ����������
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
//	vector<int> prevec = { 3,2,1,6,0,5 };//���ظ�����
//	Solution solution;
//	print_binary_tree(solution.buildTree(prevec));
//	return 0;
//}


////17.�ϲ�������
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
//	queue<TreeNode*> que;
//	if (root != NULL) que.push(root);//
//	vector<vector<int>> result;
//	while (!que.empty()) {
//		vector<int> vec;
//		int size = que.size();//������ÿ��Ľ����
//		for (int i = 0; i < size; ++i) {
//			TreeNode* node = que.front();
//			que.pop();
//			if (node != NULL) {
//				vec.push_back(node->val);
//				que.push(node->left);
//				que.push(node->right);
//			}
//			else vec.push_back(-1);//�ս���ʾΪ-1
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
//    //ǰ����� �ݹ鷨
//    TreeNode* mergeTree1(TreeNode* root1, TreeNode* root2) {
//        if (root1 == NULL) return root2;
//        if (root2 == NULL) return root1;
//        TreeNode* root = new TreeNode(0);
//        root->val = root1->val + root2->val;
//        root->left = mergeTree1(root1->left, root2->left);
//        root->right= mergeTree1(root1->right, root2->right);
//        return root;
//    }
//    //������
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


////!18.���������������� (�������)���������������ݹ�����͵�����������ͨ����������һ����
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
//    //�ݹ鷨
//    TreeNode* searchBST1(TreeNode* root, int val) {
//        if (root == NULL || root->val == val) return root;
//        TreeNode* result = NULL;
//        if (root->val > val) result = searchBST1(root->left, val);
//        if (root->val < val) result = searchBST1(root->right, val);
//        return result;
//    }
//    //������ ��������������Ҫ���ݣ����Բ���ջ�Ͷ��оͿ�������ֵ
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


////19.��֤����������
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
//class Solution {
//public:
//    //����ݹ鷨
//    vector<int> vec;
//    void traversal(TreeNode* root) {
//        if (root == NULL) return;
//        traversal(root->left);
//        vec.push_back(root->val);//��
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
//    //�ݹ鷨2 ���ݹ�����Ĺ�����ֱ���ж��Ƿ�����
//    long long maxVal = LONG_MIN; //������������int��Сֵ
//    bool isValidBST2(TreeNode* root) {
//        if (root == NULL) return true;
//        bool left = isValidBST2(root->left);
//        //�����������֤������Ԫ���ǲ��Ǵ�С����
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


////20.��������������С���Բ�
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
//class Solution {
//public:
//    //����ݹ鷨
//    vector<int> vec;
//    void traversal(TreeNode* root) {
//        if (root == NULL) return;
//        traversal(root->left);
//        vec.push_back(root->val);//��
//        traversal(root->right);
//    }
//    int getMinimumDifference1(TreeNode* root) {
//        vec.clear();
//        traversal(root);//���������������
//        if (vec.size() < 2) return 0;
//        int result = INT_MAX;
//        for (int i = 1; i < vec.size(); ++i) {
//            result = min(result, vec[i] - vec[i - 1]);
//        }
//        return result;
//    }
//    //����ݹ鷨 ������������ֱ�Ӽ��㣩
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
//        traversa2(root);//���������������
//        return result;
//    }
//    //���������
//    int getMinimumDifference3(TreeNode* root) {
//        stack<TreeNode*> st;
//        TreeNode* cur = root;
//        TreeNode* pre = NULL;
//        int result = INT_MAX;
//        while (cur != NULL || !st.empty()) {
//            if (cur != NULL) {
//                st.push(cur);
//                cur = cur->left; //��
//            }
//            else {
//                cur = st.top();
//                st.pop();
//                if (pre != NULL) { //��
//                    result = min(result, cur->val - pre->val);
//                }
//                pre = cur;
//                cur = cur->right; //��
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


////20.�����������е�����
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
//class Solution1 {
//private:
//
//    void searchBST(TreeNode* cur, unordered_map<int, int>& map) { // ǰ�����
//        if (cur == NULL) return;
//        map[cur->val]++; // ͳ��Ԫ��Ƶ��
//        searchBST(cur->left, map);
//        searchBST(cur->right, map);
//        return;
//    }
//    bool static cmp(const pair<int, int>& a, const pair<int, int>& b) {
//        return a.second > b.second;
//    }
//public:
//    vector<int> findMode(TreeNode* root) {
//        unordered_map<int, int> map; // key:Ԫ�أ�value:����Ƶ��
//        vector<int> result;
//        if (root == NULL) return result;
//        searchBST(root, map);
//        vector<pair<int, int>> vec(map.begin(), map.end());//
//        sort(vec.begin(), vec.end(), cmp); // ��Ƶ���Ÿ���
//        result.push_back(vec[0].first);////
//        for (int i = 1; i < vec.size(); i++) {
//            // ȡ��ߵķŵ�result������
//            if (vec[i].second == vec[0].second) result.push_back(vec[i].first);
//            else break;
//        }
//        return result;
//    }
//};
////�ݹ鷨
//class Solution2 {
//private:
//    int maxCount = 0;
//    int count = 0;
//    TreeNode* pre = NULL;
//    vector<int> result;
//    void searchBST(TreeNode* cur) { // ǰ�����
//        if (cur == NULL) return;
//        searchBST(cur->left);//��
//        if (pre == NULL) { //��
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
//        searchBST(cur->right);//��
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
////������
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
//    vector<int> vec = { 1,-1,2,-1,-1,2 };//������������
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


////21.�������������������
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
////��������ݹ鷨
//class Solution1 {
//public:
//    TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
//        if (root->val == q || root->val == p || root == NULL) return root;//��ֹ����
//        TreeNode* left = lowestCommonAncestor(root->left, p, q);
//        TreeNode* right = lowestCommonAncestor(root->right, p, q);
//        if (left != NULL && right != NULL) return root;
//        if (left == NULL) return right;//
//        return left;//
//    }
//};
//int main()
//{
//    vector<int> vec = { 3,5,1,6,2,0,8,-1,-1,7,4 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    Solution1 solution;
//    int q = 5, p = 1;
//    cout << solution.lowestCommonAncestor(root, p, q)->val;
//    return 0;
//}


////22.�����������������������
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
////�ݹ鷨
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
////������
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
//    vector<int> vec = { 6,2,8,0,4,7,9,-1,-1,3,5 };//������������
//    TreeNode* root = construct_binary_tree(vec);
//    Solution2 solution;
//    int q = 2, p = 8;
//    cout << solution.lowestCommonAncestor(root, p, q)->val;
//    return 0;
//}


////23.�����������еĲ������
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
////�ݹ鷨
//class Solution1 {
//public:
//    //д��һ
//    TreeNode* insertBST(TreeNode* root, int val) {
//        if (root == NULL) {//��ֹ����
//            TreeNode* node = new TreeNode(val);
//            return node;//���ؽ��
//        }
//        if (root->val > val) root->left = insertBST(root->left, val);
//        if (root->val < val) root->right = insertBST(root->right, val);
//        return root;
//    }
//    //д����
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
//    //������
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


////24.ɾ�������������еĽڵ�
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
//class Solution1 {
//public:
//    //��ͨ��������ɾ����ʽ
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
//    //�ݹ鷨
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
//    //������
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
//        // pre Ҫ֪����ɾ���ӻ����Һ���
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


////25.�޼�����������
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
//class Solution1 {
//public:
//    //�ݹ鷨
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
//    //������
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


////26.����������ת��Ϊ�߶�ƽ�����������
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
//class Solution1 {
//public:
//    //�ݹ鷨
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


////27.�Ѷ���������ת��Ϊ�ۼ���
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
////�ݹ鷨 (���������)
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
////������
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