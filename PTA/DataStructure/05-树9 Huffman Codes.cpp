#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

using namespace std;

const int MinData = 0;
unordered_map<char,int> hashMap;

using HuffmanTree = struct TreeNode*;
struct TreeNode{
    int weight;
    HuffmanTree left,right;
    TreeNode():weight(MinData),left(nullptr),right(nullptr){}
    TreeNode(int w):weight(w),left(nullptr),right(nullptr){}
};

// 计算WPL长度
int WPL(HuffmanTree huff,int depth)
{
    if(huff->left==nullptr&&huff->right==nullptr)
    {
        return depth*huff->weight;
    }
    else
    {
        return WPL(huff->left,depth+1)+WPL(huff->right,depth+1);
    }
}

// 交换
void SwapNode(HuffmanTree &h1,HuffmanTree &h2)
{
    HuffmanTree h = h1;
    h1 = h2;
    h2 = h;
}

// 堆的删除
HuffmanTree Delete(vector<HuffmanTree>&heap)
{
    HuffmanTree H = heap[1];
    int n = heap.size();
    HuffmanTree Huff = heap[n-1];
    heap.pop_back();

    n -= 1;
    if(n>1)
    {
        int parent,child;
        for(parent = 1;2*parent<n;parent = child)
        {
            child = 2*parent;
            if(child!=n - 1&&(heap[child+1]->weight<heap[child]->weight))
            {
                child+=1;
            }
            if(Huff->weight<=heap[child]->weight)
            {
                break;
            }
            SwapNode(heap[child],heap[parent]);
        }

        heap[parent] = Huff;
    }

    return H;
}

// 堆的插入
void Insert(HuffmanTree huff,vector<HuffmanTree>&heap)
{
    heap.push_back(huff);
    int n = heap.size() - 1;
    while(heap[n/2]->weight>huff->weight)
    {
        heap[n] = heap[n/2];
        n/=2;
    }
    heap[n] = huff;
}

void InitMinHeap(int n,vector<HuffmanTree>&heap)
{
    for(int i =0;i<n;++i)
    {
        getchar();
        int num = 0;
        char ch;
        scanf("%c %d",&ch,&num);
        hashMap[ch] = num;
        Insert(new TreeNode(num),heap);
    }
}

HuffmanTree InitHuffmanTree(vector<HuffmanTree>&vec)
{
    HuffmanTree Huff;
    int n = vec.size() - 1;
    for(int i = 1;i<n;++i)
    {
        Huff = new TreeNode();
        Huff->left = Delete(vec);
        Huff->right = Delete(vec);
        Huff->weight = Huff->left->weight+Huff->right->weight;
        Insert(Huff,vec);
    }
    Huff = Delete(vec);
    return Huff;
}

bool check(int n,int codeLength)
{
    HuffmanTree Huff = new TreeNode();
    HuffmanTree pre;
    int counter = 1;
    bool flag = true;
    for(int i =0;i<n;++i)
    {
        getchar();
        char c;
        string code;
        scanf("%c",&c);
        pre = Huff;

        cin>>code;
        int size = code.size();
        for(int i =0;i<size;++i)
        {
            if(code[i]=='0')
            {
                if(!pre->left)
                {
                    pre->left = new TreeNode();
                    counter++;
                }
                if(pre->weight!=0)
                {
                    flag = false;
                }
                pre = pre->left;
            }
            else if(code[i]=='1')
            {
                if(!pre->right)
                {
                    pre->right = new TreeNode();
                    counter++;
                }
                if(pre->weight!=0)
                {
                    flag = false;
                }
                pre=pre->right;
            }
        }
        if(pre->left||pre->right)
        {
            flag = false;
        }
        pre->weight = hashMap[c];
    }
    if(counter!=2*n-1||!flag||WPL(Huff,0)!=codeLength)
    {
        return false;
    }
    return true;
}

int main()
{
    int n  = 0;

    scanf("%d",&n);

    vector<HuffmanTree>heap{new TreeNode()};

    InitMinHeap(n,heap);

    HuffmanTree H = InitHuffmanTree(heap);

    int codeLength = WPL(H,0);

    int m = 0;
    scanf("%d",&m);

    for(int i =0;i<m;++i)
    {
        if(check(n,codeLength))
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }

    return 0;
}

