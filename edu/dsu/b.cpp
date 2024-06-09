#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<int> id(MAXN), sz(MAXN);
int n, m;

void get(int x){
    int cnt = 0, mini = n, maxi = 0;
    for(int i = 1; i <= n; i++){
        if(id[i] == x){
            cnt++;
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
    }

    cout << mini << " " << maxi  << " " << cnt << endl;
}
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
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        id[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++){
        string a;
        cin >> a;
        if(a == "union"){
            int b, c; cin >> b >> c;
            unite(b, c);
        }else{
            int a; cin >> a;
            get(find(a));
        }

    }
}