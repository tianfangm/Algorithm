#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int inf = 0x7fffffff;

int N,M;
vector<int>inDegree;
vector<int>outDegree;
vector<int>early_s;
vector<int>late_s;
vector<vector<int>>graph;
int minTime;
vector<int>latest;
vector<int>earliest;

bool solve_early()
{
    queue<int> q;
    vector<int>visit(N+1,0);

    int count = 0;

    for(auto it :early_s)
    {
        q.push(it);
        visit[it]=1;
        while(!q.empty())
        {
            int V = q.front();
            q.pop();
            count +=1 ;
            for(int i = 1;i<=N;++i)
            {
                if(!visit[i]&&graph[V][i]>=0)
                {
                    earliest[i]=max(earliest[i],earliest[V]+graph[V][i]);
                    if(--inDegree[i]==0)
                    {
                        visit[i]=1;
                        q.push(i);
                    }
                }
            }
        }
    }
    if(count!=N)
    {
        return false;
    }
    else
    {
        minTime = 0;
        for(int i = 1;i<=N;++i)
        {
            if(earliest[i]>minTime)
            {
                minTime=earliest[i];
            }
        }
        return true;
    }
}

void solve_late()
{
    queue<int>q;
    vector<int>visit(N+1,0);
    
    for(auto it : late_s)
    {
        q.push(it);
        visit[it]=1;
        latest[it]=minTime;
        while(!q.empty())
        {
            int V = q.front();
            q.pop();
            for(int i = 1;i<=N;++i)
            {
                if(!visit[i]&&graph[i][V]>=0)
                {
                    latest[i]=min(latest[i],latest[V]-graph[i][V]);
                    if(--outDegree[i]==0)
                    {
                        q.push(i);
                    }
                }
            }
        }
    }
    
}

int main()
{
    scanf("%d %d",&N,&M);

    // init
    inDegree.resize(N+1);
    outDegree.resize(N+1);
    earliest.resize(N+1);
    latest.resize(N+1);
    graph.push_back(vector<int>(N+1,-1));

    for(int i = 1;i<=N;++i)
    {
        graph.push_back(vector<int>(N+1,-1));
        inDegree[i]=0;
        outDegree[i]=0;
        earliest[i]=0;
        latest[i]=inf;
    }

    for(int i = 0;i<M;++i)
    {
        int s,e,w;
        scanf("%d %d %d",&s,&e,&w);
        graph[s][e]=w;
        inDegree[e]+=1;
        outDegree[s]+=1;
    }

    for(int i = 1;i<=N;++i)
    {
        if(inDegree[i]==0)
        {
            early_s.push_back(i);
        }
        if(outDegree[i]==0)
        {
            late_s.push_back(i);
        }
    }

    if(!solve_early())
    {
        printf("0\n");
    }
    else
    {
        printf("%d\n",minTime);

        solve_late();
        
        for(int i = 1;i<=N;++i)
        {
            for(int j = N;j>=1;--j)
            {
                if(graph[i][j]>=0&&earliest[i]==(latest[j]-graph[i][j]))
                {
                    printf("%d->%d\n",i,j);
                }
            }
        }
    }

    return 0;
}
