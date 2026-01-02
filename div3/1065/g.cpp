#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'


void solve(){
    int n; cin >> n;
    int arr[n], brr[n], potencias[n];
    potencias[0] = 1;
    for(int i = 1; i < 20; i++){
        potencias[i] = potencias[i-1]*2;
    }
    for(int i = 0; i < n; i++) cin >> arr[i];
    for(int i = 0; i < n; i++) cin >> brr[i];

    int k = 1e7;
    int str[n];
    for(int i = 0; i < n; i++){
        int v = 1;
        int mx = 0;
        for(int j = 0; j < 20; j++){
            if(arr[i]*v <= brr[i]) mx = max(mx, j);
            else break;
            v*=2;
        }
        str[i] = mx;
        k = min(k, mx);
    }
    cout << k << endl;
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(k){
            int pot = 1;
            int best = 0;
            for(int j = 0; j < k; j++){
                //qual o minimo q eu tenho q adicionar pra chegar aq na proxima potencia de 2?

                int goal1 = potencias[j]*arr[i] - arr[i];
                //agr multiplica todo mundo por 2^k e pega a diferencia do novo valor - brr[i]
                int goal2 = brr[i] - goal1*potencias[k];
                best = min(best, goal1 + goal2);
                pot *= 2;
            }
            ans += best; 
        }else ans += (brr[i] - potencias[k]);
    }
    cout << ans << endl;
}

signed main(){
	fastio;
    int t;
    //t = 1;
    cin >> t;
	while(t--){
		solve();
	}
}