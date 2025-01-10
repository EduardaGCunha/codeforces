#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(NULL); cin.tie(NULL)
#define endl "\n"

const int MAXN = 5*(1e4)+7;
int p[MAXN], r[MAXN], n, m, k;


void init(){
    for(int i = 1; i <= n; i++){
        p[i] = i;
        r[i] = 0;
    }
}

int get(int a) {
    return (a == p[a] ? a : p[a] = get(p[a]));
}


void unite(int a, int b){
    int x = get(a), y = get(b);
    if(x == y) return;
    if(r[x] == r[y]) r[x]++;
    if(r[x] > r[y]){
        p[y] = x;
        r[x]++;
    }else{
        p[x] = y;
        r[y]++;
    }
}


signed main(){
    fastio;
    cin >> n >> m >> k;
    init();
    
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
    } 

    vector<tuple<string, int, int>> v;
    for(int i = 0; i < k; i++){
        string a;
        int b, c; cin >> a >> b >> c;
        v.push_back({a, b, c});
    }


    vector<string> ans;
    for(int i = k-1; i>= 0; i--){
        auto [a, b, c] = v[i];
        if(a == "ask"){
            if((get(b) == get(c))) ans.push_back("YES");
            else ans.push_back("NO");
        }else{
            unite(b, c);
        }
    }
    
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << endl;
}