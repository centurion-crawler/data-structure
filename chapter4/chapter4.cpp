#include<bits/stdc++.h>
using namespace std;
#define maxn 1000
string S;
int n;
void getnext(string b, int *nextval)
{
    int len = b.length();
    int j = 0 , k = -1 ;
    nextval[0] = -1 ;
    while(j < len)//查找多次且可重叠时len不能减一，因为该单词的末尾加一的next也需要被下一次查询用到。
    {
        if(k == -1 || b[k] == b[j])
        {
            k++;
            j++;
            // 下面nest数组的优化
            if(b[k] != b[j])
                nextval[j] = k ;
            else
                nextval[j] = nextval[k];
        }
        else
        {
            k = nextval[k];
        }
    }
}
void Replace(string &S,string b,string a)
{
    int flag[maxn]={0};
    
    getline(cin,S);
        int nextval[10009];
        getline(cin,b);
        getline(cin,a);
        getnext(b, nextval);

        int lena = a.length() , lenb = b.length();
        
        int i = 0 , j = 0;
        int ans = 0 ,d=lena-lenb;
        while(i < lena)
        {
            if(j == -1 || S[i] == b[j])
            {
                i++ ;
                j++ ;
            }
            else
            {
                j = nextval[j];
            }
            if(j == lenb)
            {
                flag[++ans]=i+1+d*(ans-1);
                j = nextval[j] ;
            }
        }
        printf("%d\n" , ans);
    for (int i=1;i<=ans;i++)
        S.replace(flag[i]-1,lenb,a);
}
int main()
{
    string A,B;
    cout<<"please input the S string:"<<endl;
    getline(cin,S);
    cout<<"please input the operate number:"<<endl;
    cin>>n;
    getchar();
    for (int i=1;i<=n;i++)
    {
        getline(cin,A);
        getline(cin,B);
        Replace(S,A,B);
    }
    return 0 ;
}