#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e5+1;
int prime[MAXN];

void crivo(){
    memset(prime, 1, sizeof(prime));
    for(int i = 2; i < MAXN; i++){
        if(prime[i]){
            for(int j = i*i; j < MAXN; j+=i){
                prime[j] = 0;
            }
        }  
    }
}

void solve(){
	int n; cin >> n;
    vector<int> p, ans(n+1, 0), visited(n+1, 0);
    for(int i = 2; i <= n; i++){
        if(prime[i]) p.push_back(i);
    }

    reverse(p.begin(), p.end());
    for(auto i : p){
        //cout << i << endl;
        int lst = i;
        for(int j = i; j <= n; j+=i){
            if(!visited[j]){
                visited[j] = 1;
                ans[j] = lst;
                lst = j;
            }
        }
        ans[i] = lst;
    }
    ans[1] = 1;
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
    crivo();
	while(t--){
		solve();
	}
}