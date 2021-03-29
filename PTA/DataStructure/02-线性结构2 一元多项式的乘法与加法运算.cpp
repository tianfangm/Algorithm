#include <iostream>

using namespace std;

struct PolyNode;
using pPolyNode = PolyNode*;

struct PolyNode{
    int expon;
    int coef;
    pPolyNode next;
    PolyNode():next(nullptr){}
};

// 插入多项式
void Attach(int c,int e,pPolyNode *p)
{
    pPolyNode temp = new PolyNode();
    temp->coef = c;
    temp->expon = e;
    (*p)->next = temp;
    (*p) = (*p)->next;
}

// 读入多项式
pPolyNode Read()
{
    int n =0;
    pPolyNode head = new PolyNode();
    pPolyNode pHead = head;
    scanf("%d",&n);
    for(int i =0;i<n;++i)
    {
        int c,e;
        scanf("%d %d",&c,&e);
        Attach(c,e,&head);
    }
    return pHead->next;
}

// 多项式加法
pPolyNode AddPoly(pPolyNode p1,pPolyNode p2)
{
    pPolyNode head = new PolyNode();
    pPolyNode pHead = head;
    while(p1&&p2)
    {
        if(p1->expon==p2->expon)
        {
            int sum = p1->coef+p2->coef;
            if(sum)
            {
                Attach(sum,p1->expon,&head);
            }
            p1=p1->next;
            p2=p2->next;
        }
        else if(p1->expon>p2->expon)
        {
            Attach(p1->coef,p1->expon,&head);
            p1=p1->next;
        }
        else
        {
            Attach(p2->coef,p2->expon,&head);
            p2=p2->next;
        }
    }
    head->next = p1?p1:p2;
    return pHead->next;
}

// 多项式乘法
pPolyNode MulPoly(pPolyNode p1,pPolyNode p2)
{
    pPolyNode head = new PolyNode();
    pPolyNode pHead = head;
    pPolyNode ret = nullptr;
    
    while(p1)
    {
        pPolyNode p = p2;
        while(p)
        {
            Attach(p->coef*p1->coef,p->expon+p1->expon,&head);
            p=p->next;
        }
        ret = AddPoly(pHead->next,ret);
        head = pHead;
        p1=p1->next;
    }
    
    return ret;
}

// 打印多项式
void Print(pPolyNode p)
{
    if(!p)
    {
        printf("0 0");
    }
    while(p)
    {
        printf("%d %d",p->coef,p->expon);
        if(p->next)
        {
            printf(" ");
        }
        p=p->next;
    }
    printf("\n");
}

//  main
int main()
{
    pPolyNode p1 = Read();
    pPolyNode p2 = Read();

    pPolyNode pMul = MulPoly(p1,p2);
    
    Print(pMul);
    
    pPolyNode pAdd = AddPoly(p1,p2);
    
    Print(pAdd);
    
    return 0;
}
