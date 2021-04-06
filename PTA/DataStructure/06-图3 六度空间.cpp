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

// 比较快的解法
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
vector<vector<int>> Adj; //邻接表 
vector<bool> inq; //节点是入队
int BFS(int v){
	inq[v] = true;
	queue<int> q;
	q.push(v);
	int count = 1,level = 0; //初始化距离不超过6的结点数和层数 
	int tail,last = v; //tail为每层最后一个节点的临时标志，tail为每层最后一个节点，初始化0层的最后一个节点为v 
	while(!q.empty()){
		int tmp = q.front();
		q.pop();
		for(int i = 0; i < Adj[tmp].size(); i++){//遍历所有邻接点 
			int w = Adj[tmp][i]; 
			if(!inq[w]){//未被访问
				q.push(w); //邻接点入队
				count++;
				inq[w] = true; //标记已访问 
				tail = w; //最后一个节点的临时标志 
			} 
		}
		if(tmp == last){ //当前访问完毕的节点为该层最后一个节点，则level+1，此时下一层的节点已全入队，更新last
			level++;
			last = tail;
		}
		if(level == 6) break;
	}
	return count;
}
int main()
{
	int n,m,x,y;
	cin>>n>>m;
	Adj.resize(n+1);
	inq.resize(n+1);
	for(int i = 0; i < m; i++){//建立边
		cin>>x>>y;
		Adj[x].push_back(y); 
		Adj[y].push_back(x); 
	}
	int count;
	for(int i = 1; i <= n; i++){
		inq.assign(n+1,false); //设置未被访问
		count = BFS(i);
		printf("%d: %.2f%\n",i,((double)count/n)*100); 
	}
	return 0;	
}  

