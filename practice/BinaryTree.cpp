//1.�������ĵݹ����
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
    

};
int main()
{

    return 0;
}


//2.�������ĵ�������


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