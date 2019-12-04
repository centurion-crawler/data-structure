#include<bits/stdc++.h>
#define maxn 1000
const int INF=0x3f3f3f3f;
using namespace std;
int n,m,q,ans=0,pth=INF,route=0;
int G[maxn][maxn];
bool vis[maxn][maxn];
int vrel[100];
bool rec[maxn][maxn];
string H[maxn];
void dfs(int x,int y)
{
    if (x==y) 
    {
        route=route+ans;
        if (pth>ans) 
        {
            pth=min(pth,ans);
            for (int i=1;i<=n;i++)
                for (int j=1;j<=n;j++)
                    rec[i][j]=vis[i][j];
        }
        return;
    }
    for (int i=1;i<=n;i++)
        if (G[x][i]!=INF&&!vis[x][i])
            {
                vis[x][i]=true;
                vis[i][x]=true;
                ans=ans+G[x][i];
                dfs(i,y);
                ans=ans-G[x][i];
                vis[x][i]=false;
                vis[i][x]=false;
            }
}
int Hash(string a)
{
    int key=0;
    for (int i=0;i<a.length();i++)
        key=key+a[i];
    key=key%100;
    while (H[key]!="") key=(key+1)%100;
    H[key]=a;
    return key;
}
int Index(string a)
{
    int k=0;
    for (int i=0;i<a.length();i++)
        k=k+a[i];
    k=k%100;
    while(H[k]!=a) k++;
    return k;
}
void printmap(int x)
{
    cout<<x;
    for (int i=1;i<=n;i++)
        if (rec[x][i]) 
        {
            cout<<"->";
            rec[x][i]=0;
            rec[i][x]=0;
            printmap(i);
            break;
        } 
}
void init()
{
    vrel[55]=4;
    vrel[34]=4;
    vrel[36]=3;
    vrel[49]=3;
    vrel[62]=8;
    vrel[63]=8;
    vrel[27]=5;
    vrel[41]=5;
    vrel[57]=15;
    vrel[70]=30;
    vrel[32]=16;
    vrel[33]=12;
    vrel[39]=23;
    vrel[64]=23;
    vrel[70]=16;
    for (int i=0;i<maxn;i++)
        for (int j=0;j<maxn;j++)
            {
                vis[i][j]=false;
                G[i][j]=INF;
            }
    cout<<"please input the vertex and edge number:";
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        int pre,aft;
        string v;
        cout<<"please add <v1,v2,relate>:";
        scanf("%d%d ",&pre,&aft);
        getline(cin,v);
        //cout<<Index(v);
        G[pre][aft]=vrel[Index(v)];
        G[aft][pre]=vrel[Index(v)];
    }
    cout<<"please input the query times:";
    cin>>q;
    for (int i=1;i<=q;i++)
    {
        int s,e;
        cout<<"start vertex and terminated vertex:";
        cin>>s>>e;
        ans=0;
        route=0;
        pth=INF;
        memset(vis,false,sizeof(vis));
        dfs(s,e);
        if (route)
        {    
            cout<<"friend distance:"<<route<<endl;
            cout<<"strongest path:"<<pth<<endl;
            printmap(s);
        }
        else cout<<"No relationship!"<<endl;
    }
}

int main()
{
    string a[15]={"mother","father","son","dauther","boyfriend","girlfriend","wife","husband","classmate","stranger","teacher","friend","boss","employee","student"};
    for (int i=0;i<15;i++)
        Hash(a[i]);
    init();
    return 0;
}