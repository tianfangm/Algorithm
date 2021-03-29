#include <iostream>
#include <vector>

using namespace std;

struct Node{
    char val;
    int left,right;
    Node(){}
    Node(char c,int l,int r):val(c),left(l),right(r){}
};

int CreateTree(vector<Node>&tree)
{
    int n = 0;
    int ret = -1;

    scanf("%d",&n);
    
    vector<int> root(n,1);
    
    for(int i =0;i<n;++i)
    {
        Node node;
        char v,l,r;
        scanf("\n%c %c %c",&(node.val),&l,&r);
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

bool Isomorphic(const vector<Node>&tree1,const vector<Node>&tree2,const int &root1,const int &root2)
{
    // 12树均为空
    if(root1==-1&&root2==-1)
    {
        return true;
    }
    // 1树空2树非空 或者 1树非空2树空
    if((root1==-1&&root2!=-1)||(root1!=-1&&root2==-1))
    {
        return false;
    }
    // 1树根值不等于2树根值
    if(tree1[root1].val!=tree2[root2].val)
    {
        return false;
    }
    // 1树左子树空且2树左子树空，递归查找各自右子树
    if((tree1[root1].left==-1)&&tree2[root2].left==-1)
    {
        return Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].right);
    }
    // 1树左子树非空且2树左子树非空 且 各自子树值相同，递归查找左右子树，否则交换左右子树查找
    if(((tree1[root1].left!=-1)&&(tree2[root2].left!=-1))&&(tree1[tree1[root1].left].val==tree2[tree2[root2].left].val))
    {
        return (Isomorphic(tree1,tree2,tree1[root1].left,tree2[root2].left)&&Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].right));
    }
    else
    {
        return (Isomorphic(tree1,tree2,tree1[root1].left,tree2[root2].right)&&Isomorphic(tree1,tree2,tree1[root1].right,tree2[root2].left));
    }
    
}

int main()
{
    int root1,root2;
    vector<Node> tree1;
    vector<Node> tree2;
    
    root1 = CreateTree(tree1);
    root2 = CreateTree(tree2);
    
    printf("%s\n",Isomorphic(tree1,tree2,root1,root2)?"Yes":"No");
    
    return 0;
}
