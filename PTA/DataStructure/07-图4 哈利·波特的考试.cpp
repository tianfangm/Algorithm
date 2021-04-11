// floyd
#include <iostream>
#include <vector>

using namespace std;

const int INT_MAX = 99999999;

pair<int,int> floyd(vector<vector<int>>&graph,int n)
{
    for(int k = 1;k<=n;++k)
    {
        for(int i = 1;i<=n;++i)
        {
            for(int j = 1;j<=n;++j)
            {
                if(graph[i][j]>graph[i][k]+graph[k][j])
                {
                    graph[i][j]=graph[i][k]+graph[k][j];
                }
            }
        }
    }
    int Min = INT_MAX;
    int number = -1;
    for(int i = 1;i<=n;++i)
    {
        int temp = 0;
        for(int j = 1;j<=n;++j)
        {
            if(i!=j&&graph[i][j]>temp)
            {
                temp = graph[i][j];
            }
            if(graph[i][j]==INT_MAX)
            {
                return{0,-1};
            }
        }
        if(temp<Min)
        {
            Min=temp;
            number=i;
        }
    }
    return{number,Min};
}

int main()
{
    int N,M;
    scanf("%d %d",&N,&M);
    
    vector<vector<int>> graph(N+1,vector<int>(N+1,INT_MAX));
    
    for(int i = 0;i<M;++i)
    {
        int x,y,w;
        scanf("%d %d %d",&x,&y,&w);
        graph[x][y]=w;
        graph[y][x]=w;
    }
    
    pair<int,int>result=floyd(graph,N);
    if(result.second!=-1)
    {
        printf("%d %d\n",result.first,result.second);
    }
    else
    {
        printf("0\n");
    }
    return 0;
}
