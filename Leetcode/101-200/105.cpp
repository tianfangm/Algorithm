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
    unordered_map<int,int> hashMap;
public:
    TreeNode* createTree(const vector<int>&preorder,int preLeft,int preRight,int inLeft,int inRight)
    {
        if(inLeft>inRight)
        {
            return nullptr;
        }    

        int val = preorder[preLeft];

        TreeNode* root = new TreeNode(val);

        int inMid = hashMap[val];

        int length = inMid - inLeft;

        root->left = createTree(preorder,preLeft+1,preLeft+length,inLeft,inMid-1);

        root->right = createTree(preorder,preLeft+length+1,preRight,inMid+1,inRight);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size();
        for(int i =0;i<n;++i)
        {
            hashMap[inorder[i]] = i;
        }
        return createTree(preorder,0,n-1,0,n-1);
    }
};
