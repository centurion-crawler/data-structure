#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node{int from,to,cost;}edge[maxn];
int par[maxn];
int find(int num)
{
    return par[num]==num?num:par[num]=find(par[num]);
}
int cmp(const void *a,const void *b)
{
    return(((node*)a)->cost-((node*)b)->cost);
}
int main()
{
    int n,m,i,j;
    while(scanf("%d%d",&n,&m)!=EOF&&n)
    {
        for(i=0;i<=m;i++)
            par[i]=i;
        for(i=0;i<n;i++)
            scanf("%d%d%d",&edge[i].from,&edge[i].to,&edge[i].cost);
        qsort(edge,n,sizeof(node),cmp);
        int cnt=0,res=0;
        for(i=0;i<n;i++)
        {
            int sa=find(edge[i].from),sb=find(edge[i].to);
            if(sa==sb)
                continue;
            res+=edge[i].cost;
            par[sa]=sb;
            cnt++;
            if(cnt==m-1)
                break;
        }
        if(cnt>=m-1)
            printf("%d\n",res);
        else
            printf("?\n");
    }
    return 0;
}
