#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

struct segtree{
    int size; 
    vector<int> arr;
    
    void init(int n){
        size = 1;
        while(size < n) size*=2;
        arr.assign(2*size, 0LL);
    }

    void set(int i, int v, int x, int lx, int rx){
        if(rx-lx == 1){
            arr[x] = v;
            return;
        }

        int m = (lx + rx)/2;
        if(i < m){
            set(i, v, 2*x+1, lx, m);
        }else{
            set(i, v, 2*x+2, m, rx);
        }
        arr[x] = arr[2*x+1] + arr[2*x+2];
    }

    void set(int i, int v){
        set(i, v, 0, 0, size);
    }

    int sum(int l, int r, int x, int lx, int rx){
        if(lx>= r || l >= rx) return 0;
        if(lx >= l && rx <= r) return arr[x];
        int m = (lx+rx)/2;
        return sum(l, r, 2*x+1, lx, m) + sum(l, r, 2*x+2, m, rx);
    }

    int sum(int l, int r){
        return sum(l, r, 0, 0, size);
    }
};

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    segtree st;
    st.init(n);
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.set(i, x);
    }

    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        if(a == 1){
            st.set(b, c);
        }else{
            cout << st.sum(b, c) << endl;
        }
    }
}