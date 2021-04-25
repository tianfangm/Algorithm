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
// 暂存
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*>stk;
        queue<TreeNode*>q;
        while(root||!stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            q.push(root);
            if(root->right)
            {
                root = root->right;
            }
            else
            {
                root = nullptr;
            }
        }
        TreeNode*head = new TreeNode();
        root = head;
        while(!q.empty())
        {
            head->right = q.front();
            q.pop();
            head = head->right;
            head->left = nullptr;
            head->right = nullptr;
        }
        return root->right;
    }
};

//直接修改
class Solution {
public:
    TreeNode* increasingBST(TreeNode* root) {
        stack<TreeNode*>stk;
        TreeNode *head = new TreeNode(),*pHead = head;
        while(root||!stk.empty())
        {
            while(root)
            {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            head->right = root;
            head = head->right;
            head->left = nullptr;
            if(root->right)
            {
                root = root->right;
            }
            else
            {
                root = nullptr;
            }
        }
        return pHead->right;
    }
};
