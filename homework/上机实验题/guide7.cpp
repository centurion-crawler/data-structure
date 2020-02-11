#include <bits/stdc++.h>//可达性统计
using namespace std;
const int maxn=30000+7;
int head[maxn],ver[maxn];
int Next[maxn];
int cnt,tot;
int deg[maxn],a[maxn];
int n,m;
bitset<maxn> c[maxn];
void add(int x,int y)
{
	ver[++tot]=y,Next[tot]=head[x];
	head[x]=tot;
	deg[y]++;
}
void toposort()
{
	queue<int>q;
	for (int i=1;i<=n;++i)
	   if (deg[i]==0) q.push(i);
	while(q.size())
	{
		int x=q.front();
		q.pop();
		a[++cnt]=x;
		for (int i=head[x];i;i=Next[i])
		{
			int y=ver[i];
			deg[y]--;
			if (deg[y]==0) q.push(y);
		}
	}
}
void solve()
{
	int x,y;
	for (int i=cnt;i>=1;i--)
	{
		x=a[i];
		c[x][x]=1;
		for (int j=head[x];j;j=Next[j]) {
			int y=ver[j];
			c[x]|=c[y];
		}
	}
}
int main() 
{
	int x,y;
	scanf("%d%d",&n,&m);
	while (m--){
		scanf("%d%d",&x,&y);
		add(x,y);
	}
	toposort();
	solve();
	for (int i=1;i<=n;i++)
	 printf("%d\n",c[i].count());
	return 0;
}