#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<int> id(MAXN), sz(MAXN);

int find(int a){
    if(id[a] == a) return a;
    return id[a] = find(id[a]);
}

void unite(int a, int b){
    a = find(a), b = find(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a, b);
    sz[a] += sz[b];
    id[b] = a;
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++){
        string a; int b, c;
        cin >> a >> b >> c;
        if(a == "union"){
            unite(b, c);
        }else{
            find(b) != find(c) 
                ? cout << "NO" << endl : cout << "YES" << endl;
        }

    }
}