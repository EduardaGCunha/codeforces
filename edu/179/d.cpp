#include <bits/stdc++.h>
using namespace std;

void prt(int a, int b){
    cout << a << " " << b << " " << a << " " << b << " " << a << " "  << b << endl;
}

void solve(){
    int n, m; cin >> n >> m;
    int arr[m];
    for(int i = 0; i < m; i++) cin >> arr[i];
    sort(arr, arr+m);
    vector<pair<int, int>> div(n);
    int l = -1, r = m;
    for(int i = 0; i < n; i++){
        if(!(i&1)){
            l++, r--;
            div[i].first = arr[l];
            div[i].second = arr[r]; 
        }else{
            div[i].first = arr[r];
            div[i].second = arr[l]; 
        }
    }

    for(int i = 0; i < n; i++){
        prt(div[i].first, div[i].second);
    }
}
 
int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}