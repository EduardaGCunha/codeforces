#include <bits/stdc++.h>
using namespace std; 

#define int long long

const int MOD = 1e9+7;

int fastexpo(int a, int b){
    int res = 1;
    while(b > 0){
        if(b%2) res = (res*a)%MOD;
        a = (a*a)%MOD;
        b /= 2;
    }
    return res;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        int sum = 0;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
            sum += arr[i];
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            sum = (sum - arr[i] + MOD) % MOD;
            ans = (ans + arr[i]*sum) % MOD;
        }
        cout << ans << endl;
        int p = ((n*(n-1))/2)%MOD;
        cout << p << endl;
        ans = (ans * fastexpo(p, MOD-2)) % MOD;
        cout << ans << '\n';
    }
}