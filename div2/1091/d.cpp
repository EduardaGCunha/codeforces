#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
sempre comeca no (0, 0) mod n
efetivamente os movimentos sao (a+i, b) e dps (x, b+i)
se individualemnte eu consigo chegar em todas as posicoes, ent talvez tbm consiga junto
se eu faco k movimentos, ent no total eu fiz (a*k mod n, b*k mod m) ne?
nn sei tanto a segunda parte considerando q eu inice com a, seria tipo b*(k-1) sla
parece coisa de coprimo 
*/

void solve(){
    int n, m; cin >> n >> m;
    int arr[n+1], specials[m+1];
    vector<int> segments;
    segments.push_back(0);
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= m; i++){
        cin >> specials[i];
        segments.push_back(specials[i]);
    }
    segments.push_back(n+1);
    int goal = arr[specials[1]];

    // for(int i = 0; i < n; i++){
    //     cout << specials[i] << " ";
    // }
    // cout << endl;

    int ans = 0, mx = 0;
    for(int i = 0; i < (int)segments.size()-1; i++){
        int l = segments[i] + 1;
        int r = segments[i+1]-1;
        //intervalo (l+1, r-1)

        int cnt = 0;
        int j = l;
        while(j <= r){
            if(arr[j] != goal){
                cnt++;
                while(j <= r && arr[j] != goal) j++;
            }else j++;
        }
        //cout << l << " " << r << " " << cnt << endl;
        ans += cnt;
        mx = max(mx, cnt);
    }
    ans = max(ans, 2*mx);
    cout << ans << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}