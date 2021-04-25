#include <iostream>
#include <vector>

using namespace std;

void Print(const vector<int>&nums)
{
    int N = nums.size();
    for(int i = 0;i<N;++i)
    {
        printf("%d",nums[i]);
        if(i!=N-1)
        {
            printf(" ");
        }
    }
    printf("\n");
}

int getPivot(vector<int>&nums,int l,int r)
{
    int center = (l+r)>>1;
    if(nums[l]>nums[center])
    {
        swap(nums[l],nums[center]);
    }
    if(nums[l]>nums[r])
    {
        swap(nums[l],nums[r]);
    }
    if(nums[center]>nums[r])
    {
        swap(nums[center],nums[r]);
    }
    swap(nums[r-1],nums[center]);
    return nums[r-1];
}

void Qsort(vector<int>&nums,int l,int r)
{
    const int weight = 0;
    if(r-l>weight)
    {
        int pivot = getPivot(nums,l,r);
        int left = l,right = r - 1;
        while(left<right)
        {
            while(nums[--right]>pivot);
            while(nums[++left]<pivot);
            if(left<right)
            {
                swap(nums[left],nums[right]);
            }
        }
        swap(nums[left],nums[r-1]);
        Qsort(nums,l,left-1);
        Qsort(nums,left+1,r);
    }
}

void quick_sort(vector<int>&nums)
{
    Qsort(nums,0,nums.size()-1);
}

int main()
{
    int N;
    scanf("%d",&N);
    vector<int>nums;
    for(int i = 0;i<N;++i)
    {
        int num = 0;
        scanf("%d",&num);
        nums.push_back(num);
    }

    quick_sort(nums);
    
    Print(nums);
    
    return 0;
}
