#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

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

int GetLeftLength(int n)
{
    int H = static_cast<int>(log2(n+1));
    int X = n+1-pow(2,H);
    return pow(2,H-1)-1+min(static_cast<int>(pow(2,H-1)),X);
}

void solve(int inLeft,int inRight,int out,const vector<int>&input,vector<int>&output)
{
    int n = inRight - inLeft + 1;
    
    if(n==0)
    {
        return;
    }
    
    int L = GetLeftLength(n);
    
    output[out] = input[inLeft+L]; 
    
    int leftChildren = 2*out+1;
    int rightChildren = leftChildren+1;
    
    solve(inLeft,L+inLeft-1,leftChildren,input,output);
    solve(L+inLeft+1,inRight,rightChildren,input,output);
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    
    vector<int>input;
    vector<int>output(n);
    
    for(int i= 0;i<n;++i)
    {
        int num = 0;
        scanf("%d",&num);
        input.push_back(num);
    }
    
    sort(input.begin(),input.end());
    
    solve(0,n-1,0,input,output);
    
    Print(output);
    
    return 0;
}
