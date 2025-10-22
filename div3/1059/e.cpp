#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
tem q ser algum numero q nao apareceu antes
o segundo numero so nao pode ser igual q o ultimo numero do arr
o terceiro numero pode ser qualquer um
*/

void solve(){
    int n, k; cin >> n >> k;
    int arr[n];
    map<int, int> freq;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        freq[arr[i]]++;
    }
    
    vector<int> ans(3, 0);
    ans[0] = arr[n-3], ans[1] = arr[n-2], ans[2] = arr[n-1];
    
    for(int i = 1; i <= n; i++){
        if(freq[i] == 0) ans[0] = i;
    }

    if(ans[1] == ans[2] && ans[0] != ans[1]){
        ans[1] = 1;
        while(ans[1] == ans[2] || ans[0] == ans[1]) ans[1]++;
    }

    for(int i = 0; i < k; i++){
        cout << ans[i%3] << " ";
    }
    cout << endl;
}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}