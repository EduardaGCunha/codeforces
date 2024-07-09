#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

const int MAXN = 3*(1e5)+7;
vector<int> id(MAXN), sz(MAXN), r(MAXN), mini(MAXN), maxi(MAXN);
int n, m;

int find(int a){
    if(id[a] == a) return a;
    return id[a] = find(id[a]);
}

void unite(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(r[a] == r[b]) r[a]++;
    if(r[a] > r[b]){
        id[b] = a;
        sz[a] += sz[b];
        mini[a] = min(mini[a], mini[b]);
        maxi[a] = max(maxi[a], maxi[b]);
    }else{
        id[a] = b;
        sz[b] += sz[a];
        mini[b] = min(mini[a], mini[b]);
        maxi[b] = max(maxi[a], maxi[b]);
    }
}

int main(){
    fastio;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
        mini[i] = i;
        maxi[i] = i;
    }
    for(int i = 0; i < m; i++){
        string a;
        cin >> a;
        if(a == "union"){
            int b, c; cin >> b >> c;
            unite(b, c);
        }else{
            int a; cin >> a;
            int b = find(a);
            cout << mini[b] << " " << maxi[b] << " " << sz[b] << endl;
        }

    } 
}