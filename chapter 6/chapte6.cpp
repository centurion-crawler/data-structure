#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int L[maxn+1]={0},R[maxn+1]={0};//建立L,R数组储存节点左右儿子
bool flag=false;
void getfa(int x,int target)//从v开始往下递归搜素儿子节点
{
    if (x==target) {flag=true;return;}
        if (L[x]!=0) getfa(L[x],target);
        if (R[x]!=0) getfa(R[x],target);
}
int main()
{
    int n;
    int v,u;
    cin>>n;
    for (int i=1;i<=n;i++)
        cin>>L[i]>>R[i];
        //没有标记为0
    cin>>v>>u;
    getfa(v,u); 
    cout<<flag;
    return 0;
}