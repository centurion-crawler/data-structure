//递归法
#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
int n;
struct node
{
    int lson;
    int rson;
}tree[maxn];
void pre_order(int x)//先序遍历
{
    cout<<x<<" ";
    if (tree[x].lson==-1&&tree[x].rson==-1)  return;
    if (tree[x].lson!=-1) pre_order(tree[x].lson);
    if (tree[x].rson!=-1) pre_order(tree[x].rson);
}
void mid_order(int x)//中序遍历
{
    if (tree[x].lson==-1&&tree[x].rson==-1)  {cout<<x<<" ";return;}
    if (tree[x].lson!=-1) mid_order(tree[x].lson);
    cout<<x<<" ";
    if (tree[x].rson!=-1) mid_order(tree[x].rson);

}
void last_order(int x)//后序遍历
{
    if (tree[x].lson==-1&&tree[x].rson==-1)  {cout<<x<<" ";return;}
    if (tree[x].lson!=-1) last_order(tree[x].lson);
    if (tree[x].rson!=-1) last_order(tree[x].rson);
    cout<<x<<" ";
}
int main()
{
    int F,S,root;
    cin>>n;
    for (int i=1;i<maxn;i++)
    {
        tree[i].lson=-1;
        tree[i].rson=-1;  
    }
    for (int i=1;i<=n;i++)
    {
        int s_size;

        scanf("%d%d%d",&s_size,&F,&S);
        if (s_size==1) 
            tree[F].lson=S;
        else tree[F].rson=S;   
    }
    cin>>root;
    cout<<"pre-order:";
    pre_order(root);
    cout<<endl;
    cout<<"mid-order:";
    mid_order(root);
    cout<<endl;
    cout<<"last-order:";
    last_order(root);
}
//栈的非递归算法
/*
#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
int n;
struct node
{
    int num;
    int lson;
    int rson;
    bool vis;
    bool pri;
}tree[maxn];
stack<node> s;
void pre_order()//先序遍历
{
    while(!s.empty())
    {
        if (!tree[s.top().num].vis)
        {
            cout<<s.top().num<<" ";
            tree[s.top().num].vis=true;
        }
        if  (s.top().lson==-1&&s.top().rson==-1)  s.pop();
        if (s.top().lson!=-1&&!tree[s.top().lson].vis) {//tree[s.top().lson].vis=true;
                                                        s.push(tree[s.top().lson]);continue;}
        if (s.top().rson!=-1&&!tree[s.top().rson].vis) {//tree[s.top().rson].vis=true;
                                                        s.push(tree[s.top().rson]);continue;}
        s.pop();
    }
}
void mid_order()//中序遍历
{
    
    while(!s.empty())
    {
        if (s.top().lson==-1&&s.top().rson==-1)  {tree[s.top().num].vis=true;cout<<s.top().num;s.pop();}
        if (s.top().lson!=-1&&!tree[s.top().lson].vis) {s.push(tree[s.top().lson]);continue;}
        if (!tree[s.top().num].vis)
            {
             cout<<s.top().num<<" ";
             tree[s.top().num].vis=true;
            }
        if (s.top().rson!=-1&&!tree[s.top().rson].vis) {s.push(tree[s.top().rson]);continue;}
        s.pop();
    }
}
void last_order()//后序遍历
{
    
    while(!s.empty())
    {
        if (s.top().lson==-1&&s.top().rson==-1)  {tree[s.top().num].vis=true;cout<<s.top().num;s.pop();}
        if (s.top().lson!=-1&&!tree[s.top().lson].vis) {tree[s.top().lson].vis=true;s.push(tree[s.top().lson]);continue;}
        if (s.top().rson!=-1&&!tree[s.top().rson].vis) {tree[s.top().rson].vis=true;s.push(tree[s.top().rson]);continue;}
        cout<<s.top().num<<" ";
        s.pop();
    }
}

int main()
{
    int F,S,root;
    cin>>n;
    for (int i=1;i<maxn;i++)
    {
        tree[i].lson=-1;
        tree[i].rson=-1; 
        tree[i].vis=false;
    }
    for (int i=1;i<=n;i++)
    {
        int s_size;

        scanf("%d%d%d",&s_size,&F,&S);
        if (s_size==1) 
            tree[F].lson=S;
        else tree[F].rson=S;   
        tree[F].num=F;
        tree[S].num=S;
    }
    cin>>root;
    while(!s.empty()) s.pop();
    s.push(tree[root]);
    
    cout<<"pre-order:";
    pre_order();
    cout<<endl;

    for (int i=1;i<maxn;i++)
        tree[i].vis=false;
    tree[root].vis=true;
    s.push(tree[root]);
    
    cout<<"last-order:";
    last_order();
    cout<<endl;

    for (int i=1;i<maxn;i++)
    tree[i].vis=false;
    s.push(tree[root]);
    cout<<"mid-order:";
    mid_order();
}*/
/*
#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
#define inf 0x3f3f3f3f
struct node
{
    char name;
    node * lson;
    node * bro;
    bool vis;
};//孩子兄弟结构结点定义
struct parentnode
{
    int fa;
    char c;
    node * point;
};//双亲数组结构结点定义
parentnode A[maxn];
int n;
int cnt=1;
node* trans()//将双亲数组结构转变成孩子兄弟树形结构
{
    node * hp,*p1,*p2;
    hp=(node*)malloc(sizeof(node));
    hp->vis=false;
    hp->name=A[1].c;
    hp->bro=NULL;
    A[1].point=hp;//根节点单独判断
    for (int i=2;i<=n;i++)
        {
            if (A[i].fa!=A[i-1].fa) 
            {
                p1=(node*)malloc(sizeof(node));
                p1->vis=false;
                p1->bro=NULL;
                p1->lson=NULL;
                p1->name=A[i].c;
                A[i].point=p1;
                A[A[i].fa].point->lson=p1;
                //当前结点是新一层
            }
            else 
            {
                p2=(node *)malloc(sizeof(node));
                p2->vis=false;
                p2->bro=NULL;
                p2->lson=NULL;
                p2->name=A[i].c;
                A[i].point=p2;
                p1->bro=p2;
                p1=p2;//指针移动到兄弟结点
                //当前结点层数不变
            }
        }
    return hp;
}
void finddeep(node * p,int deep)//按照孩子-兄弟结构的指针进行遍历即可
{
    if (!p->vis) {cout<<p->name<<" ";p->vis=true;}
    if (p->bro==NULL&&p->lson==NULL) 
        {
            cnt=max(cnt,deep);
            
            return;
        }
    if (p->lson!=NULL) {finddeep(p->lson,deep+1);if (!p->vis) {cout<<p->name<<" ";p->vis=true;}}
    if (p->bro!=NULL) {finddeep(p->bro,deep);if (!p->vis) {cout<<p->name<<" ";p->vis=true;}}
    return;
}
bool cmp(parentnode a, parentnode b)
{
    if (a.fa<b.fa) return true;
    else return false;
}
int main()
{
    node * Heap;
    cin>>n;
    A[0].fa=-inf;
    for (int i=1;i<=n;i++)
    { 
        scanf("%d %c",&A[i].fa,&A[i].c);//输入每个结点的父亲信息和该点的标号
    }
    sort(A+1,A+n+1,cmp);
        Heap=trans();//返回根节点指针
        finddeep(Heap,1);
        cout<<endl<<cnt;
    return 0;
}*/
/*
#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
int n;
struct node
{
    int lson;
    int rson;
}tree[maxn];
queue<int> s;
void level_order()//后序遍历
{
    while(!s.empty())
    {
        cout<<(s.front())<<" ";
        if (tree[s.front()].lson!=-1) 
            {
               // cout<<"push:"<<tree[s.back()].lson<<endl;
                s.push(tree[s.front()].lson);
            }
        if (tree[s.front()].rson!=-1) 
            {
               // cout<<"push:"<<tree[s.back()].lson<<endl;
                s.push(tree[s.front()].rson);
            }
        s.pop();
    }
}

int main()
{
    int F,S,root;
    cin>>n;
    for (int i=1;i<maxn;i++)
    {
        tree[i].lson=-1;
        tree[i].rson=-1;  
    }
    for (int i=1;i<=n;i++)
    {
        int s_size;

        scanf("%d%d%d",&s_size,&F,&S);
        if (s_size==1) 
            tree[F].lson=S;
        else tree[F].rson=S;   
        //tree[F].num=F;
        //tree[S].num=S;
    }
    cout<<"root:";
    cin>>root;
    while(!s.empty()) s.pop();
    cout<<"level-order:";
    s.push(root);
    level_order();
    cout<<endl;
}*/