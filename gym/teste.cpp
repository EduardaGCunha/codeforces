#include <bits/stdc++.h>
#define fastio cin.tie(0); ios_base::sync_with_stdio(0)
#define ll long long
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), r.rend()
using namespace std;

struct sat {
    int n, tot; 
    vector<vector<int>> g;
    vector<int> vis, comp, id, ans;
    stack<int> s;

    sat() {};
    sat(int n_) : n(n_), tot(n), g(2*n) {}

    int dfs(int i, int& t){
        int lo = id[i] = t++;
        s.push(i), vis[i] = 2;
        for(int j : g[i]){
            if(!vis[j]) lo = min(lo, dfs(j, t));
            else if(vis[j] == 2) lo = min(lo, id[j]);
        }

        if(lo == id[i]) while(1){
            int u = s.top(); s.pop();
            vis[u] = 1, comp[u] = i;
            if((u>>1) < n && ans[u>>1] == -1) ans[u>>1] = ~u&1;
            if(u == i) break; 
        }

        return lo;
    }

    void add_impl(int x, int y){
        x = x >= 0 ? 2*x : -2*x-1;
        y = y >= 0 ? 2*y : -2*y-1;

        g[x].push_back(y);
        g[y^1].push_back(x^1);
    }

    void add_and(int x, int y){
        add_true(x);
        add_true(y);
    }

    void add_nand(int x, int y){
        add_cl(~x, ~y);
    }

    void neg(int x, int y){
        add_and(~x, ~y);
    }

    void add_cl(int x, int y){
        add_impl(~x, y);
    }

    void add_xor(int x, int y){
        add_cl(x, y), add_cl(~x, ~y);
    }

    void add_xnor(int x, int y){
        add_cl(~x, y), add_cl(x, ~y);
    }

    void add_eq(int x, int y){
        add_xor(~x, y);
    }

    void add_true(int x){
        add_impl(~x, x);
    }

    void add_false(int x) {
        add_impl(x, ~x);
    }

    void at_most_one(vector<int> v){
        g.resize(2*(tot+v.size()));
        for(int i = 0; i < v.size(); i++){
            add_impl(tot+i, ~v[i]);
            if(i){
                add_impl(tot+i, tot+i-1);
                add_impl(v[i], tot+i-1);
            }
        }

        tot+= v.size();
    }

    pair<bool, vector<int>> solve(){
        ans = vector<int>(n, -1);
        int t = 0;
        vis = comp = id = vector<int>(2*tot, 0);
        for(int i = 0; i < 2*tot; i++) if(!vis[i]) dfs(i, t);
        for(int i = 0; i < tot; i++){
            if(comp[2*i] == comp[2*i+1]) return {false, {}};
        }
        return {true, ans};
    }


};

int main(){
    fastio;
    int n, m; cin >> n >> m;

    sat res(n);
    
    bool ans=true;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b;
        string s; cin >> s;
        cin >> c;
            if(s == "="){
                if(c == 0) res.neg(a, b);
                else if (c == 1) res.add_xor(a, b);
                else res.add_and(a, b);
            }else if(s == "!="){
                if(c == 0) res.add_cl(a, b);
                else if(c == 1) res.add_xnor(a, b);
                else res.add_nand(a, b);
            }else if(s == "<"){
                if(c == 0) ans = false;
                else if(c == 1) res.neg(a, b);
                else res.add_nand(a, b);
            }else if(s == ">"){
                if(c == 0) res.add_cl(a, b);
                else if(c == 1) res.add_and(a, b);
                else ans = false;
            }else if(s == "<="){
                if(c==0) res.neg(a, b);
                else if(c== 1) res.add_nand(a, b);
                else continue;
            }else{
                if(c==0) continue;
                else if(c==1) res.add_cl(a, b);
                else res.add_and(a, b);
            }
        
    }

    ans = (ans && res.solve().first);
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}