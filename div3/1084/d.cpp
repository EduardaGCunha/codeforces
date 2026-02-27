#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+7;
int sieve[MAXN], divi[MAXN];

void crivo(){
    for(int i = 2; i < MAXN; i++){
        if(sieve[i] == 0){
            for(int j = i; j < MAXN; j += i){
                sieve[j] = i;
                divi[j]++;
            }
        }
    }
    sieve[1] = 1;
}

void solve(){
    int n, x, y; cin >> n >> x >> y;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    vector<int> prim, seg;
    for(int i = 0; i < n; i++){
        if(i < y && i >= x) seg.push_back(arr[i]);
        else prim.push_back(arr[i]); 
    }

    // for(int i = 0; i < seg.size(); i++){
    //     cout << seg[i] << " ";
    // }
    // cout << endl;


    // for(int i = 0; i < prim.size(); i++){
    //     cout << prim[i] << " ";
    // }
    // cout << endl;

    int p = 0;
    for (int j = 1; j < seg.size(); j++) {
        if (seg[j] < seg[p]) p = j;
    }
    
    vector<int> c(seg.size());
    for (int j = 0; j < seg.size(); j++) {
        c[j] = seg[(p + j) % seg.size()]; 
    }
    seg = c;

    // for(int i = 0; i < seg.size(); i++){
    //     cout << seg[i] << " ";
    // }
    // cout << endl;
    
    int i = 0;
    while(i < prim.size() && prim[i] < seg[0]) i++;

    for(int j = 0; j < i; j++) cout << prim[j] << " ";
    for(auto u : seg) cout << u << " ";
    for(int j = i; j < prim.size(); j++) cout << prim[j] << " ";
    cout << endl;
}

signed main(){
	fastio;
    crivo();
	int t; cin >> t;
	while(t--){
		solve();
	}
}