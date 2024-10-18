#include <bits/stdc++.h>
using namespace std;


class DSU{
    private:
        vector<int> p;
        vector<int> r;
        int connected;
    public:
        DSU(int n) : p(n), r(n, 1), connected(n) {
            for(int i = 0; i < n; i++) p[i] = i;
        }

        int find(int x){
            return (p[x] == x ? x : find(p[x]));
        }

        bool unite(int x, int y){
            x = find(x);
            y = find(y);

            if(x == y) return false;

            connected--;
            if(r[x] == r[y]) r[x]++;
            if(r[x] > r[y]) p[y] = x; 
            else p[x] = y;
            return true;
        }

        bool conn(int x, int y){
            return find(x) == find(y);
        }

        int getconn() const {return connected;}
};

int main(){
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        DSU dsu(n);
        while(m--){
            int a, d, k; cin >> a >> d >> k;
            a--;
            for(int f = 0; f < k; f++){
                int cur = a + f * d;
                if(cur + d <= n) dsu.unite(cur, cur + d);
            }
        }
        cout << dsu.getconn() << endl;
    }
}