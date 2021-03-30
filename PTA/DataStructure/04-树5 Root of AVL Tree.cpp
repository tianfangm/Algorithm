#include <iostream>
#include <algorithm>

using namespace std;

using Tree = struct TreeNode*;
struct TreeNode
{
    int val;
    Tree left,right;
    int height;
    TreeNode():height(1){}
    TreeNode(int v):val(v),left(nullptr),right(nullptr),height(1){}
};

int getHeight(Tree node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return node->height;
}

int GetBalanceFactor(Tree node)
{
    if(node==nullptr)
    {
        return 0;
    }
    return getHeight(node->left)-getHeight(node->right);
}

int GetTreeHeight(Tree node)
{
    if(node == nullptr)
    {
        return 0;
    }
    return max(getHeight(node->left),getHeight(node->right))+1;
}

// LL,LR,RL,RR四种旋转

Tree LLRotate(Tree root)
{
    Tree Tmp = root->left;
    
    Tree Tmp1 = Tmp->right;
    
    Tmp->right = root;
    
    root->left = Tmp1;
    
    root->height = GetTreeHeight(root);
    Tmp->height = GetTreeHeight(Tmp);
    
    return Tmp;
}

Tree RRRotate(Tree root)
{
    Tree Tmp = root->right;
    
    Tree Tmp1 = Tmp->left;
    
    Tmp->left = root;
    
    root->right = Tmp1;
    
    root->height = GetTreeHeight(root);
    Tmp->height = GetTreeHeight(Tmp);
    
    return Tmp;
}


Tree Insert(Tree root,int v)
{
    if(!root)
    {
        root = new TreeNode(v);
    }
    else
    {
        if(root->val>v)
        {
            root->left = Insert(root->left,v);
        }
        else if(root->val<v)
        {
            root->right = Insert(root->right,v);
        }
        
        root-> height = max(getHeight(root->left),getHeight(root->right)) + 1;
        
        int balanceFactor = GetBalanceFactor(root);
        
        if(balanceFactor>1&&GetBalanceFactor(root->left)>0)
        {
            return LLRotate(root);
        }
        if(balanceFactor<-1&&GetBalanceFactor(root->right)<0)
        {
            return RRRotate(root);
        }
        if(balanceFactor>1&&GetBalanceFactor(root->left)<0)
        {
            root->left = RRRotate(root->left);
            return LLRotate(root);
        }
        if(balanceFactor<-1&&GetBalanceFactor(root->right)>0)
        {
            root->right = LLRotate(root->right);
            return RRRotate(root);
        }
    }
    return root;
}

int main()
{
    int n =0;
    scanf("%d",&n);
    
    Tree tree = nullptr;
    
    for(int i =0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        
        tree = Insert(tree,num);
    }
    
    printf("%d\n",tree->val);
    
    return 0;
}
