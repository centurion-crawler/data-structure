/*#include<bits/stdc++.h>
uing namespace std;
struct node
{
    int key;
    node * next;
};
int n;
node *Build()
{
    cout<<"Please input the number:";
    cin>>n;
    node *h=(node *)malloc(sizeof(node));
    node *p1=h;
    node *p2=NULL;
    cin>>h->key;
    for (int i=1;i<=n-1;i++)
    {
        p2= (node *)malloc(sizeof(node));
        p1->next=p2;
        cin>>p2->key;
        p1=p2;
    }
    p1->next=h;
    return h;
}
node * Match(node *hp,int km)
{
    node *p=hp;
    for (int i=1;i<=n;i++)
        if (hp->key==km) return hp;
        else hp=hp->next;
    return NULL;
}
node * search(node* H,node* t,int K)
{
    if (t->key==K) return t;
    if (t->key>K) return Match(H,K);
    else return Match(t,K);
}
void init()
{
    int q;
    node *head=Build();
    node *t=head;
    cout<<"please input the query number:";
    cin>>q;
    for (int i=1;i<=q;i++)
        {
            int Key;
            cin>>Key;
            node *t1=search(head,t,Key);
            if (t1!=NULL) 
            {
                t=t1;
                cout<<"Hash position is:"<<t<<endl;
            }
            else cout<<"Not found!"<<endl;
        }
}
int main()
{
    init();
    return 0;
}
*/
#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
struct node
{
    int num;
    node * lson;
    node * rson;
    node * fa;
    int left;
};
int n,m;
bool flag;
int number;
void insert(int x,node *hp)
{
    if (x<hp->num)
    {
        if (hp->lson!=NULL) 
        {
            insert(x,hp->lson);
            return;
        }
        else 
        {
            node*p1=(node *)malloc(sizeof(node));
            hp->lson=p1;
            hp->left=0;
            p1->lson=NULL;p1->rson=NULL;p1->fa=hp;
            p1->num=x;
            return;
        }
    }
    else
    {
        if (hp->rson!=NULL)
        {
            insert(x,hp->rson);
            return;
        }
        else 
        {
            node*p1=(node *)malloc(sizeof(node));
            hp->rson=p1;
            hp->left=0;
            p1->lson=NULL;p1->rson=NULL;p1->fa=hp;
            p1->num=x;
            return;
        }
    }
}
void search(node *hp,int Min,int Max)
{
    if (hp->lson!=NULL) 
        search(hp->lson,Min,Max);
    if (hp->num>=Min && hp->num<=Max) 
        cout<<hp->num<<" ";
    if (hp->rson!=NULL)
        search(hp->rson,Min,Max);
}
void setup(node *hp)
{
    if (hp->lson!=NULL)
        setup(hp->lson);
        number++;
        hp->left=number;
    if (hp->rson!=NULL)
        setup(hp->rson);
}
void del(node *hp,int inx)
{
    if (flag) return;
    if (inx<hp->num)
        del(hp->lson,inx);
    if (inx>hp->num)
        del(hp->rson,inx);
    if (inx==hp->num)
        {
           flag=true;
           if  (hp->lson==NULL)
           {
               hp->lson->fa=hp->fa;
               if (hp->fa->lson==hp)
                   hp->fa->lson=hp->rson;
               if (hp->fa->rson==hp)
                   hp->fa->rson=hp->rson;
           }
           if (hp->lson!=NULL)
           {
                node*p1=hp->lson;
                if (p1->rson==NULL)
                {
                    hp->lson->fa=hp->fa;
                    if (hp->fa->lson==hp)
                        hp->fa->lson=hp->lson;
                    if (hp->fa->rson==hp)
                        hp->fa->rson=hp->lson;
                        hp->lson->rson=hp->rson;
                        hp->rson->fa=hp->lson;
                }
                else
                {
                    while(p1->rson!=NULL)
                        p1=p1->rson;
                    p1->fa->rson=p1->lson;
                    p1->lson->fa=p1->fa;
                    p1->lson=hp->lson;
                    p1->rson=hp->rson;
                    p1->fa=hp->fa;
                    if (hp->fa->lson==hp)
                        hp->fa->lson=p1;
                    if (hp->fa->rson==hp)
                        hp->fa->rson=p1;
                    hp->rson->fa=p1;
                    hp->lson->fa=p1;
                }
                free(hp);
           }
        }
    return;
}
void init()
{
    cout<<"please input the number:";
    cin>>n;
    int a;
    node *root=(node *)malloc(sizeof(node));
    node *h=(node *)malloc(sizeof(node));
    h->lson=NULL;
    h->rson=NULL;
    h->fa=root;
    cin>>h->num;
    for (int i=1;i<n;i++)
    {
        cin>>a;
        insert(a,h);
    }
    cout<<"please input the query number:";
    cin>>m;
    for (int i=0;i<m;i++)
    {
        int A,B;
        cin>>A>>B;
        search(h,A,B);
    }
    /*
    cout<<"please input the delete number:";
    cin>>m;
    for (int i=0;i<m;i++)
    {
        int A;
        cin>>A;
        flag=false;
        del(h,A);
        if (flag) cout<<"deleted completed!"<<endl;
        else cout<<"Not Found!";
    }*/
}
int main()
{
    init();
}
