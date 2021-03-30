#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node{
    int val;
    int left,right;
    Node(){}
    Node(int c,int l,int r):val(c),left(l),right(r){}
};

void LevelTraversal(vector<Node>tree,int root,vector<int>&result)
{
    queue<int> q;
    q.push(root);
    while(!q.empty())
    {
        int n = q.size();
        for(int i =0;i<n;++i)
        {
            int Tmp = q.front();
            q.pop();
            if((tree[Tmp].left)!=-1)
                q.push(tree[Tmp].left);
            if((tree[Tmp].right)!=-1)
                q.push(tree[Tmp].right);
            if((tree[Tmp].right)==-1&&(tree[Tmp].left)==-1)
            {
                result.push_back(tree[Tmp].val);
            }
        }
    }
}

int CreateTree(vector<Node>&tree)
{
    int n = 0;
    int ret = -1;

    scanf("%d",&n);
    
    vector<int> root(n,1);
    
    for(int i =0;i<n;++i)
    {
        Node node;
        char l,r;
        node.val = i;
        scanf("\n%c %c",&l,&r);
        if(l=='-')
        {
            node.left = -1;
        }
        else
        {
            node.left = l-'0';
            root[l-'0']=0;
        }
        if(r=='-')
        {
            node.right = -1;
        }
        else
        {
            node.right = r-'0';
            root[r-'0']=0;
        }
        tree.emplace_back(node);
    }
    
    for(int i =0;i<n;++i)
    {
        if(root[i])
        {
            ret = i;
            break;
        }
    }
    
    return ret;
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

int main()
{
    int root;
    vector<Node> tree;
    vector<int> result;
    
    root = CreateTree(tree);
    
    LevelTraversal(tree,root,result);
    
    Print(result);
    
    return 0;
}
