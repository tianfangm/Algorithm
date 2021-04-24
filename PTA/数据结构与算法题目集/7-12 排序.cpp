#include <iostream>
#include <vector>

using namespace std;

// 输出
void Print(const vector<int>&vec)
{
    int n = vec.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",vec[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

// -----------------------------------冒泡排序-----------------------------------
void bubble_sort(vector<int>&nums)
{
    int N = nums.size();

    for(int P = N;P>1;--P)
    {
        int flag = 0;
        for(int i = 1;i<P;++i)
        {
            if(nums[i-1]>nums[i])
            {
                swap(nums[i-1],nums[i]);
                flag = 1;
            }
        }
        if(flag==0)
        {
            break;
        }
    }
}

// -----------------------------------插入排序-----------------------------------
void insert_sort(vector<int>&nums)
{
    int n = nums.size();
    for(int p = 1;p<n;++p)
    {
        int temp = nums[p];
        int i = p;
        for(;i>=1&&nums[i-1]>temp;--i)
        {
            nums[i]=nums[i-1];
        }
        nums[i]=temp;
    }
}

// -----------------------------------希尔排序-----------------------------------
void shell_sort(vector<int>&nums)
{
    // Hibbard增量序列
    // Dk=2^k-1
    // Sedgewick增量序列
    // Dk={1,5,19,41,109...}
    int n = nums.size();
    // 间隔为D
    for(int D = n/2;D>0;D/=2)
    {
        for(int p = D;p<n;++p)
        {
            int temp = nums[p];
            int i = p;
            for(;i>=D&&nums[i-D]>temp;i-=D)
            {
                nums[i]=nums[i-D];
            }
            nums[i]=temp;
        }
    }
}

// -----------------------------------堆排序-----------------------------------
// 建立最大堆
void percDown(vector<int>&nums,int i,int N)
{
    int temp = nums[i];
    int parent = i;
    for(int child = parent;2*child+1<N;parent = child)
    {
        child = 2*parent+1;
        if(child+1<N&&nums[child]<nums[child+1])
        {
            child+=1;
        }
        if(nums[child]<=temp)
        {
            break;
        }
        nums[parent]=nums[child];
    }
    nums[parent]=temp;
}

void heap_sort(vector<int>&nums)
{
    int n = nums.size();
    // 建立最大堆
    for(int i = n/2;i>=0;--i)
    {
        percDown(nums,i,n);
    }
    for(int i = n-1;i>0;--i)
    {
        swap(nums[0],nums[i]);
        percDown(nums,0,i);
    }
}

// -----------------------------------归并排序-----------------------------------
// 递归
void merge(vector<int>&nums,vector<int>&tempA,int L,int R,int REnd)
{
    int LEnd = R - 1;
    int Elements = REnd - L + 1;
    int temp = L;
    while(L<=LEnd&&R<=REnd)
    {
        if(nums[L]<nums[R])
        {
            tempA[temp++]=nums[L++];
        }
        else
        {
            tempA[temp++]=nums[R++];
        }
    }
    while(L<=LEnd)
    {
        tempA[temp++]=nums[L++];
    }
    while(R<=REnd)
    {
        tempA[temp++]=nums[R++];
    }
    for(int i = 0;i<Elements;++i)
    {
        nums[REnd - i] = tempA[REnd - i];
    }
}

void Msort(vector<int>&nums,vector<int>&tempA,int L,int R)
{
    int Center;
    if(L<R)
    {
        Center = (L+R)>>1;
        Msort(nums,tempA,L,Center);
        Msort(nums,tempA,Center+1,R);
        merge(nums,tempA,L,Center+1,R);
    }
}

void merge_sort(vector<int>&nums)
{
    int n = nums.size();
    vector<int>tempA(n);
    Msort(nums,tempA,0,n-1);
}

// 迭代
void merge1(vector<int>&nums,vector<int>&tempA,int L,int R,int REnd)
{
    int LEnd = R - 1;
    int temp = L;
    while(L<=LEnd&&R<=REnd)
    {
        if(nums[L]<nums[R])
        {
            tempA[temp++]=nums[L++];
        }
        else
        {
            tempA[temp++]=nums[R++];
        }
    }
    while(L<=LEnd)
    {
        tempA[temp++]=nums[L++];
    }
    while(R<=REnd)
    {
        tempA[temp++]=nums[R++];
    }
}

void Merge_pass(vector<int>&nums,vector<int>&tempA,int N,int length)
{
    int i = 0;
    for(;i<N-2*length;i+=2*length)
    {
        merge1(nums,tempA,i,i+length,i+2*length-1);
    }
    if(i+length<N)
    {
        merge1(nums,tempA,i,i+length,N-1);
    }
    else
    {
        for(int j = i;j<N;++j)
        {
            tempA[j]=nums[j];
        }
    }
}

void merge_sort1(vector<int>&nums)
{
    int length = 1;
    int n = nums.size();
    vector<int>tempA(n);
    while(length<n)
    {
        Merge_pass(nums,tempA,n,length);
        length*=2;
        Merge_pass(tempA,nums,n,length);
        length*=2;
    }
}

// -----------------------------------main-----------------------------------
int main()
{
    int N = 0;
    scanf("%d",&N);
    vector<int>nums;

    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums.push_back(num);
    }

    //bubble_sort(nums);
    //insert_sort(nums);
    //shell_sort(nums);
    //heap_sort(nums);
    //merge_sort(nums);
    merge_sort1(nums);

    Print(nums);

    return 0;
}
