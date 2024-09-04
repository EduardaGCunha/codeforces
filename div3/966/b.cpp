#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int l = arr[0], r = arr[0];
    for(int i  = 1; i < n; i++){
        if(arr[i] + 1 == l) l = arr[i];
        else if(arr[i] - 1 == r) r = arr[i];
        else{
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}