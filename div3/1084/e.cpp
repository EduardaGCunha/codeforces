#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 1e6+7;
int sieve[MAXN], divi[MAXN];

void crivo(){
    for(int i = 2; i < MAXN; i++){
        if(sieve[i] == 0){
            for(int j = i; j < MAXN; j += i){
                sieve[j] = i;
                divi[j]++;
            }
        }
    }
    sieve[1] = 1;
}

void solve(){
    int n; cin >> n;
    int arr[n];
    int prev = -1;
    int pos = 0, ans = 0, a = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(prev > arr[i]){
            pos = 1;
        }
        prev = arr[i];
        if(divi[arr[i]] >= 2){
            a = 1;
        } 
        if(i > 0 && sieve[arr[i-1]] > sieve[arr[i]]){
            a = 1;
        }
    }

    //cout << pos << " "<< ans << endl;
    if(!pos){
        cout << "Bob\n";
        return;
    }
    if(a) cout << "Alice\n";
    else cout << "Bob\n";
}

signed main(){
    fastio;
    crivo();
    int t; cin >> t;

    // for(int i = 0; i < 10; i++){
    //     cout << sieve[i] << endl; 
    // }

    while(t--){
        solve();
    }
}