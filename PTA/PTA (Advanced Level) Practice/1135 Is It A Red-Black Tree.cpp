#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

using pNode = struct node*;
struct node{
    int color;// 1 black 2 red
    int val;
    pNode left,right;
    node(int c,int v):color(c),val(v),left(nullptr),right(nullptr){}
};

bool flag = true;

pNode buildTree(pNode root,int val)
{
    if(root==nullptr)
    {
        int color = val>0?1:2;
        root = new node(color,abs(val));
    }
    else if(abs(val)>root->val)
    {
        root->right = buildTree(root->right,val);
    }
    else if(abs(val)<root->val)
    {
        root->left = buildTree(root->left,val);
    }
    return root;
}

void dfs(pNode root,int height,int &maxHeight)
{
    // 到达根节点时，bh大小不相等
    if(root==nullptr)
    {
        height+=1;
        if(maxHeight!=height)
        {
            flag = false;
        }
        return;
    }
    int bh = root->color==1?1:0;
    dfs(root->left,height+bh,maxHeight);
    dfs(root->right,height+bh,maxHeight);
}

void judge(pNode root,int preColor)
{
    if(preColor==2&&root->color==2)
    {
        flag = false;
        return;
    }
    int maxHeight = 0;
    pNode temp = root;
    while(temp)
    {
        if(temp->color==1)
        {
            maxHeight+=1;
        }
        temp = temp->left;
    }
    maxHeight+=1;
    dfs(root,0,maxHeight);
    if(root->left)judge(root->left,root->color);
    if(root->right)judge(root->right,root->color);
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    while(n>0)
    {
        int m = 0;
        scanf("%d",&m);
        pNode root = nullptr;
        for(int i =0;i<m;++i)
        {
            int num = 0;
            scanf("%d",&num);
            root = buildTree(root,num);
        }
        
        if(root->color==2)
        {
            flag = false;
        }
        
        judge(root,1);
        
        if(flag)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
        
        flag = true;
        n-=1;
    }
    return 0;
}
