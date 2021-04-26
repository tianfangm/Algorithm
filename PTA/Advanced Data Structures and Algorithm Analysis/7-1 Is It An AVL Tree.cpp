#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

using pNode = struct node*;
struct node{
    int val;
    int height;
    pNode left,right;
    node():val(0),height(0),left(nullptr),right(nullptr){}
    node(int v):val(v),height(0),left(nullptr),right(nullptr){}
};

int flag = true;
unordered_map<int,int> hashMap;

pNode create(vector<int>&preorder,int preLeft,int preRight,int inLeft,int inRight)
{
    if(inLeft>inRight)
    {
        return nullptr;
    }
    
    int num = preorder[preLeft];
    
    pNode root = new node(num);
    
    int inMid = hashMap[num];
    
    int length = inMid-inLeft;
    
    root->left = create(preorder,preLeft+1,preLeft+length,inLeft,inMid-1);
    
    root->right = create(preorder,preLeft+length+1,preRight,inMid+1,inRight);
    
    return root;
}

void dfs(pNode root,int height)
{
    if(!root)
    {
        return;
    }
    root->height = height;
    dfs(root->left,height+1);
    dfs(root->right,height+1);
}

void getMaxHeight(pNode root,int &maxHeight)
{
    if(root->height>=maxHeight)
    {
        maxHeight = root->height;
    }
    if(root->left)getMaxHeight(root->left,maxHeight);
    if(root->right)getMaxHeight(root->right,maxHeight);
}

void judge(pNode root)
{
    int lheight = root->height,rheight = root->height;
    if(root->left)getMaxHeight(root->left,lheight);
    if(root->right)getMaxHeight(root->right,rheight);
    if(abs(lheight-rheight)>1)
    {
        flag = false;
    }
    if(root->left)judge(root->left);
    if(root->right)judge(root->right);
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    for(int i = 0;i<n;++i)
    {
        int m = 0;
        flag = true;
        scanf("%d",&m);
        vector<int>preorder;
        vector<int>inorder;
        for(int j = 0;j<m;++j)
        {
            int num = 0;
            scanf("%d",&num);
            preorder.push_back(num);
            inorder.push_back(num);
        }
        // 获得中序遍历
        sort(inorder.begin(),inorder.end());
        
        for(int j = 0;j<m;++j)
        {
            hashMap[inorder[j]]=j;
        }
        // 构建树
        pNode root = create(preorder,0,m-1,0,m-1);
        // 遍历获得树的高度
        dfs(root,1);
        // 判断
        judge(root);
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
