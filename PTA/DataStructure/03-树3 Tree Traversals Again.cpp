#include <iostream>
#include <unordered_map>
#include <stack>
#include <string>
#include <vector>

using namespace std;

unordered_map<int,int> hashMap;

using Tree = struct TreeNode*;
struct TreeNode{
    int val;
    Tree left,right;
};

// 后序遍历
void PostOrder(Tree root,vector<int>&postorder)
{
    stack<Tree> stk;
    Tree node = root,prev = nullptr;
    while(node||!stk.empty())
    {
        while(node)
        {
            stk.push(node);
            node = node->left;
        }
        node = stk.top();
        stk.pop();
        if(node->right==nullptr||node->right == prev)
        {
            postorder.push_back(node->val);
            prev = node;
            node = nullptr;
        }
        else
        {
            stk.push(node);
            node = node->right;
        }
    }
}

// 构建树
Tree CreateTree(const vector<int>&preorder,int preLeft,int preRight,int inLeft,int inRight)
{
    if(inLeft>inRight)
    {
        return nullptr;
    }
    else
    {
        Tree root = new TreeNode();
        
        root->val = preorder[preLeft];
        
        int inMid = hashMap[preorder[preLeft]];
        
        int length = inMid - inLeft;
        
        root->left = CreateTree(preorder,preLeft+1,preLeft+length,inLeft,inMid - 1);
        
        root->right = CreateTree(preorder,preLeft+length+1,preRight,inMid+1,inRight);
        
        return root;
    }
}

// 读入
int Read(vector<int>&preorder)
{
    vector<int> inorder;
    stack<int> stk;
    int n = 0;
    scanf("%d",&n);
    for(int i =0;i<2*n;++i)
    {
        string op;
        cin>>op;
        if(op[1]=='u')
        {
            int num = 0;
            scanf("%d",&num);
            stk.push(num);
            preorder.push_back(num);
        }
        else
        {
            inorder.push_back(stk.top());
            stk.pop();
        }
    }
    for(int i =0;i<n;++i)
    {
        hashMap[inorder[i]]=i;
    }
    return n;
}

// 打印
void Print(const vector<int>&vec)
{
    int n = vec.size();
    for(int i =0;i<n;++i)
    {
        printf("%d",vec[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

//
int main()
{
    vector<int> preorder;
    vector<int> postorder;
    
    int n = Read(preorder);

    Tree root = CreateTree(preorder,0,n-1,0,n-1);
    
    PostOrder(root,postorder);
    
    Print(postorder);
    
    return 0;
}
