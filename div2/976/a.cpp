#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(int n, int k){
    if(k == 1) return n;

    int cnt = 0;
    while(n > 0){
        cnt += (n % k);
        n/=k; 
    }

    return cnt;
}

signed main(){
    int t; cin >> t;
    while(t--){
        int a, b; cin >> a >> b;
        cout << solve(a, b) << endl;
    }

}