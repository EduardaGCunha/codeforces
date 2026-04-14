#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
    int n, m; cin >> n >> m;
    int arr[n+1], specials[m+1];
    vector<int> segments;
    segments.push_back(0);

    // FIX 1: use 1-based indexing (matches problem)
    for(int i = 1; i <= n; i++) cin >> arr[i];

    for(int i = 1; i <= m; i++){
        cin >> specials[i];
        segments.push_back(specials[i]);
    }

    // FIX 2: add last boundary
    segments.push_back(n + 1);

    // FIX 3: correct goal index
    int goal = arr[specials[1]];

    int ans = 0, mx = 0;
    for(int i = 0; i < (int)segments.size()-1; i++){
        int l = segments[i] + 1;
        int r = segments[i+1]-1;

        int cnt = 0;
        int j = l;
        while(j <= r){
            if(arr[j] != goal){
                cnt++;
                while(j <= r && arr[j] != goal) j++;
            }else j++; // FIX 4: increment j, not i
        }

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