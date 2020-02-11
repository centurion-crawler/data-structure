#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
const int k = 1000; 
int a[MAXN], c[MAXN], ranked[MAXN];
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i]; 
        ++c[a[i]];
    }
    for (int i = 1; i < k; ++i)
        c[i] += c[i-1];
    for (int i = n-1; i >= 0; --i)
        ranked[--c[a[i]]] = a[i];
    for (int i = 0; i < n; ++i)
        cout << ranked[i] << endl;
    return 0;
}