// BFS,我的解法
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using pNode = struct Node*;
struct Node{
    int pointTo;
    pNode next;
    Node(int t):pointTo(t),next(nullptr){}
    Node(int t,pNode nex):pointTo(t),next(nex){}
};

class Graph
{
public:
    int nv,ne;
    vector<pNode> graph;
    
    Graph(int n):nv(n+1),ne(0)
    {
        for(int i = 0;i<nv;++i)
        {
            graph.push_back(new Node(i));
        }
    }
    
    void InsertEdge(int v1,int v2);
    
    void solve();
    int BFS(int node);
};

void Graph::InsertEdge(int v1,int v2)
{
    pNode p = graph[v1];
    pNode temp = new Node(v2,p->next);
    p->next = temp;
    p = graph[v2];
    pNode temp1 = new Node(v1,p->next);
    p->next = temp1;
}

void Graph::solve()
{
    for(int i = 1;i<nv;++i)
    {
        int result = BFS(i);
        printf("%d: %.2f\%\n",i,100.0*result/(nv-1));
    }
}

int Graph::BFS(int node)
{
    int result = 0,level = 0;
    queue<int> q;
    vector<int>visited(nv,0);
    visited[0] = 1;
    q.push(node);
    while(!q.empty())
    {
        int n = q.size();
        for(int i = 0;i<n;++i)
        {
            node = q.front();
            result+=1;
            visited[node] = 1;
            q.pop();
            pNode p = graph[node];
            while(p)
            {
                if(!visited[p->pointTo])
                {
                    visited[p->pointTo] = 1;
                    q.push(p->pointTo);
                }
                p=p->next;
            }
        }
        level+=1;
        if(level>6)
        {
            break;
        }
    }
    
    return result;
}

Graph Read()
{
    int n;
    scanf("%d",&n);
    Graph g = Graph(n);
    scanf("%d",&(g.ne));
    
    for(int i = 0;i<g.ne;++i)
    {
        int e1,e2;
        scanf("%d %d",&e1,&e2);
        g.InsertEdge(e1,e2);
    }
    
    return g;
}

int main()
{
    Graph g = Read();
    
    g.solve();
    
    return 0;
}
