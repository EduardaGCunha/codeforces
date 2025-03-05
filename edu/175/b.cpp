#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

signed main() {
    fastio;
    int t; cin >> t;
    while (t--) {
        int n, x, k; cin >> n >> x >> k;
        string s;cin >> s;
        int ans = 0, cnt = 0, pos = 0;
        int sobrou = 0;
        for (int i = 0; i < n; i++) {
            //cout << "valor do x agora" << " " << x << endl;
            if (cnt >= k) break;
            if (s[i] == 'R') x++;
            else x--;
            cnt++;
            if (x == 0){ 
                ans++;
                if (cnt <= k) {
                pos = 1;
                //cout << pos << " " << sobrou << " " << ans << endl;
                sobrou = k - cnt;
                break;
                }
            }
        }
        
        if (!pos) {
            cout << ans << endl;
            continue;
        }
        
        int cycle = 0, m = -1;
        for (int i = 0; i < n; i++) {
            //cout << cycle << endl;
            if (s[i] == 'L') cycle--;
            else cycle++;
            if (cycle == 0) {
                m = i + 1;
                break;
            }
        }
        
        if (m != -1) {
            ans += (sobrou/m);
        }
        
        cout << ans << endl;
    }

}
