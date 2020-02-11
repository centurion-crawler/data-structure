#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
int a[maxn];
int n;
int cnt[8][2]={0};
void quicksort(int l,int r)
{
    int i=l,j=r,mid=a[(i+j)/2];
    do
    {
        while(a[i]<mid) {i++;cnt[1][0]++;}
        while(a[j]>mid) {j--;cnt[1][0]++;}
        if (i<=j)
        {
            swap(a[i],a[j]);
            i++;
            j--;
            cnt[1][1]+=3;
        }
    }while(i<=j);
    if (i<r) quicksort(i,r);
    if (l<j) quicksort(l,j);    
}
void maxheapify(int s,int e)
{
    int dad=s;
    int son=dad*2+1;
    while(son<=e)
    {
        cnt[2][0]++;
        if (son+1<=e && a[son]<a[son+1])
            {son++;cnt[2][1]++;}
        
        if (a[dad]>a[son])
            return;
        else
        {
            swap(a[dad],a[son]);
            dad=son;
            son=dad*2+1;
        } 
    }
}
void heapsort(int len)
{
    for (int i=len/2-1;i>=0;i--)
        maxheapify(i,len-1);
    for (int i=len-1;i>0;i--)
    {
        swap(a[0],a[i]);
        cnt[2][1]+=3;
        maxheapify(0,i-1);
    }
}
void Merge(int A[],int TA[],int S,int MID,int E)
{
    int i=S, j=MID+1, k=S;
    while(i!=MID+1 && j!=E+1)
    {
        cnt[3][0]++;
        if (A[i]>A[j])
            TA[k++]=A[j++];
        else
            TA[k++]=A[i++];
        cnt[3][1]++;
    }
    while(i!=MID+1)
    {
        cnt[3][1]++;
        TA[k++]=A[i++];
    }
    while(j!=E+1)
    {
        cnt[3][1]++;
        TA[k++]=A[j++];
    }
    for (i=S;i<=E;i++)
    {
        cnt[3][1]++;
        A[i]=TA[i];
    }
}
void Mergesort(int A[],int TA[],int s,int e)
{
    int mid;
    if (s<e)
    {
        mid=s+(e-s)/2;
        Mergesort(A,TA,s,mid);
        //cnt[3][1]+=2;
        Mergesort(A,TA,mid+1,e);
        //cnt[3][1]+=2;
        Merge(A,TA,s,mid,e);
    }
}
int getkey(int x,int m)
{
    return (x%(int)pow(10,m)/(int)pow(10,m-1));
}
void radixsort(int len,int key)
{
    queue<int>t[10];
    for (int i=0;i<10;i++)
        while(!t[i].empty())
            t[i].pop();
    for (int k=1;k<=key;k++)
    {
        for (int i=0;i<len;i++)
        {
            cnt[4][1]++;
            t[getkey(a[i],k)].push(a[i]);
        }
        int cnts=-1;
        for (int i=0;i<10;i++)
        {
            while(!t[i].empty())
                {
                    cnt[4][1]++;
                    a[++cnts]=t[i].front();
                    t[i].pop();
                    cnt[4][1]++;
                }
        }
    }   
}
void selectsort(int len)
{
    for (int i=0;i<len-1;i++)
    {
        cnt[5][1]++;
        for (int j=i+1;j<len;j++)
            {
                cnt[5][1]++;
                cnt[5][0]++;
                if (a[i]>a[j]) {cnt[5][1]+=3;swap(a[i],a[j]);}
            }
    }
}
void insert_sort(int *array,int l)
{
    int i,j;
    int temp;
    for(i=1;i<l;i++)
    {
        cnt[6][1]++;
        temp=*(array+i);
        cnt[6][1]+=2;
        for(j=i;j>0&&*(array+j-1)>temp;j--)
        {
            cnt[6][0]+=2;
            *(array+j)=*(array+j-1);
            cnt[6][1]+=2;
        }
        *(array+j)=temp;
        cnt[6][1]+=3;
    }
}
void shellInsert(int array[],int n,int dk)
{
    int i,j,temp;
    for(i=dk;i<n;i++)//分别向每组的有序区域插入
    {
        cnt[7][1]++;
        temp=array[i];
        for(j=i-dk;(j>=i%dk)&&array[j]>temp;j-=dk)//比较与记录后移同时进行
        {
            cnt[7][0]+=2;
            cnt[7][1]++;
            array[j+dk]=array[j];
            cnt[7][1]++;
        }
        cnt[7][0]++;
        if(j!=i-dk)
        {
            
            array[j+dk]=temp;//插入
            cnt[7][1]+=3;
        }
    }
}
 
//计算Hibbard增量
int dkHibbard(int t,int k)
{
    return (int)(pow(2,t-k+1)-1);
}
 
//希尔排序
void shellSort(int array[],int n,int t)
{
    void shellInsert(int array[],int n,int dk);
    int i;
    for(i=1;i<=t;i++)
    {
        shellInsert(array,n,dkHibbard(t,i));
        cnt[7][1]++;
        
    }
}
void print(string STR)
{
     cout<<STR<<" Result:"<<endl;
    for (int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
int main()
{
    int b[maxn];
    int c[maxn];
    int keynum;
    n=100;
    
    for (int i=0;i<n;i++)
    {
        b[i]=rand()%1000;
        cout<<b[i]<<" ";
        a[i]=b[i];
    }

    quicksort(0,n-1);
    print("quicksort");
    for (int i=0;i<n;i++)
        a[i]=b[i];

    heapsort(n);
    print("heapsort");
    for (int i=0;i<n;i++)
        a[i]=b[i];

    Mergesort(a,c,0,n-1);

    print("mergesort");
    for (int i=0;i<n;i++)
        a[i]=b[i];
    cout<<"please input radixsort keynum:"<<endl;
    cin>>keynum;
    radixsort(n,keynum);
    print("radixsort");
    for (int i=0;i<n;i++)
        a[i]=b[i];

    insert_sort(a,n);
    print("insertion sort");
    for (int i=0;i<n;i++)
        a[i]=b[i];
    selectsort(n);
    print("select sort");
    for (int i=0;i<n;i++)
        a[i]=b[i];
    shellSort(a,n,(int)(log(n+1)/log(2)));
    print("Shell");
    cout<<"\t\t\t\t compare times"<<"\t"<<"move times"<<endl;
    cout<<"quicksort:O(nlogn)-O(n^2):\t"<<cnt[1][0]<<"\t\t"<<cnt[1][1]<<endl;
    cout<<"heapsort:O(nlogn)-O(nlogn):\t"<<cnt[2][0]<<"\t\t"<<cnt[2][1]<<endl;
    cout<<"mergesort:O(nlogn)-O(nlogn):\t"<<cnt[3][0]<<"\t\t"<<cnt[3][1]<<endl;
    cout<<"radixsort:O(d(n+rd))-O(d(n+rd)):"<<cnt[4][0]<<"\t\t"<<cnt[4][1]<<endl;
    cout<<"insertion sort:O(n^2)-O(n^2):\t"<<cnt[6][0]<<"\t\t"<<cnt[6][1]<<endl;
    cout<<"select sort:O(n^2)-O(n^2):\t"<<cnt[5][0]<<"\t\t"<<cnt[5][1]<<endl;
    cout<<"shell sort:O(n^(1.5))-O(n^2):\t"<<cnt[7][0]<<"\t\t"<<cnt[7][1]<<endl;

    return 0;
}















