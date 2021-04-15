#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int inf = 0x7fffffff;

vector<vector<int>>v(10000);
unordered_map<int,int>line;
int N,start,endstop;
int minCnt,minTransfer;
vector<int>visited(10000);
vector<int>path;
vector<int>tempPath;

void Input()
{
    for(int i = 0;i<N;++i)
    {
        int M = 0,pre,cur;
        scanf("%d %d",&M,&pre);
        for(int j = 1;j<M;++j)
        {
            scanf("%d",&cur);
            v[cur].push_back(pre);
            v[pre].push_back(cur);
            line[pre*10000+cur]=line[cur*10000+pre]=i+1;
            pre=cur;
        }
    }
}

int getTransfer(const vector<int>&p)
{
    int n = p.size();
    int cnt = -1, preline = 0;
    for(int i = 1;i<n;++i)
    {
        if(line[p[i-1]*10000+p[i]]!=preline)
        {
            cnt+=1;
            preline = line[p[i-1]*10000+p[i]];
        }
    }
    return cnt;
}

void dfs(int node,int cnt)
{
    if(node==endstop&&(cnt<minCnt||((cnt==minCnt)&&getTransfer(tempPath)<minTransfer)))
    {
        minCnt = cnt;
        minTransfer = getTransfer(tempPath);
        path = tempPath;
    }
    if(node==endstop)
    {
        return;
    }
    for(int i = 0;i<v[node].size();++i)
    {
        if(!visited[v[node][i]])
        {
            tempPath.push_back(v[node][i]);
            visited[v[node][i]]=1;
            dfs(v[node][i],cnt+1);
            tempPath.pop_back();
            visited[v[node][i]]=0;
        }
    }
}

int main()
{
    scanf("%d",&N);

    Input();

    int K = 0;
    scanf("%d",&K);
    for(int i = 0;i<K;++i)
    {
        minCnt = inf,minTransfer=inf;
        tempPath.clear();
        scanf("%d %d",&start,&endstop);
        tempPath.push_back(start);
        visited[start]=1;
        dfs(start,0);
        visited[start]=0;
        printf("%d\n",minCnt);
        int preline = 0,pre = start;
        for(int j = 1;j<path.size();++j)
        {
            if(preline!=line[path[j-1]*10000+path[j]])
            {
                if(preline!=0)
                {
                    printf("Take Line#%d from %04d to %04d.\n",preline,pre,path[j-1]);
                }
                pre = path[j-1];
                preline = line[path[j-1]*10000+path[j]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",preline,pre,endstop);
    }

    return 0;
}
