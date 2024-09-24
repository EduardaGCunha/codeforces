#include <bits/stdc++.h>
using namespace std;

const int MAXN = 8;
vector<int> H[MAXN], G[MAXN];


int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        H[a].push_back(b);
        H[b].push_back(a);
    }
    
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    for(int i = 0; i < n; i++){
        for(auto u : H[i]){
            
        }
    }
}