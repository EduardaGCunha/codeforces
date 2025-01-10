#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 2*(1e5);
int arr[MAXN], tree[4*MAXN];

int query(int v, int l, int r, int a, int b){
    if(b < l || r < a) return 0;
    if(a <= l && r <= b) return tree[v];
    int m = (l+r)/2;
    return query(2*v, l, m, a, b) + query(2*v+1, m+1, r, a, b);
}

void update(int v, int l, int r, int i, int x){
    if(i < l || r < i) return;
    if(l == r){
        tree[v] = x;
        return;
    }
    int m = (l+r)/2;
    update(2*v, l, m, i, x);
    update(2*v+1, m+1, r, i, x);
    tree[v] = tree[2*v] + tree[2*v+1];
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int res[n];
    for(int i = 0; i < n; i++){
        res[i] = query(1, 1, n, arr[i]+1, n);
        update(1, 1, n, arr[i], 1);
    }
    for(int i = 0; i < n; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    
}
