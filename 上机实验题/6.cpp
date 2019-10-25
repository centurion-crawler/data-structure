/*//递归法
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
}*/

/*栈的非递归算法
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
            cout<<s.top().num;
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
             cout<<s.top().num;
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
        cout<<s.top().num;
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