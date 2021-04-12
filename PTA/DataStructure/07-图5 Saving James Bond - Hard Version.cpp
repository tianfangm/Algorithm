#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <unordered_set>
#include <stack>

using namespace std;

struct crocodile{
    int x;
    int y;
    crocodile(int _x,int _y):x(_x),y(_y){}
};

double getDis(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2)+pow(y1-y2,2));
}

bool canJump(int x1,int y1,int x2,int y2,int D)
{
    return getDis(x1,y1,x2,y2)<=D;
}

bool getSaved(int x1,int y1,int D)
{
    return abs(x1)+D>=50||abs(y1)+D>=50;
}

int bfs(int index,vector<int>&layer,vector<int>&path,const vector<crocodile*>&crocodiles,const int& D,const int& N)
{
    // init
    for(int i = 0;i<N;++i)
    {
        layer[i]=0;
        path[i]= -1;
    }
    
    queue<int> q;
    unordered_set<int> visited;
    
    q.push(index);
    
    while(!q.empty())
    {
        index = q.front();
        q.pop();
        if(getSaved(crocodiles[index]->x,crocodiles[index]->y,D))
        {
            return index;
        }
        visited.insert(index);
        for(int i = 0;i<N;++i)
        {
            if(!visited.count(i)&&canJump(crocodiles[index]->x,crocodiles[index]->y,crocodiles[i]->x,crocodiles[i]->y,D))
            {
                q.push(i);
                visited.insert(i);
                path[i]=index;
                layer[i]=layer[index]+1;
            }
        }
    }
    
    return -1;
}

int main()
{
    // 鳄鱼数组
    int N,D;
    scanf("%d %d",&N,&D);
    vector<crocodile*>crocodiles;
    
    if(D+7.5>=50)
    {
        // 如果可以直接跳上岸
        printf("1\n");
    }
    else
    {
        // 读入鳄鱼位置
        for(int i = 0;i<N;++i)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            crocodiles.push_back(new crocodile(x,y));
        }

        // 处理
        // 找到第一跳位置
        vector<int>firstJump;
        for(int i = 0;i<N;++i)
        {
            if(getDis(0,0,crocodiles[i]->x,crocodiles[i]->y)<=7.5+D)
            {
                firstJump.push_back(i);
            }
        }

        // 对每个第一跳进行bfs
        vector<int>minCount;
        vector<int>layer(N,0);
        vector<int>path(N,-1);
        int minLayer = 99999999;
        for(int i = 0;i<firstJump.size();++i) {
            int flag = bfs(firstJump[i],layer,path,crocodiles, D, N);
            if (flag != -1)
            {
                if(layer[flag]<minLayer)
                {
                    minLayer = layer[flag];
                    minCount.clear();
                    minCount.push_back(firstJump[i]);
                }
                else if(layer[flag]==minLayer)
                {
                    minCount.push_back(firstJump[i]);
                }
            }
        }

        if(minCount.size()==0)
        {
            // 无法逃脱
            printf("0\n");
        }
        else {
            // 找到第一跳最小的一跳
            int minLength = 99999999;
            int minIndex = 0;
            for (int i = 0; i < minCount.size(); ++i) {
                int index = minCount[i];
                int _l = getDis(0, 0, crocodiles[index]->x, crocodiles[index]->y);
                if (minLength > _l) {
                    minLength = _l;
                    minIndex = index;
                }
            }

            // bfs
            minIndex = bfs(minIndex, layer, path, crocodiles, D, N);

            // 利用堆栈求路径
            stack<int> stk;
            while (minIndex != -1) {
                stk.push(minIndex);
                minIndex = path[minIndex];
            }

            // 打印结果
            printf("%d\n", stk.size() + 1);
            while (!stk.empty())
            {
                int index = stk.top();
                stk.pop();
                printf("%d %d\n",crocodiles[index]->x,crocodiles[index]->y);
            }
        }
        
    }
    return 0;
}
