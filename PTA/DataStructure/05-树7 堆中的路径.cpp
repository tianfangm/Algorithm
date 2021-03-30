#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

void Print(int n,const vector<int>&vec)
{
    while(n!=0)
    {
        printf("%d",vec[n]);
        n/=2;
        if(n!=0)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void InsertHeap(vector<int>&heap,int num)
{
    heap.push_back(num);
    int n = heap.size() - 1;
    while(heap[n/2]>num)
    {
        heap[n] = heap[n/2];
        n/=2;
    }
    heap[n] = num;
}

int main()
{
    vector<int> heap{INT_MIN};
    
    int n = 0, m = 0;
    scanf("%d %d",&n,&m);
    
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        InsertHeap(heap,num);
    }
    
    for(int i = 0;i<m;++i)
    {
        int num = 0;
        scanf("%d",&num);
        Print(num,heap);
    }
    
    return 0;
}
