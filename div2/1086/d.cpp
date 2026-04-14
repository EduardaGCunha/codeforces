#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
after the directions have been assigned

structure of the tree and direction of the edges from the information given by the note
  1234
1 1000
2 0110
3 0010
4 1111

2 3
4 2
4 1

we have to check if they can reach themselves
if not its not possible
if we have
2 3
3 2
this is a cycle
not possible as well

we must check if we dont form a cycle with children as well
*/

struct DSU{
    vector<int> p;
    int n;
    void init(int x){
        n = x;
        p.resize(n);
        for(int i = 0; i < n; i++){
            p[i] = i;
        }
    }

    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }

    bool unite(int a, int b){
        a = find(a), b = find(b);
        if(a == b) return false;
        p[a] = b;
        return true;
    }

};

void solve(){
    int n; cin >> n;
    vector<vector<int>> grid(n, vector<int>(n));
    bool pos = true;
    DSU dsu;
    dsu.init(n);
    for(int i = 0; i < n; i++){
        string s; cin >> s;
        for(int j = 0; j < n; j++){
            grid[i][j] = (s[j] == '1' ? 1 : 0);
            if(j == i && grid[i][j] != 1) pos = false;
        }
    }

    if(!pos){
        cout << "No\n";
        return;
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(grid[i][j] && grid[j][i]) {
                cout << "No\n";
                return;
            }
        }
    }

    vector<pair<int, int>> ans;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(!grid[i][j]) continue;

            bool add = true;
            for(int k = 0; k < n; k++){
                if(k == i || k == j) continue;
                if(grid[i][k] && grid[k][j]){
                    add = false;
                    break;
                }
            }
            if(add){
                
                ans.push_back({i, j});
                if(!dsu.unite(i, j)){
                    cout << "No\n";
                    return;
                } 
            }
        }
    }

    if(ans.size() != n-1){
        cout << "No\n";
        return;
    }

    vector<vector<int>> grid2(n, vector<int>(n, 0));
    //conexao entre si
    for(int i = 0; i < n; i++) grid2[i][i] = 1;
    //conexao entre vertices criados
    for(auto [a, b] : ans) grid2[a][b] = 1;

    //conexao pai pra filho
    for(int k = 0; k < n; k++){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                grid2[i][j] |= (grid2[i][k] && grid2[k][j]);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(grid[i][j] != grid2[i][j]){
                cout << "No\n";
                return;
            }
        }
    }

    cout << "Yes\n";
    for(auto [a, b] : ans){
        cout << a + 1 << " " << b + 1 << endl;
    }
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}