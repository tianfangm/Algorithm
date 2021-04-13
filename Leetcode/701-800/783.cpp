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
    int minDiffInBST(TreeNode* root) {
        stack<TreeNode*>stk;
        int pre = -1;
        int result = INT_MAX;
        while(root||!stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root=root->left;
            }
            root = stk.top();
            stk.pop();
            if(pre!=-1&&result>root->val-pre)
            {
                result = root->val-pre;
            }
            pre=root->val;
            root = root->right;
        }
        return result;
    }
};
