#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN= 1e6+7;

void solve(){
    int n, m; cin >> n >> m;
    set<int> st;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        st.insert(x);
    }

    vector<int> brr(m);
    int mx = 0;
    for(int i = 0; i < m; i++){
        cin >> brr[i];
        mx = max(mx, brr[i]);
    }

    vector<int> sieve(mx+1, 0);
    for(auto u : st){
        for(int i = u; i <= mx; i+=u){
            sieve[i]++;
        }  
    }

    int k = st.size();
    int a = 0, b = 0, c = 0;
    for(int i = 0; i < m; i++){
        int x = brr[i];
        if(sieve[x] == k) a++;
        else if(sieve[x] == 0) b++;
        else c++;
    }
    // cout << sieve[10] << " " << sieve[7] << " " << sieve[3] << endl;
    // cout << a << " " << b << " " << c << endl;
    a += c/2;
    b += c/2;
    if(c&1) a++;

    //cout << a << " " << b << " " << c << endl;
    if(a > b) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}