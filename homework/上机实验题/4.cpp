#include<bits/stdc++.h>
using namespace std;
struct tri
{
    int x;
    int y;
    int ord;
    int num;
}A[502],B[502];//A,B矩阵的系数矩阵
int nA,mA,nB,mB,numA,numB;
struct Matrix
{
    int m[25][25];
    int N;
    int M;
    tri data[502];
};
Matrix Multiply()
{
    Matrix r1;
    if (mA!=nB) 
    {cout<<"Multipy ERROR!"<<endl;return r1;}
    int arpos[25]={0};
    int brpos[25]={0};
    int rrpos[25]={0};
    for (int i=1;i<=numA;i++)
        {
            if (arpos[A[i].x]==0) arpos[A[i].x]=i;
        }
    for (int i=1;i<nA;i++)
        if (arpos[i]==0) arpos[i]=arpos[i+1];
    if (arpos[nA]==0) arpos[nA]=numA+1;
    for (int i=1;i<=numB;i++)
        {
            if (brpos[B[i].x]==0) brpos[B[i].x]=i;
        }
    for (int i=1;i<nB;i++)
        if (brpos[i]==0) brpos[i]=brpos[i+1];
    if (brpos[nB]==0) brpos[nB]=numB+1;
    r1.N=nA;
    r1.M=mB;
    int numr1=0;
    for (int row=1;row<=r1.N;row++)
    {
        int ctemp[25]={0};
        int tp;
        rrpos[row]=numr1+1;
        if (row<r1.N) tp=arpos[row+1];
        else tp=numA+1;
        for (int p=arpos[row];p<tp;p++)
        {
            int brow=A[p].y;
            int t;
            if (brow<nB) t=brpos[brow+1];
            else t=numB+1;
            for (int q=brpos[brow];q<t;++q)
            {
                int col=B[q].y;
                ctemp[col]+=(A[p].num*B[q].num);
            }
        }
        for (int col=1;col<=r1.M;++col)
            if (ctemp[col])
            {
                if (++numr1>r1.N*r1.M) cout<<"ERROR"<<endl;
                r1.data[numr1].x=row;r1.data[numr1].y=col;r1.data[numr1].num=ctemp[col];
            }
    }
    for (int i=1;i<=numr1;i++)
        r1.m[r1.data[i].x][r1.data[i].y]=r1.data[i].num;
    return r1;
}
Matrix Add()
{
    Matrix r1;
    if (nA!=nB||mA!=mB)  
        {cout<<"Add ERROR!"<<endl;return r1;}
    for (int i=1;i<=numA;i++)
    {
        r1.m[A[i].x][A[i].y]=A[i].num;
    }
    for (int i=1;i<=numB;i++)
    {
        r1.m[B[i].x][B[i].y]+=B[i].num;   
    }
    r1.N=nA;
    r1.M=mA;
    return r1;
}
Matrix Sub()
{
    Matrix r1;
    if (nA!=nB||mA!=mB) 
        {cout<<"Sub ERROR!"<<endl;return r1;}
    for (int i=1;i<=numA;i++)
    {
        r1.m[A[i].x][A[i].y]=A[i].num;
    }
    for (int i=1;i<=numB;i++)
    {
        r1.m[B[i].x][B[i].y]-=B[i].num;   
    }
    r1.N=nA;
    r1.M=mA;
    return r1;
}
void init()
{
    cout<<"Please input nA,mA,tA:"<<endl;
    cin>>nA>>mA>>numA;
    for (int i=1;i<=numA;i++)
    {
        cin>>A[i].x>>A[i].y>>A[i].num;
        //A[i].ord=(A[i].x-1)*mA+A[i].y;
    }
    cout<<"Please input nB,mB,tB:"<<endl;
    cin>>nB>>mB>>numB;
    for (int i=1;i<=numB;i++)
    {
        cin>>B[i].x>>B[i].y>>B[i].num;
        //B[i].ord=(B[i].x-1)*mB+B[i].y;
    }
}
int main()
{
    Matrix r;
    init();
    int op;
    cout<<"Please input the operation:"<<endl;
    cin>>op;
    if (op==1) r=Multiply();
    if (op==2) r=Add();
    if (op==3) r=Sub();
    for (int i=1;i<=r.N;i++)
     {  
        for (int j=1;j<=r.M;j++)
           cout<<r.m[i][j]<<" ";
     cout<<endl;
     }
     return 0;
}   
