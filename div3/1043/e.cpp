#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

void solve(){
	int n, m, q; cin >> n >> m >> q;
    vector<int> arr(n+1, 0), brr(m+1, 0), pref1(n+1, 0), pref2(m+1, 0);
    arr[0] = 1e18;
    brr[0] = 1e18;
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= m; i++) cin >> brr[i];
    
    sort(arr.rbegin(), arr.rend());
    sort(brr.rbegin(), brr.rend());
    for(int i = 1; i <= n; i++){
        //cout << arr[i] << " ";
        pref1[i] = arr[i] + pref1[i-1];
    }
    //cout << endl;

    for(int i = 1; i <= m; i++){
        //cout << brr[i] << " ";
        pref2[i] = brr[i] + pref2[i-1];
    }
    //cout << endl;

    int cura = 1, curb = 1;
    vector<int> opt(n+m+2, 0);
    for(int i = 1; i <= n + m; i++){
        if(cura>n) curb++;
        else if(curb > m) cura++;
        else if(arr[cura] > brr[curb]) cura++;
        else curb++;
        opt[i] = cura-1;
    }


    while(q--){
        int x, y, z; cin >> x >> y >> z;
        int op1 = opt[z];
        int op2 = z - opt[z];
        if(op1 >= x) cout << pref1[x] + pref2[z-x] << endl;
        else if(op2 >= y) cout << pref1[z-y] + pref2[y] << endl;
        else cout << pref1[op1] + pref2[op2] << endl;
    }
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}