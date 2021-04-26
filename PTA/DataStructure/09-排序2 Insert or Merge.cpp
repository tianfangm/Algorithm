#include <iostream>
#include <vector>

using namespace std;

bool compare(const vector<int>&pre,const vector<int>&after)
{
    int n = pre.size();
    for(int i = 0;i<n;++i)
    {
        if(pre[i]!=after[i])
        {
            return false;
        }
    }
    return true;
}

void Print(const vector<int>&nums)
{
    int n = nums.size();
    for(int i = 0;i<n;++i)
    {
        printf("%d",nums[i]);
        if(i!=n-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

void merge(vector<int>&nums,vector<int>&tempA,int l,int r,int rEnd)
{
    int lEnd = r - 1;
    int temp = l;
    while(l<=lEnd&&r<=rEnd)
    {
        if(nums[l]<=nums[r])
        {
            tempA[temp++]=nums[l++];
        }
        else
        {
            tempA[temp++]=nums[r++];
        }
    }
    while(l<=lEnd)
    {
        tempA[temp++]=nums[l++];
    }
    while(r<=rEnd)
    {
        tempA[temp++]=nums[r++];
    }
}

void Merge_pass(vector<int>&pre,vector<int>&tempA,int n,int length)
{
    int i = 0;
    for(;i<n-2*length;i+=2*length)
    {
        merge(pre,tempA,i,i+length,i+2*length-1);
    }
    if(i+length<n)
    {
        merge(pre,tempA,i,i+length,n-1);
    }
    else
    {
        for(int j=i;j<n;++j)
        {
            tempA[j]=pre[j];
        }
    }
}

void merge_sort(vector<int>&pre,const vector<int>&after)
{
    int length = 1;
    int n = pre.size();
    vector<int>tempA(n);
    bool flag = false;
    while(length<n)
    {
        Merge_pass(pre,tempA,n,length);
        if(compare(tempA,after))
        {
            flag = true;
        }
        else
        {
            if(flag)
            {
                pre = tempA;
                break;
            }
        }
        length*=2;
        Merge_pass(tempA,pre,n,length);
        if(compare(pre,after))
        {
            flag = true;
        }
        else
        {
            if(flag)
            {
                break;
            }
        }
        length*=2;
    }
}

bool insert_sort(vector<int>&pre,const vector<int>&after)
{
    int n = pre.size();
    int flag = false;
    for(int i = 1;i<n;++i)
    {
        int j = 0;
        int num = pre[i];
        for(j = i;j>=1&&num<pre[j - 1];--j)
        {
            pre[j]=pre[j - 1];
        }
        pre[j] = num;
        if(compare(pre,after))
        {
            flag = true;
        }
        else
        {
            if(flag)
            {
                return true;
            }
        }
    }
    return false;
}

void solve(vector<int>&pre,vector<int>&after)
{
    vector<int>temp = pre;
    if(insert_sort(temp,after))
    {
        printf("Insertion Sort\n");
        Print(temp);
    }
    else
    {
        merge_sort(pre,after);
        printf("Merge Sort\n");
        Print(pre);
    }
}

int main()
{
    int N = 0;
    scanf("%d",&N);

    vector<int>pre;
    vector<int>after;

    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        pre.push_back(num);
    }

    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        after.push_back(num);
    }

    solve(pre,after);

    return 0;
}
