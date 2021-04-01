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
    int recur(TreeNode* node)
    {
        if(node==nullptr)
        {
            return 0;
        }
        int left = recur(node->left);
        if(left==-1)
        {
            return -1;
        }
        int right = recur(node->right);
        if(right==-1)
        {
            return -1;
        }
        return abs(left-right)<2?max(left,right)+1:-1;
    }
    bool isBalanced(TreeNode* root) {
        return recur(root)!=-1;
    }
};
