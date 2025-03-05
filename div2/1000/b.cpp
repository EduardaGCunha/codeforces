#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, l, r; cin >> n >> l >> r;
        vector<int> prev, cur, next;
        for(int i = 1; i <= n; i++){
            int x; cin >> x;
            if(i < l) prev.push_back(x);
            if(i >= l && i <= r) cur.push_back(x);
            if(i > r) next.push_back(x);
        }

        sort(prev.begin(), prev.end());
        sort(cur.rbegin(), cur.rend());
        sort(next.begin(), next.end());

        int sum = 0, sum2 = 0, i = 0, j = 0;
        for(int i = 0, j = 0; i < cur.size(); i++){
            if(j >= next.size() || cur[i] < next[j]){
                sum += cur[i];
            }
            else sum += next[j];
            j++;
        }

        for(int i = 0, j = 0; i < cur.size(); i++){
            if(j >= prev.size() || cur[i] < prev[j]){
                sum2 += cur[i];
            }
            else sum2 += prev[j];
            j++;
        }

        cout << min(sum, sum2) << endl;
        
    }
}