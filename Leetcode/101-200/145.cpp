/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stk;
        vector<int> result;
        TreeNode *prev = nullptr;
        while(root||!stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            if(!root->right||prev == root->right)
            {
                prev = root;
                result.push_back(root->val);
                root = nullptr;
            }
            else
            {
                stk.push(root);
                root = root->right;
            }
        }
        return result;
    }
};
