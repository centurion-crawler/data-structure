#include <bits/stdc++.h>
#define pii pair<int, int>
#define LL long long
#define piii pair<pii, int>
#define ls(x) (x << 1)
#define rs(x) ((x << 1) | 1)
using namespace std;
const int maxn = 200010;
vector<piii> G[maxn];
piii edge[maxn];
int n;
map<int, int> mp;
void add(int x, int y, int z, int id) {
    G[x].push_back(make_pair(make_pair(y, z), id));
    G[y].push_back(make_pair(make_pair(x, z), id));
}
struct node {
    bool flag;
    LL mi, Set;
};
struct SegmentTree {
    int n;
    node tr[maxn * 4];
    void pushup(int o) {
        tr[o].mi = min(tr[ls(o)].mi, tr[rs(o)].mi);
    }
     
    void maintain(int o, LL val) {
        tr[o].Set = min(tr[o].Set, val);
        tr[o].mi = min(tr[o].mi, tr[o].Set);
        tr[o].flag = 1;
    }
     
    void pushdown(int o) {
        if(tr[o].flag) {
            maintain(ls(o), tr[o].Set);
            maintain(rs(o), tr[o].Set);
            tr[o].Set = 1e18;
            tr[o].flag = 0;
        }
    }
     
    void build(int o, int l, int r) {
        if(l == r) {
            tr[o].mi = 1e18;
            tr[o].flag = 0;
            tr[o].Set = 1e18;
            return;
        }
        int mid = (l + r) >> 1;
        build(ls(o), l, mid);
        build(rs(o), mid + 1, r);
        tr[o].mi = 1e18;
        tr[o].flag = 0;
        tr[o].Set = 1e18;
    }
     
    void update(int o, int l, int r, int ql, int qr, LL val) {
        if(ql > qr) return;
        if(l == 0) return;
        if(l >= ql && r <= qr) {
            maintain(o, val);
            return;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if(ql <= mid) update(ls(o), l, mid, ql, qr, val);
        if(qr > mid) update(rs(o), mid + 1, r, ql, qr, val);
        pushup(o);
    }
     
    LL query(int o, int l, int r, int pos) {
        if(l == r && l == pos) {
            return tr[o].mi;
        }
        pushdown(o);
        int mid = (l + r) >> 1;
        if(pos <= mid) return query(ls(o), l, mid, pos);
        else return query(rs(o), mid + 1, r, pos);
    }
};
SegmentTree st;
struct Dj {
    priority_queue<pair<long long, int> > q;
    pii pre[maxn];
    bool in_line[maxn], v[maxn], in_tree[maxn], is_line[maxn];
    LL dis[maxn];
    vector<int> G1[maxn];
    int f[maxn];
    vector<int> line;
    vector<LL> re;
     
    void add1(int x, int y) {
        G1[x].push_back(y);
        G1[y].push_back(x);
    }
     
    void dijkstra(int s) {
        memset(v, 0, sizeof(v));
        memset(dis, 0x3f, sizeof(dis));
        q.push(make_pair(0, s));
        dis[s] = 0;
        while(q.size()) {
            int x = q.top().second;
            q.pop();
            if(v[x]) continue;
            v[x] = 1;
            for (int i = 0; i < G[x].size(); i++) {
                int y = G[x][i].first.first;
                LL z = G[x][i].first.second;
                if(v[y]) continue;
                if(dis[y] > dis[x] + z) {
                    dis[y] = dis[x] + z;
                    pre[y] = make_pair(x, G[x][i].second);
                    q.push(make_pair(-dis[y], y));
                }
            }
        }
    }
     
    void dfs(int x, int flag, int fa) {
        f[x] = flag;
        for (int i = 0 ; i < G1[x].size(); i++) {
            int y = G1[x][i];
            if(y == fa || is_line[y]) continue;
            dfs(y, flag, x);
        }
    }
     
    void solve(int s) {
        for (int i = 1; i <= n; i++) {
            if(i == s) continue;
            add1(i, pre[i].first);
            in_tree[pre[i].second] = 1;
        }
        for (int i = n + 1 - s; i != s; i = pre[i].first) {
            line.push_back(i);
            in_line[pre[i].second] = 1;
            is_line[i] = 1;
        }
        line.push_back(s);
        is_line[s] = 1;
        for (int i = 0; i < line.size(); i++) {
            int y = line[i];
            dfs(y, y, -1);
        }  
    }
};
Dj dj1, dj2;
int main() {
    int x, y, z, m, T;
//  freopen("1163F.in", "r", stdin);
//  freopen("1163F.out", "w", stdout);
    cout<<"please input the points,edges,query numbers:";
    scanf("%d%d%d", &n, &m, &T);
    cout<<"input the order of the both points and edge value:";
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        edge[i] = make_pair(make_pair(x, y), z);
        add(x, y, z, i);
    }
    dj1.dijkstra(1), dj2.dijkstra(n);
    dj1.solve(1), dj2.solve(n);
    int cnt = 0;
    for (int i = dj1.line.size() - 1; i >= 0; i--) {
        mp[dj1.line[i]] = ++cnt;
    }
    st.build(1, 1, cnt - 1);
    for (int i = 1; i <= m; i++) {
        if(dj1.in_tree[i] && dj2.in_tree[i]) continue;
        else {
            int x = edge[i].first.first, y = edge[i].first.second;
            LL tmp = 1e18;
            int l, r;
            l = min(mp[dj1.f[x]], mp[dj2.f[y]]), r = max(mp[dj1.f[x]], mp[dj2.f[y]]);
            tmp = dj1.dis[x] + dj2.dis[y] + edge[i].second;
            if(l >= 1 && r <= cnt)
                st.update(1, 1, cnt - 1, l, r - 1, tmp);
            swap(x, y);
            l = min(mp[dj1.f[x]], mp[dj2.f[y]]), r = max(mp[dj1.f[x]], mp[dj2.f[y]]);
            tmp = dj1.dis[x] + dj2.dis[y] + edge[i].second;
            if(l >= 1 && r <= cnt)
                st.update(1, 1, cnt - 1, l, r - 1, tmp);
        }
    }
    int cnt_T = 0;
    while(T--) {
        cnt_T++;
        LL ans = 0;
        cout<<"change edge[x]'s value to y";
        scanf("%d%d", &x, &y);
        int l1 = edge[x].first.first, r1 = edge[x].first.second;
        if(!dj1.in_line[x]) {
            ans = dj1.dis[n];
            ans = min(ans, min(dj1.dis[l1] + dj2.dis[r1] + y, dj1.dis[r1] + dj2.dis[l1] + y));
            printf("%lld\n", ans);
        } else {
            LL ans = dj1.dis[l1] + dj2.dis[r1] + y;
            ans = min(ans, dj1.dis[r1] + dj2.dis[l1] + y);
            int now = min(mp[l1], mp[r1]);
            printf("%lld\n", min(ans, st.query(1, 1, cnt - 1, now)));
        }
    }
}