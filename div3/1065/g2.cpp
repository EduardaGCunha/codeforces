#include <bits/stdc++.h>

using namespace std;



#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

#define int long long

#define endl '\n'



const int MOD = 1e6+3;

const int MAXN = 1e6+7;

int fact[MAXN], inv[MAXN];



int fastexpo(int a, int b){

int res = 1;

while(b > 0){

if(b&1) res = (res*a)%MOD;

a = (a*a)%MOD;

b /= 2;

}

return res;

}



void solve(){

int n; cin >> n;

int arr[n], brr[n];

for(int i = 0; i < n; i++) cin >> arr[i];

for(int i = 0; i < n; i++) cin >> brr[i];



int k = 30;

for(int i = 0; i < n; i++){

k = min(k, __lg(brr[i]/arr[i]));

}



//cout << k << endl;

vector<int> cnt(20, 0);

int x = 0, den = 1, tot = 0, ans = 0;

for(int i = 0; i < n; i++){

int t = brr[i]/(1<<k) - arr[i];

int rem = (brr[i] - (arr[i] + t)*(1<<k));

den = (den*fact[t])%MOD;

tot += t;

x += t + __builtin_popcount(rem);

for(int j = 0; j < k; j++) cnt[j] += (rem & (1<<j));

}



ans = (fact[tot]*inv[den])%MOD;

for(int i = 0; i < k; i++){

ans = (ans * fact[cnt[i]])%MOD;

}



x += k;

cout << x << " " << ans << endl;



}



signed main(){

fastio;

int t; cin >> t;

fact[0] = 1;

inv[0] = 1;

for(int i = 1; i < MAXN; i++){

fact[i] = (fact[i-1]*i)%MOD;

inv[i] = fastexpo(fact[i], MOD-2);

}

while(t--){

solve();

}

}