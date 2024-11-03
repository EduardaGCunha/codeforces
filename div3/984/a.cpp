#include <bits/stdc++.h>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n];
        for(int i = 0; i < n; i++) cin >> arr[i];

        int cnt = 0;
        for(int i = 1; i <= n-1; i++){
            if(abs(arr[i] - arr[i-1]) == 7 || abs(arr[i] - arr[i-1]) == 5) continue;
            cnt = 1;
        }
        if(cnt) cout << "NO\n";
        else cout << "YES\n"; 
    }
} 