#include <iostream>
#include <vector>

using namespace std;

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

void init(vector<int>&nums,int n)
{
    for(int i = 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums.push_back(num);
    }
}

bool compare(const vector<int>&nums,const vector<int>&after)
{
    int n = nums.size();
    for(int i = 0;i<n;++i)
    {
        if(nums[i]!=after[i])
        {
            return false;
        }
    }
    return true;
}

bool insertion_sort(vector<int>&nums,const vector<int>&after)
{
    int n = nums.size();
    bool flag = false;
    for(int i = 1;i<n;++i)
    {
        int j = 0;
        int temp = nums[i];
        for(j = i;j>0&&temp<nums[j-1];--j)
        {
            nums[j]=nums[j-1];
        }
        nums[j]=temp;
        if(compare(nums,after))
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

// 最大堆
void moveDown(vector<int>&nums,int top,int n)
{
    int temp = nums[top];
    int parent = top,child = 2*parent+1;
    for(int child = parent;2*child+1<n;parent = child)
    {
        child = 2*parent+1;
        if(child+1<n&&nums[child+1]>nums[child])
        {
            child+=1;
        }
        if(nums[child]<=temp)
        {
            break;
        }
        nums[parent]=nums[child];
    }
    nums[parent] = temp;
}

void heap_sort(vector<int>&pre,const vector<int>&after)
{
    // 构建最大堆
    int n = pre.size();
    bool flag = false;
    for(int i = n/2;i>=0;--i)
    {
        moveDown(pre,i,n);
    }
    // 遍历
    for(int i = n-1;i>0;--i)
    {
        swap(pre[0],pre[i]);
        moveDown(pre,0,i);
        
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
    }
}

void solve(vector<int>&pre,const vector<int>&after)
{
    vector<int>temp = pre;
    if(insertion_sort(temp,after))
    {
        printf("Insertion Sort\n");
        Print(temp);
    }
    else
    {
        heap_sort(pre,after);
        printf("Heap Sort\n");
        Print(pre);
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    
    vector<int>pre;
    vector<int>after;
    
    init(pre,n);
    init(after,n);
    
    solve(pre,after);
    
    return 0;
}
