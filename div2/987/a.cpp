#include <bits/stdc++.h>
using namespace std; 

void solve(){
    int n; cin >> n;
    int arr[n];
    map<int, int> m;
    int cnt = 0, differ = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        m[arr[i]]++;
        cnt = max(cnt, m[arr[i]]);
    }

   cout << n - cnt << endl;

}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}