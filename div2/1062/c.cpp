#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
ordeno pelas menores conexoes
se ja estiverem conectados ent eu so do skip
uso dsu pra checar conexao
*/

const int MAXN = 2e5+7;
int p[MAXN], r[MAXN];

void init(){
    for(int i = 0; i < MAXN; i++){
        p[i] = i;
        r[i] = 0;
    }
}

int find(int x){
    return (p[x] == x ? x : find(p[x]));
}

bool unite(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return false;
    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]){
        p[b] = a;
        r[a] += r[b]; 
    }else{
        p[a] = b;
        r[b] += r[a];
    }

    return true;
}

void solve(){
    init();
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    priority_queue<tuple<int, int, int>> pq; 
    for(int i = 0; i < n; i++){
        int l = (i-1+n)%n, R = (i+1)%n;
        if(arr[i] >= arr[l]) pq.push({-arr[i], -i, -l});
        if(arr[i] >= arr[R]) pq.push({-arr[i], -i, -R});
    }

    int ans = 0;
    int tot = n-1;
    while(tot && !pq.empty()){
        auto [v, i, pos] = pq.top(); pq.pop();
        v = -v;
        i = -i;
        pos = -pos;
        if(unite(i, pos)){
            ans += v;
            tot--;
        }
    }
    cout << ans << endl;
}   

signed main(){
	fastio;
    int t; cin >> t;
	while(t--){
		solve();
	}
}