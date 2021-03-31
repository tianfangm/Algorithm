#include <iostream>
#include <vector>

using namespace std;

int Find(const vector<int>&vec,int X)
{
    while(vec[X]>0)
    {
        X = vec[X];
    }
    return X;
}

void Union(vector<int>&vec,int x,int y)
{
    int root1,root2;
    root1 = Find(vec,x);
    root2 = Find(vec,y);
    
    if(vec[root1]>vec[root2])
    {
        vec[root2] += vec[root1];
        vec[root1] = y;
    }
    else
    {
        vec[root1] += vec[root2];
        vec[root2] = x;
    }
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    vector<int> vec(n+1,-1);
    
    char c = 'a';
    
    while(1)
    {
        scanf("\n%c",&c);
        if(c=='S')
        {
            break;
        }
        int a,b;
        scanf("%d %d",&a,&b);
        if(c=='C')
        {
            int c1 = Find(vec,a),c2 = Find(vec,b);
            if(c1==c2)
            {
                printf("yes\n");
            }
            else
            {
                printf("no\n");
            }
        }
        else if(c=='I')
        {
            Union(vec,a,b);
        }
    }
    int sum = 0;
    for(int i =1;i<=n;++i)
    {
        if(vec[i]<0)
        {
            sum+=1;
        }
    }
    if(sum==1)
    {
        printf("The network is connected.\n");
    }
    else
    {
        printf("There are %d components.\n",sum);
    }
    return 0;
}
