// 比较根节点，及其左右子树
#include <iostream>

using namespace std;

using Tree = struct TreeNode*;
struct TreeNode{
    int v;
    Tree Left,Right;
    // 判断是否被访问过
    int flag;
};

Tree NewNode(int v)
{
    Tree T = new TreeNode();
    T->v = v;
    T->Left = T->Right = nullptr;
    T->flag = 0;
    return T;
}

Tree Insert(Tree T, int v)
{
    if(!T)
    {
        T = NewNode(v);
    }
    else
    {
        if(v>T->v)
        {
            T->Right = Insert(T->Right,v);
        }
        else
        {
            T->Left = Insert(T->Left,v);
        }
    }
    return T;
}

Tree MakeTree(int n)
{
    Tree T;
    
    int v;
    // 创建新结点
    scanf("%d",&v);
        
    T = NewNode(v);
    // 插入结点
    for(int i =1;i<n;++i)
    {
        scanf("%d",&v);
        T = Insert(T,v);
    }
    
    return T;
}

bool check(Tree T,int v)
{
    if(T->flag)
    {
        if(v<T->v)
        {
            return check(T->Left,v);
        }
        else if(v>T->v)
        {
            return check(T->Right,v);
        }
        else
        {
            return false;
        }
    }
    else
    {
        if(v==T->v)
        {
            T->flag = 1;
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool Judge(Tree T,int n)
{
    bool result = true;
    int v;
    scanf("%d",&v);
    if(v!=T->v)
    {
        result = false;
    }
    else
    {
        T->flag = 1;
    }

    for(int i =1;i<n;++i)
    {
        scanf("%d",&v);
        
        if(result&&!check(T,v))
        {
            result = false;
        }
    }
    return result;
}

void ResetT(Tree T)
{
    if(T->Left)ResetT(T->Left);
    if(T->Right)ResetT(T->Right);
    T->flag = 0;
}

void FreeTree(Tree T)
{
    if(T->Left)FreeTree(T->Left);
    if(T->Right)FreeTree(T->Right);
    delete T;
}

int main()
{
    // 读入n和l
    int n,l;
    Tree T;
    scanf("%d",&n);
    while(n)
    {
        scanf("%d",&l);
        // 根据第一行序列建树T
        T = MakeTree(n);
        for(int i =0;i<l;++i)
        {
            // 判断树
            printf("%s\n",Judge(T,n)?"Yes":"No");
            ResetT(T);
        }
        FreeTree(T);
        scanf("%d",&n);
    }

    return 0;
}
