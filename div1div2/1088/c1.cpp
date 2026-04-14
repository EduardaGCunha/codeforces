#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MOD = 676767677;

void solve(){
    int n, k; cin >> n >> k;
    int arr[n+1], brr[n+1];
    for(int i = 1; i <= n; i++) cin >> arr[i];
    for(int i = 1; i <= n; i++) cin >> brr[i];

    /*
    esses caras precisam ser iguais pq sao forcados
    */
    for(int i = 1; i <= n-k; i++){
        if(brr[i] == -1) continue;
        if(arr[i] != brr[i]){
            cout << "NO\n";
            return;
        }
    }

    for(int i = k+1; i <= n; i++){
        if(brr[i] == -1) continue;
        if(arr[i] != brr[i]){
            cout << "NO\n";
            return;
        }
    }
    int intervalo = n-k+1;
    //cout << intervalo << endl;
    if(intervalo <= k){
        multiset<int> va;
        for(int i = n-k+1; i <= k; i++) va.insert(arr[i]);
        map<int, int> freq;
        for(int i = n-k+1; i <= k; i++){
            if(brr[i] == -1) continue;
            freq[brr[i]]++;
            if(freq[brr[i]] > 1){
                cout << "NO\n";
                return;
            }
            if(va.find(brr[i]) == va.end()){
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";

}

signed main(){
	fastio;
	int t; cin >> t;
	while(t--){
		solve();
	}
}