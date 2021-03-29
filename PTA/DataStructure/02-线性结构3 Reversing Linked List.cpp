#include <iostream>
#include <unordered_map>

using namespace std;

struct Node;
using pNode = Node*;

struct Node{
    int address,next;
    int val;
    pNode nex;
    Node():nex(nullptr){}
    Node(int a,int v,int n):address(a),val(v),next(n),nex(nullptr){}
};

// 读入地址
pNode Read(int &k)
{
    int start,n;
    
    unordered_map<int,pNode> hashMap;
    
    scanf("%d %d %d",&start,&n,&k);
    
    for(int i =0;i<n;++i)
    {
        int a,v,next;
        scanf("%d %d %d",&a,&v,&next);
        hashMap[a] = new Node(a,v,next);
    }
    
    pNode head = new Node(),pHead = head;

    while(start!=-1)
    {
        head->nex = hashMap[start];
        head = head->nex;
        start = hashMap[start]->next;
    }
    
    return pHead->nex;
}

// 翻转
pair<pNode,pNode> ReverseK(pNode head,pNode tail)
{
    pNode prev = tail->nex, cur = head;
    while(prev!=tail)
    {
        pNode temp = cur->nex;
        if(prev)
        {
            cur->next = prev->address;
        }
        cur->nex = prev;
        prev = cur;
        cur = temp;
    }
    return {tail,head};
}

pNode Reverse(pNode head,const int k)
{
    pNode pHead  = new Node(),cur = pHead;
    pHead ->nex = head;
    
    while(head)
    {
        int cnt = 1;
        pNode tail = head;
        while(tail&&cnt<k)
        {
            tail = tail->nex;
            cnt+=1;
        }
        if(!tail||cnt<k)
        {
            break;
        }
        pair<pNode,pNode>result = ReverseK(head,tail);
        cur->nex = result.first;
        cur->next = result.first->address;
        cur = result.second;
        head = cur->nex;
    }
    return pHead->nex;
}

// 打印
void Print(pNode p)
{
    while(p)
    {
        printf("%05d %d",p->address,p->val);
        if(p->nex)
        {
            printf(" %05d\n",p->next);
        }
        else
        {
            printf(" -1\n");
        }
        p=p->nex;
    }
}

int main()
{
    int k = 0;
    
    pNode p = Read(k);
    
    p = Reverse(p,k);
    
    Print(p);
    
    return 0;
}
