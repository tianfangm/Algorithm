#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

int N,K,endstop;
unordered_map<int,string>um1;
unordered_map<string,int>um2;
vector<int> weight,pre[204],tempPath,path;
vector<vector<int>>roads;
int minCost,count,maxHappiness;
double maxAvgHappiness;

const int inf = 0x7fffffff;

void dijkstra()
{
    vector<int>visit(N,0);
    vector<int>dist(N,inf);
    
    dist[0]=0;
    
    while(1)
    {
        int V = -1, minDist = inf;
        for(int i = 0;i<N;++i)
        {
            if(!visit[i]&&dist[i]<minDist)
            {
                minDist = dist[i];
                V = i;
            }
        }
        
        if(V==-1)
        {
            break;
        }
        
        visit[V]=1;
        
        for(int i = 0;i<N;++i)
        {
            if(!visit[i]&&roads[V][i]!=inf)
            {
                if(dist[i]>dist[V]+roads[V][i])
                {
                    dist[i]=dist[V]+roads[V][i];
                    pre[i].clear();
                    pre[i].push_back(V);
                }
                else if(dist[i]==dist[V]+roads[V][i])
                {
                    pre[i].push_back(V);
                }
            }
        }
    }
    minCost = dist[endstop];
}

void dfs(int v)
{
    tempPath.push_back(v);
    
    if(v==0)
    {
        int value = 0;
        for(int i = 0;i<tempPath.size();++i)
        {
            value+=weight[tempPath[i]];
        }
        double tempavg = 1.0*value/(tempPath.size()-1);
        if(value>maxHappiness)
        {
            maxHappiness = value;
            maxAvgHappiness = tempavg;
            path = tempPath;
        }
        else if(value==maxHappiness&&tempavg>maxAvgHappiness)
        {
            maxAvgHappiness = tempavg;
            path = tempPath;
        }
        count+=1;
        tempPath.pop_back();
        return;
    }
    
    for(int i = 0;i<pre[v].size();++i)
    {
        dfs(pre[v][i]);
    }
    
    tempPath.pop_back();
}

int main()
{
    string s;
    scanf("%d %d",&N,&K);
    cin>>s;
    um1[0]=s;
    um2[s]=0;
    weight.push_back(0);
    roads.push_back(vector<int>(N,inf));
        
    for(int i = 1;i<N;++i)
    {
        int h;
        cin>>s>>h;
        um1[i]=s;
        um2[s]=i;
        weight.push_back(h);
        roads.push_back(vector<int>(N,inf));
        if(s=="ROM")
        {
            endstop = i;
        }
    }
    
    for(int i = 0;i<K;++i)
    {
        string e;
        int c,x,y;
        cin>>s>>e>>c;
        x = um2[s],y = um2[e];
        roads[x][y]=c;
        roads[y][x]=c;
    }
    
    dijkstra();
    
    count=0,maxHappiness=0,maxAvgHappiness=0;
    
    dfs(endstop);
    
    printf("%d %d %d %d\n",count,minCost,maxHappiness,static_cast<int>(maxAvgHappiness));
    
    for(int i = path.size()-1;i>=1;--i)
    {
        cout<<um1[path[i]]<<"->";
    }
    cout<<"ROM"<<endl;
    
    return 0;
}
