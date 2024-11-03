#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 2*(1e5)+1;
int mark[MAXN][11];

class DSU{
    private:
        vector<int> p;
        vector<int> r;
    public:
        DSU(int n) : p(n), r(n, 1) {
            for(int i = 0; i < n; i++) p[i] = i;
        }

        int find(int x){
            return (p[x] == x) ? x : p[x] = find(p[x]);
        }

        bool unite(int x, int y){
            x = find(x);
            y = find(y);

            if(x == y) return false;

            if(r[x] == r[y]) r[x]++;
            if(r[x] > r[y]) p[y] = x; 
            else p[x] = y;
            return true;
        }

        bool conn(int x, int y){
            return find(x) == find(y);
        }

};

signed main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        for(int i = 0; i <= n; i++){
            for(int j = 0; j <= 10; j++){
                mark[i][j] = 0;
            }
        }
        DSU dsu(n+1);

        for(int i = 0; i < m; i++){
            int a, b, c; cin >> a >> b >> c;
            mark[a][b] = max(mark[a][b], c);
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= 10; j++){
                int it = mark[i][j];
                int pos = i;
                while(it > 0 && pos + j <= n){
                    it--;
                    dsu.unite(pos, pos + j);
                    mark[pos][j] = 0;
                    pos += j;
                    it = max(it, mark[pos][j]);
                }
            }
        }

        int ans = 0;
        for(int i = 1; i <= n; i++){
            ans += (dsu.find(i) == i);
        }

        cout << ans << endl;
    }
}