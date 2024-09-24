#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int arr[n+1];
        arr[0] = 0;
        for(int i = 1; i <= n; i++){
            int a; cin >> a;
            arr[i] = arr[i-1] + a;
        }

        string s; cin >> s;

        int l = 0, r = n-1;
        int sum = 0;
        while(l < r){
            while(s[l] != 'L' && l < r) l++;
            while(s[r] != 'R' && r > l) r--;
            if(l < r){
                sum += arr[r+1] - arr[l];
            }
            l++, r--;
        }
        cout << sum << endl;
    }
}