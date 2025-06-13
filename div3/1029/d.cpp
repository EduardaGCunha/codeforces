#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

/*
eh escolher entre diminuir por n-i+1 ou i toda vez
meio q vira uma equacao
se eu fixar ai e an 

*/

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];
    int base = (n*n) - 1;
    /*
    op1 = a0 - n*op2;
    op2 = n*a1 - an/(n^2 - 1)
    */
    if(base <= 0){
        cout << "NO\n";
        return;
    }
    int fr = n*(arr[0]) - arr[n-1];
    if(fr < 0 || fr % base != 0){
        cout << "NO\n";
        return;
    }
    int op1 = fr/base; 
    int op2 = arr[0] - n*op1;
    if(op2 < 0){
        cout << "NO\n";
        return;
    }

    int pos = 1;
    for(int i = 0; i < n; i++){
        int val = op2*(i+1) + op1*(n-(i+1)+1);
        //cout << val << endl;
        if(val != arr[i]){
            pos = 0;
            break;
        }
    }
    if(pos) cout << "YES\n";
    else cout << "NO\n";
}

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        solve();
    }
}
 